export PREFIX="$HOME/opt/cross"
export TARGET=i686-elf
export PATH="$PREFIX/bin:$PATH"

echo Downloading binutils
wget https://ftp.gnu.org/gnu/binutils/binutils-2.34.tar.gz

echo Extracting binutils archive
tar -xvf binutils-2.34.tar.gz 


mkdir binutils-build
cd binutils-build/

echo Building binutils
../binutils-2.34/configure --target=$TARGET --prefix="$PREFIX" --with-sysroot --disable-nls
make
make install
cd ..

echo $PWD



echo Downloading gcc 7.5.0
wget https://ftp.gnu.org/gnu/gcc/gcc-7.5.0/gcc-7.5.0.tar.gz
tar -xvf  gcc-7.5.0.tar.gz 

mkdir gcc-build

cd gcc-build/

echo Building custom gcc 

which -- $TARGET-as || echo $TARGET-as is not in the PATH
../gcc-7.5.0/configure --target=$TARGET --prefix="$PREFIX" --disable-nls --enable-languages=c,c++ --without-headers
make all-gcc
make install
make all-target-libgcc
make install-gcc
make install-target-libgcc
cd ..

echo $PWD

rm binutils-2.34.tar.gz
rm gcc-7.5.0.tar.gz

