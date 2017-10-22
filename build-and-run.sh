#!/bin/bash
cmake .
make
cp -r data bin/Release/data
cd bin/Release
./OpMon
