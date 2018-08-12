#!/bin/bash
set -e # exit on error

#Change every Release in this file to Debug if you want to build the game in debug.
cmake . -DCMAKE_BUILD_TYPE=Release
make
cd bin/Release
rm -rf data
cd ../../
cp -r data bin/Release/
cd bin/Release
./opmon

