FROM alpine:3.17

VOLUME ["/var/www/html"]


RUN apk --update --no-cache add \
	php81 \
	php81-fpm \
	php81-mysqli \
	php81-json \
	php81-curl \
	php81-dom \
	php81-exif \
	php81-fileinfo \
	php81-intl \
	php81-mbstring \
	php81-openssl \
	php81-xml \
	php81-zip \
	php81-apcu \
	php81-redis \
	php81-phar

RUN sed -i 's/;daemonize = yes/daemonize = no/' /etc/php81/php-fpm.conf
RUN sed -i 's/listen = 127.0.0.1:9000/listen = 0.0.0.0:9000/' /etc/php81/php-fpm.d/www.conf

RUN mkdir -p /var/www/html

COPY phpinfo.php /var/www/html/phpinfo.php

EXPOSE 9000 3306

COPY wp_setup.sh /usr/local/bin/wp_setup.sh
RUN chmod +x /usr/local/bin/wp_setup.sh

CMD ["ash", "-c", "/usr/local/bin/wp_setup.sh"]