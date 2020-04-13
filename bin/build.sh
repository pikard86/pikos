export PREFIX="$HOME/opt/cross"
export TARGET=i686-elf
export PATH="$PREFIX/bin:$PATH"

./clean

echo "building boot sector"
mkdir -p target/boot
i686-elf-as src/boot/boot.s -o target/boot/boot.o

echo "building kernel"
mkdir -p target/kernel
i686-elf-gcc -c src/kernel/kernel.c -o target/kernel/kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra

echo "Linking the kernel"
mkdir -p target/bin
i686-elf-gcc -T src/boot/linker.ld -o target/bin/pikos.bin -ffreestanding -O2 -nostdlib target/boot/boot.o target/kernel/kernel.o -lgcc

echo "Checking kernel image with grub"

if grub-file --is-x86-multiboot target/bin/pikos.bin; then
  echo multiboot confirmed
else
  echo the file is not multiboot
fi

echo "Generating bootable iso"
mkdir -p target/isodir/boot/grub
cp target/bin/pikos.bin target/isodir/boot/pikos.bin
cp src/boot/grub.cfg target/isodir/boot/grub/grub.cfg
grub-mkrescue -o target/pikos.iso target/isodir
