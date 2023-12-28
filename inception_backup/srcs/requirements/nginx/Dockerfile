FROM alpine:3.17

VOLUME ["/var/www/html"]

RUN apk update && apk add nginx openssl

RUN mkdir -p /etc/nginx/ssl \
    && openssl req -new -newkey rsa:4096 -days 365 -nodes -x509 \
       -subj "/C=US/ST=State/L=City/O=Organization/CN=localhost" \
       -keyout /etc/nginx/ssl/nginx.key -out /etc/nginx/ssl/nginx.crt
RUN chmod 640 /etc/nginx/ssl/nginx.crt
RUN chmod 600 /etc/nginx/ssl/nginx.key

COPY nginx.conf /etc/nginx/nginx.conf

RUN mkdir -p /usr/share/nginx/html

COPY phpinfo.php /var/www/html/phpinfo.php
RUN chmod 777 /var/www/html/phpinfo.php

COPY index.html /var/www/html/index.html
RUN chmod 777 /var/www/html/index.html

EXPOSE 443

CMD ["nginx", "-g", "daemon off;"]

# CMD ["/bin/ash", "/usr/local/bin/setup.sh"]

# COPY "tools/waitscript.sh" "/usr/local/bin/waitscript.sh"
# CMD ["/bin/ash", "/usr/local/bin/waitscript.sh"]