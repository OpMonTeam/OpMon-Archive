echo Please enter your password :
sudo apt install libsdl2-2.0-0 gcc libstdc++6 libsmpeg0 libsfml-dev libsfml-graphics
rm -r ressources
cp -r ../exe/ressources ../exeLinux
sudo cp -r ../exeLinux /opt
sudo cp -r ../exeLinux $HOME/
cd $HOME
mv exeLinux .opmon
sudo cp ../exeLinux/OPMon.desktop /usr/share/applications
if [ $LANG = fr_FR.UTF-8 ]
then
	sudo cp ../exeLinux/OPMon.desktop $HOME/Bureau
else
	sudo cp ../exeLinux/OPMon.desktop $HOME/Desktop
fi
if [ $LANG = es_ES.UTF-8 ]
then
	sudo cp ../exeLinux/OPMon.desktop $HOME/Descargas
else
	sudo cp ../exeLinux/OPMon.desktop $HOME/Desktop
fi
echo Installation completed.
