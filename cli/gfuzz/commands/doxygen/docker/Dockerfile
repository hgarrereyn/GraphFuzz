
FROM ubuntu:20.04

RUN apt-get -y update && \
    apt-get -y upgrade && \
    apt-get -y install doxygen git python3

WORKDIR /src
COPY in ./in

ENTRYPOINT ["/src/in/run.py"]
