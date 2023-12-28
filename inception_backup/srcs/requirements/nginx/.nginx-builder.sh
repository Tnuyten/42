#!/bin/ash

# Define variables
WD="/home/tnuyten/shared/inception"
IMAGE_NAME="nginx-image"
CONTAINER_NAME="nginx-container"
NETWORK_NAME="inception"

DOCKERFILE_PATH="$WD/srcs/requirements/nginx/Dockerfile"

HOST_PORT="443"
CONTAINER_PORT="443"
HOST_PORT2="80"
CONTAINER_PORT2="80"
PORT_MAPPING1="$HOST_PORT:$CONTAINER_PORT"
PORT_MAPPING2="$HOST_PORT2:$CONTAINER_PORT2"

HOST_VOLUME_PATH="phpfiles-volume"
CONTAINER_VOLUME_PATH="/var/www/html"
VOLUME_MAPPING="$HOST_VOLUME_PATH:$CONTAINER_VOLUME_PATH"

#ENV_VARS="-e VAR_NAME=var_value"

# Stop and delete old container
docker stop "$CONTAINER_NAME" || true
docker rm "$CONTAINER_NAME" || true

set -e

docker volume create phpfiles-volume

# Build the Docker image
docker build --no-cache -t "$IMAGE_NAME" -f "$DOCKERFILE_PATH" .

# Run the Docker container
#docker run -d --name "$CONTAINER_NAME" -p "$PORT_MAPPING" -v "$VOLUME_MAPPING" $ENV_VARS "$IMAGE_NAME"
echo "docker run -d --name "$CONTAINER_NAME" --network-alias "$CONTAINER_NAME" -p "$PORT_MAPPING1" -p "$PORT_MAPPING2" -v "$VOLUME_MAPPING" --network "$NETWORK_NAME" "$IMAGE_NAME""
docker run -d --name "$CONTAINER_NAME" --network-alias "$CONTAINER_NAME" -p "$PORT_MAPPING1" -p "$PORT_MAPPING2" -v "$VOLUME_MAPPING" --network "$NETWORK_NAME" "$IMAGE_NAME"
# docker run -d --name "$CONTAINER_NAME" -p "$PORT_MAPPING1" -p "$PORT_MAPPING2" --network $NETWORK_NAME "$IMAGE_NAME"

set +e

# Provide some feedback
echo "Docker container '$CONTAINER_NAME' has been created and is running."
