wget https://ftp.gnu.org/gnu/gcc/gcc-7.5.0/gcc-7.5.0.tar.gz
wget https://ftp.gnu.org/gnu/binutils/binutils-2.34.tar.gz
tar -xvf binutils-2.34.tar.gz 
tar -xfv  gcc-7.5.0.tar.gz 
mkdir binutils-build
cd binutils-build/
../binutils-2.34/configure --target=$TARGET --prefix="$PREFIX" --with-sysroot --disable-nls
make
make install
cd ..

mkdir gcc-build
cd gcc-build/
which -- $TARGET-as || echo $TARGET-as is not in the PATH
../gcc-7.5.0/configure --target=$TARGET --prefix="$PREFIX" --disable-nls --enable-languages=c,c++ --without-headers
make all-gcc
make instal
make all-target-libgcc
make install-gcc
make install-target-libgccl

rm binutils-2.34.tar.gz
rm gcc-7.5.0.tar.gz

