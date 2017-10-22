#!/bin/bash
#Change every Release to Debug if you want to build the game in debug.
cmake . -DCMAKE_BUILD_TYPE=Release
make
cp -r data bin/Release/data
cd bin/Release
./OpMon
