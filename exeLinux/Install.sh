echo Entrez votre mot de passe pour installer les dépendences
sudo apt install libsdl2-2.0-0
sudo apt install libsdl2-mixer-2.0-0
sudo apt install libsdl2-ttf-2.0-0
sudo apt install libsdl2-image-2.0-0
sudo apt install libfreetype6
sudo apt install gcc
sudo apt install zlib1g
sudo apt install libvorbis0a
sudo apt install libvorbisfile3
sudo apt install libwebp5
sudo apt install libflac8
sudo apt install libjpedg9
sudo apt install libmodplug1
sudo apt install libogg0
sudo apt install libpng16-16
sudo apt install libstdc++6
sudo apt install libtiff5
sudo apt install libsmpeg0
rm ressources
cp -r ../exe/ressources ../exeLinux
cp ../exeLinux /opt
cp ../exeLinux/OPMon.desktop $PWD
echo Installation terminée.
