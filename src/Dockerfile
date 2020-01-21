FROM debian:buster-slim

WORKDIR /app

COPY . .

RUN apt-get update && apt-get install -y gcc \
    python3 \
    socat

RUN ./compile

CMD socat tcp-l:1337,reuseaddr,fork exec:"./spawn"
