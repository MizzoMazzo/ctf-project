#!/bin/bash

#down all running compose-services
docker-compose down

#pull git again
git pull

#rebuild docker-compose services
docker-compose up --build -d
