# Contributor: Navet56 <evandib@gmail.com> 
# Maintainer: Navet56 <evandib@gmail.com> 

pkgname=opmon
pkgver=0.12.1
pkgrel=1 
license=('GPL') 
arch=('x86_64') 
pkgdesc="A open source RPG monster fighting game" 
url="http://opmon-game.ga" 
depends=('sfml' 'gcc' 'libstdc++5' 'smpeg') 
makedepends=('make') 
source=(https://github.com/jlppc/OpMon/archive/alpha-${pkgver}.tar.gz) 
md5sums=('59e570b4442c9a3eec3827f850185456') 

build() { 
cd $srcdir/$pkgname-$pkgver 

make || return 1 
 
mkdir -p $pkgdir/usr/bin/
mkdir -p $pkgdir/usr/share/OpMon/

cp exeLinux/OpMon $pkgdir/usr/bin/
chmod +x $pkgdir/usr/bin
cp debInstall/bin/usr/share/OpMon $pkgdir/usr/share/OpMon
cp debInstall/bin/usr/share/applications $pkgdir/usr/share/applications
}

package() 
{
  cd "$srcdir/$pkgname-$pkgver"
  make DESTIDIR="$pkgdir" install	
}
