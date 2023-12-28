#!/bin/ash

# Define variables
HOME="/home/tnuyten"
IMAGE_NAME="mariadb-image"
CONTAINER_NAME="mariadb-container"
DOCKERFILE_PATH="$HOME/shared/inception/srcs/requirements/mariadb/Dockerfile"
HOST_PORT="3306"
CONTAINER_PORT="3306"

#VOLUME_MAPPING="/host/path:/container/path"
#ENV_VARS="-e VAR_NAME=var_value"

# Stop and delete old container
docker stop "$CONTAINER_NAME" || true
docker rm "$CONTAINER_NAME" || true

set -e

# Build the Docker image
docker build -t "$IMAGE_NAME" -f "$DOCKERFILE_PATH" .

# Run the Docker container
#docker run -d --name "$CONTAINER_NAME" -p $PORT_MAPPING -v $VOLUME_MAPPING $ENV_VARS "$IMAGE_NAME"
docker run -d --name "$CONTAINER_NAME" -p "$HOST_PORT:$CONTAINER_PORT" "$IMAGE_NAME" --network inception

set +e

echo "Docker container '$CONTAINER_NAME' has been created and is running."

docker ps
