echo "init.sh: Waiting for mysql start..."

sleep 15 #TODO find a better way to wait.

echo "init.sh: Running queries..."

mysql -e "CREATE DATABASE neus;" #test DB

mysql -e "CREATE DATABASE IF NOT EXISTS wordpress; GRANT ALL ON wordpress.* TO '$WORDPRESS_DB_USER'@'%' IDENTIFIED BY '$WORDPRESS_DB_PASSWORD'; FLUSH PRIVILEGES;"
mysql -e "FLUSH PRIVILEGES;"

echo "init.sh: Finished running queries"

# GRANT ALL ON wordpress.* TO (SELECT value FROM sys.config WHERE name = 'MYSQL_USER')@'%' IDENTIFIED BY (SELECT value FROM sys.config WHERE name = 'MYSQL_PASSWORD');
