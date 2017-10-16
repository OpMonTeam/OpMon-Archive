#!/bin/bash
sudo dpkg-deb --build bin/
mv bin.deb OpMon_vers-bin.deb
sudo chmod 777 OpMon_vers-bin.deb
