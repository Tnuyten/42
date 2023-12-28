#!/bin/ash

echo "Starting script..."

WORDPRESS_DIR="/var/www/html"
INIT_MARKER="$WORDPRESS_DIR/.initialized"

# Function to install WordPress
install_wordpress() {
    echo "Installing WordPress..."

    if [ ! -f "$INIT_MARKER" ]; then
        # Download and extract WordPress
        wget -O /tmp/wordpress.tar.gz https://wordpress.org/latest.tar.gz
        tar -xzf /tmp/wordpress.tar.gz -C "$WORDPRESS_DIR" --strip-components=1
        rm /tmp/wordpress.tar.gz

		# Add wp-cli to finish the wp installation headless.
		wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
		chmod +x wp-cli.phar && \
		mv wp-cli.phar /usr/local/bin/wp

        # Set up configuration file
        cp "$WORDPRESS_DIR/wp-config-sample.php" "$WORDPRESS_DIR/wp-config.php"
        sed -i -e "s/database_name_here/$WORDPRESS_DB_NAME/" \
               -e "s/username_here/$WORDPRESS_DB_USER/" \
               -e "s/password_here/$WORDPRESS_DB_PASSWORD/" \
			   -e "s/localhost/mariadb/" \
			   -e "s/define( 'WP_DEBUG', false );/define( 'WP_DEBUG', true );/" \
               "$WORDPRESS_DIR/wp-config.php"

		cd /var/www/html

		sleep 25

		echo "Doing wp core install"

		wp core install --url='https://tnuyten.42.fr/' --title="tnuyten42" --admin_user=Thibauld --admin_password=1234 --admin_email="Thibauld.nuyten@gmail.com"

        # Create marker file
        touch "$INIT_MARKER"

        echo "WordPress installation finished."
    else
        echo "WordPress already installed. Skipping..."
    fi
}

# Function to gracefully stop php-fpm
graceful_shutdown() {
    echo "Received SIGTERM. Shutting down php-fpm gracefully..."
    kill -s QUIT 1
    wait $!
}

# Trap SIGTERM signal
trap 'graceful_shutdown' SIGTERM

# Install WordPress
install_wordpress

# Start php-fpm
echo "Running php-fpm"
exec php-fpm81 -F -R