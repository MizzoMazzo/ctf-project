FROM debian:buster-slim

RUN apt-get update && apt-get install -y gcc \
    python3 \
    socat

WORKDIR /app

COPY . .
RUN ./compile
RUN chmod -R 773 .

USER nobody

CMD socat tcp-l:1337,reuseaddr,fork,nodelay exec:"./spawn",stderr
