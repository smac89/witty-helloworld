#!/usr/bin/env bash

if [ ! -d build ]; then
	mkdir build
fi

builtin pushd build
cmake ../ -DEXECUTABLE_NAME=hellowitty
ninja
./hellowitty --docroot . --http-address localhost --http-port 9090 --deploy-path=/
builtin popd
