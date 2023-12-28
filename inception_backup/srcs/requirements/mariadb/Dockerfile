FROM	alpine:3.17

# Persistent mysql db volume
VOLUME /var/lib/mysql

RUN apk --update --no-cache add sudo

# Install MariaDB
RUN	apk --update --no-cache add mariadb mariadb-client

# Install the setup script
COPY db-setup.sh /usr/local/bin/db-setup.sh
# RUN chown mysql:mysql /usr/local/bin/db-setup.sh
RUN chmod 777 /usr/local/bin/db-setup.sh

# Setup script part 2: electric boogaloo
COPY init.sh /usr/local/bin/init.sh
# RUN chown mysql:mysql /usr/local/bin/db-setup.sh
RUN chmod 777 /usr/local/bin/init.sh

# Create the mysql socket dir and give permissions
RUN mkdir /run/mysqld && \
	chmod 744 /run/mysqld && \
	chown mysql:mysql /run/mysqld

# Expose the mysql port
EXPOSE	3306

# Install mysql config
COPY my.cnf /etc/my.cnf

# Startup command
CMD ["ash", "-c", "/usr/local/bin/db-setup.sh"]
