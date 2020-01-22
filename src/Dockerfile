FROM debian:buster-slim

#install dependencies
RUN apt-get update && apt-get install -y gcc \
    python3 \
    socat

#prepare secure user environment
RUN adduser --disabled-password --gecos '' ctf

WORKDIR /home/ctf

#copy files
COPY --chown=ctf:ctf . .

USER ctf
RUN ./compile
RUN chmod 770 spawn

CMD socat tcp-l:1337,reuseaddr,fork,nodelay exec:"./spawn",stderr
