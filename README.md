# SFML_Tutorials

## SFML+MinGW64+MSYS2+CMake

1. add mirror site

* /etc/pacman.d/mirrorlist.mingw32
```
Server = https://mirrors.tuna.tsinghua.edu.cn/msys2/mingw/i686/
Server = http://mirrors.ustc.edu.cn/msys2/mingw/i686/
```

* /etc/pacman.d/mirrorlist.mingw64
```
Server = https://mirrors.tuna.tsinghua.edu.cn/msys2/mingw/x86_64/
Server = http://mirrors.ustc.edu.cn/msys2/mingw/x86_64/
```

* /etc/pacman.d/mirrorlist.msys
```
Server = https://mirrors.tuna.tsinghua.edu.cn/msys2/msys/$arch/
Server = http://mirrors.ustc.edu.cn/msys2/msys/$arch/
```
2. update the package database and core system packages
```
pacman -Syu
```
3. close Msys2, and open it again, update the reset
```
pacman -Su
```
4. install vim
```
pacman -S vim
```
5. install git
```
pacman -S git
```
6. install gcc
```
pacman -S mingw-w64-x86_64-gcc
```
7. install make
```
pacman -S mingw-w64-x86_64-make
ming32-make
```
8. install cmake
```
pacman -S mingw-w64-x86_64-cmake
cmake -G"MinGW Makefiles" ../
```
9. install sfml
```
pacman -S mingw-w64-x86_64-sfml
```