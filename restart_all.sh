#!/bin/bash

#pull git again
git pull

#rebuild docker-compose services
docker-compose up --build -d
