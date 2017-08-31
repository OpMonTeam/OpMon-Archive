#!/bin/bash
sudo dpkg-deb --build source/
mv source.deb OpMon_vers-source.deb
sudo chmod 777 OpMon_vers-source.deb
