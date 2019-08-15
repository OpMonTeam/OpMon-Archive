#
# spec file for package opmon
# created by jubalh for openSUSE
#

Name:           opmon
Version:        0.16
Release:        0
Summary:        Free and open source Pokémon clone
License:        GPL-3.0-or-later
Group:          Amusements/Games/RPG
URL:            https://opmon-game.ga/
Source:         https://github.com/OpMonTeam/OpMon/archive/alpha-v%{version}.tar.gz
BuildRequires:  gcc-c++
BuildRequires:  cmake >= 3.3.0
BuildRequires:  sfml2-devel >= 2.4.2
BuildRequires:  fdupes

%description
OPMon is a Pokémon-inspired game project imagined in 2012 and started in september 2016. This game is totally open source, allowing the fans to come realize their dreams! You can add OpMons, attacks, items, and many other things!

%prep
%setup -q -n OpMon-alpha-v%{version}

%build
%cmake
make %{?_smp_mflags}

%install
%cmake_install
%fdupes -s %{buildroot}

%files
%defattr(-,root,root)
%attr(0444,root,root) %doc README.md
%attr(0444,root,root) %license LICENSE.md
/usr/bin/opmon
/usr/share/OpMon/
/usr/share/applications/OPMon.desktop
/usr/share/OpMon/OPMon.desktop

%changelog
