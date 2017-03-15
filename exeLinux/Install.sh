echo Please enter your password :
su
apt install libsdl2-2.0-0 libsdl2-mixer-2.0-0 libsdl2-ttf-2.0-0 libsdl2-image-2.0-0 libfreetype6 gcc zlib1g libvorbis0a libvorbisfile3 libwebp5 libflac8 libmodplug1 libogg0 libpng16-16 libstdc++6 libtiff5 libsmpeg0
rm -r ressources
cp -r ../exe/ressources ../exeLinux
sudo cp -r ../exeLinux /opt
sudocp ../exeLinux/OPMon.desktop $PWD
echo Installation completed.
