#!/bin/ash

set -e

PHP_DIR="./wordpress"
PHP_FILE="php-builder.sh"
NGINX_DIR="./nginx"
NGINX_FILE="nginx-builder.sh"

build_component() {
	local COMPONENT_DIR="$1"
	local COMPONENT_FILE="$2"

	cd "$COMPONENT_DIR"
	ash "$COMPONENT_FILE"
	cd -
}

# Build NGINX
build_component "$NGINX_DIR" "$NGINX_FILE"

# Build PHP
build_component "$PHP_DIR" "$PHP_FILE"

# Show Docker containers
docker ps
