FROM --platform=amd64 ubuntu:20.04
RUN apt update && apt install -y \
    make \
    g++
COPY . /app
WORKDIR /app/cpp_source
RUN make
