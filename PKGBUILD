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
source=(https://github.com/jlppc/OpMon/raw/master/opmon-arch.tar.gz) 
md5sums=('040779d18328c973b8c664eff345ed84') 

build() { 
cd $srcdir/opmon-arch

make || return 1

}

package() 
{

mkdir "${pkgdir}/usr"
mkdir "${pkgdir}/usr/share"
mkdir "${pkgdir}/usr/share/OpMon"

install -d "${srcdir}/opmon-arch/arch_install/bin/usr/bin" "${pkgdir}/usr/"
install -d "${srcdir}/opmon-arch/arch_install/bin/usr/share/OpMon" "${pkgdir}/usr/share/"
install "${srcdir}/opmon-arch/arch_install/bin/usr/share/applications/OPMon.desktop" "${pkgdir}/usr/share/applications"

cd "${srcdir}/opmon-arch"
make DESTIDIR="${pkgdir}"

chmod 755 "${pkgdir}/usr/share/OpMon"
}
