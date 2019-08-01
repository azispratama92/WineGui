#!/usr/bin/env bash
# By: Melroy van den Berg
# Description: Helper script for creating and uploading new Docker image to Docker Hub
docker build -t gtk3_cmake_ninja .
# You could also use docker images to look-up the correct image and use the <image_id>
# Example: docker tag <image_id> danger89/gtk3-docker-cmake-ninja:latest
docker tag gtk3_cmake_ninja danger89/gtk3-docker-cmake-ninja:latest
docker push danger89/gtk3-docker-cmake-ninja