#!/usr/bin/env bash
# By: Melroy van den Berg
# Description: Release production build + create Debian package file (.deb)

if [ ! -d "build" ]; then
  echo "Creating build directory..."
  mkdir build
fi

if [ -z "$(ls build)" ]; then
  cd build
  cmake -GNinja -Ddoc=ON -DCMAKE_BUILD_TYPE=Release ..
else
  echo "INFO: Only run ninja..."
  cd build
fi
ninja &&
cpack -G DEB