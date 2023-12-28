# !/bin/ash

# echo "Starting script..."

# INIT_MARKER="/var/lib/mysql/.initialized"

# # Function to gracefully stop MySQL
# graceful_shutdown() {
# 	echo "Received SIGTERM. Shutting down MySQL gracefully..."
# 	mysqladmin -uroot -p"$MYSQL_ROOT_PASSWORD" shutdown
# 	wait $!
# }

# # Trap SIGTERM signal
# trap 'graceful_shutdown' SIGTERM

# if [ ! -f "$INIT_MARKER" ]; then
# 	echo "First-time container initialization..."

# 	echo "Running mysql_install_db"
# 	if mysql_install_db --user=mysql --ldata=/var/lib/mysql; then
# 		echo "Creating WordPress database and user..."
# 		if mysql -h localhost -P 3306 -uroot -p"$MYSQL_ROOT_PASSWORD" -e "CREATE DATABASE IF NOT EXISTS wordpress; GRANT ALL ON wordpress.* TO '$WORDPRESS_DB_USER'@'%' IDENTIFIED BY '$WORDPRESS_DB_PASSWORD'; FLUSH PRIVILEGES;";
# 		then
# 			echo "Initialization finished. Creating marker file..."
# 			touch "$INIT_MARKER"
# 		else
# 			echo "Error creating WordPress database and user. Initialization failed."
# 			rm -f "$INIT_MARKER"
# 			exit 1
# 		fi
# 	else
# 		echo "Error running mysql_install_db. Initialization failed."
# 		exit 1
# 	fi
# else
# 	echo "Initialization already done. Skipping..."
# fi

# echo "Running mysqld"
# exec mysqld --verbose



# # # Old version:

echo "Starting script..."
echo "Current user: $(whoami)"
echo "Current working directory: $(pwd)"
echo "Environment variables:"
env

INIT_MARKER="/var/lib/mysql/.initialized"

# Function to gracefully stop MySQL
graceful_shutdown() {
	echo "Received SIGTERM. Shutting down MySQL gracefully..."
	mysqladmin -uroot -p"$MYSQL_ROOT_PASSWORD" shutdown
	wait $!
}

# Trap SIGTERM signal
trap 'graceful_shutdown' SIGTERM

if [ ! -f "$INIT_MARKER" ]; then
	echo "First-time container initialization..."

	echo "Running mysql_install_db"
	mysql_install_db --user=mysql --ldata=/var/lib/mysql

	#Sleep to give install time to finish?
	sleep 5

	echo "Creating WordPress database and user..."
# # 	mysql -uroot -p"$MYSQL_ROOT_PASSWORD" <<-EOSQL
# # 		CREATE DATABASE IF NOT EXISTS wordpress;
# # 		GRANT ALL ON wordpress.* TO '$WORDPRESS_DB_USER'@'%' IDENTIFIED BY '$WORDPRESS_DB_PASSWORD';
# # 		FLUSH PRIVILEGES;
# # EOSQL
# 	mysql -uroot -p"$MYSQL_ROOT_PASSWORD" -e "CREATE DATABASE IF NOT EXISTS wordpress; GRANT ALL ON wordpress.* TO '$WORDPRESS_DB_USER'@'%' IDENTIFIED BY '$WORDPRESS_DB_PASSWORD'; FLUSH PRIVILEGES;"
	ash -c init.sh &

	echo "Initialization finished. Creating marker file..."
	touch "$INIT_MARKER"
else
	echo "Initialization already done. Skipping..."
fi

echo "Running mysqld"

#YOU FUCKING MORON
exec mysqld --verbose
