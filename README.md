# FC-Standard
Framework Command Standard is an implementation of the FC Programming Language designed to provide a standard programming interface with graphics options across all platforms.

Wiki: https://lumpology.com/docs/fc-standard-documentation/


Version System: (Will come into effect after 1.0.0.R)

Example: 2.1.3.R

Format: X1.X2.X3._

X1 = Major FC Standard Version Change (Will be incompatible with previous X1 version)

X2 = FC Standard Feature Update (Will be mostly compatible with previous X2 version but not might not be downgrade-able)

X3 = FC Standard Patch / Stability Fix (Will be compatible with previous X3 version as well as downgrade-able)

Lettering:

R = Non-LTS Stable Release

Q = LTS Stable Release 

A = Non-LTS Unstable Release

Δ = LTS Unstable Release

Timeframe:

R = One Time Stable Build (Releases whenever new stability is achieved)

Q = Quarterly Long Term Support Build (Releases every quarter replacing previous Q build)

A = One Time Unstable Build (Releases whenever data for a new feature needs to be acquired)

Δ = Yearly Long Term Support Unstable Build (Releases at the beginning of every year and is updated all year independent of stability)

More Example Version Updates:

1.0.0.Q 

1.0.1.R

1.0.2.A

1.0.2.R

1.0.3.R

1.1.0.Δ

1.1.0.R

1.1.0.Q

Platforms:

Architechures: x86_64, arm64, (possible future IBM Power and RISC-V support if demand is great enough)

Future Packages will be provided for Windows, Mac OSX, Android, Ubuntu Touch and FreeBSD.
Planned Linux Package Support: Binary, AppImage, Debian(deb), Snapcraft(snapd), Flathub(flatpak), AUR(rpm), Open Store(clickable), Gentoo(source code lol)

Dependancies:
freeglut3 (future to be added to a.h)
freeglut3-dev (future to be added to a.h)
libglew-dev (future to be added to a.h)
Dear IMGUI (backends for glut and opengl3) (future to be added to a.h)
libcurl (tested using sudo apt-get install libcurl4-gnutls-dev on Ubuntu) (future to be added to a.h)
(can be compiled without dependancies by removing line from dev.cpp #define ASPECTUFXTOOLS)
C++ 17 or higher (C++ 14 would work but is untested as we try to use modern features when ever we can)

exprtk (header only include) (is included in package, may need to be swapped for non linux operating systems)
FC is tested on Ubuntu 22.04LTS using the GNU Compiler Collection, other compilers may work but are untested.
We make no promices to use Standard C++, if it works and is cross platform we use it.

(planned future external deps include: UIRN(Unique ID Random Number) Hasher[hash.h], Patchwork[patchwork.h & codex.h], VixInt128[int128.h])
