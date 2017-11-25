#!/bin/sh

if [ ! -d build ]; then
	mkdir build
fi

builtin pushd build
cmake ../ -DEXECUTABLE_NAME=hellowitty
if command -v ninja > /dev/null; then
	ninja
else
	make
fi

./hellowitty --docroot . --http-address localhost --http-port 9090 --deploy-path=/
builtin popd
