#!/bin/bash
cd /home/ubuntu/ctf-project

#down all running compose-services
docker-compose down

#pull git again
git pull

#rebuild docker-compose services
docker-compose up --build -d

#checkout this file as it is modified somehow
git checkout restart_all.sh
