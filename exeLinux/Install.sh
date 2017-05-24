echo Please enter your password :
sudo apt install libsdl2-2.0-0 libsdl2-mixer-2.0-0 libsdl2-ttf-2.0-0 libsdl2-image-2.0-0 libfreetype6 gcc zlib1g libvorbis0a libvorbisfile3 libwebp5 libflac8 libmodplug1 libogg0 libpng16-16 libstdc++6 libtiff5 libsmpeg0 libsfml-dev libsfml-graphics
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
