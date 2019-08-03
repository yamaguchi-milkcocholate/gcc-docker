#!/usr/bin/env bash

name="gcc-docker"

# build
docker build -t ${name}:latest .
# up
docker run -d -it --rm -v $(PWD)/..:/var/project/${name} --name ${name} ${name}:latest /bin/bash
