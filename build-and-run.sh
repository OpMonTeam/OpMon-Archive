#!/bin/bash
set -e # exit on error

#Change every Release in this file to Debug if you want to build the game in debug.
md bin/Release && cd bin/Release
rm -r GameData
cp -r ../../OpMon-Data/GameData .
cd ../..
cmake . -DCMAKE_BUILD_TYPE=Release
make
cd bin/Release
./opmon
