echo "building boot sector"
i686-elf-as boot.s -o boot.o

echo "building kernel"
i686-elf-gcc -c kernel.c -o kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra

echo "Linking the kernel"
i686-elf-gcc -T linker.ld -o pikos.bin -ffreestanding -O2 -nostdlib boot.o kernel.o -lgcc

echo "Checking kernel image with grub"

if grub-file --is-x86-multiboot pikos.bin; then
  echo multiboot confirmed
else
  echo the file is not multiboot
fi

echo "Generating bootable iso"
mkdir -p isodir/boot/grub
cp pikos.bin isodir/boot/pikos.bin
cp grub.cfg isodir/boot/grub/grub.cfg
grub-mkrescue -o pikos.iso isodir
