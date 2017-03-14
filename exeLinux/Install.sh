echo Entrez votre mot de passe pour installer les dépendences :
sudo apt install libsdl2-2.0-0 libsdl2-mixer-2.0-0 libsdl2-ttf-2.0-0 libsdl2-image-2.0-0 libfreetype6 gcc zlib1g libvorbis0a libvorbisfile3 libwebp5 libflac8 libjpedg9 libmodplug1 libogg0 libpng16-16 libstdc++6 libtiff5 libsmpeg0
rm ressources
cp -r ../exe/ressources ../exeLinux
cp -r ../exeLinux /opt
cp ../exeLinux/OPMon.desktop $PWD
echo Installation terminée.
