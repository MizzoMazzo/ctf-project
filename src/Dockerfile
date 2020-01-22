FROM debian:buster-slim

#install dependencies
RUN apt-get update && apt-get install -y gcc \
    python3 \
    socat

#prepare secure user environment
#RUN adduser --disabled-password --gecos '' ctf

WORKDIR /app

#copy files
#COPY --chown=ctf:ctf . .
COPY . .

#RUN chown -R ctf:ctf .
#RUN chmod 4755 generator.py
#RUN chmod 4755 converter.py

#USER ctf
RUN ./compile
#RUN chmod 4755 spawn


#USER nobody

CMD socat tcp-l:1337,reuseaddr,fork,nodelay exec:"./spawn",stderr
