COMPOSE:=srcs/docker-compose.yml
VOLUMELOC:=/home/tnuyten/data

all: up

up:
	docker-compose -f $(COMPOSE) up -d

down:
	docker-compose -f $(COMPOSE) down

vdown:
	docker-compose -f $(COMPOSE) down -v
	sudo rm -rf $(VOLUMELOC)

restart:
	docker-compose -f $(COMPOSE) restart

build:
	docker-compose -f $(COMPOSE) build

rebuild:
	docker-compose -f $(COMPOSE) build --no-cache

.PHONY: all up down vdown restart build rebuild