#!/bin/bash

#Apply the submodules (OpMon-Data)
git submodule update --init --recursive

#Change every Release in this file to Debug if you want to build the game in debug.
mkdir bin
mkdir bin/Release
cd bin/Release
rm -r GameData
cp -r ../../OpMon-Data/GameData .
cd ../..
cmake . -DCMAKE_BUILD_TYPE=Release
make
cd bin/Release
./opmon
