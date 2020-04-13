#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "terminal.h"

/* Check if the compiler thinks you are targeting the wrong operating system. */
#if defined(__linux__)
#error "You are not using a cross-compiler, you will most certainly run into trouble"
#endif

/* This tutorial will only work for the 32-bit ix86 targets. */
#if !defined(__i386__)
#error "This tutorial needs to be compiled with a ix86-elf compiler"
#endif

void print_banner(void) {

    terminal_writestring("__________.__ __   ________    _________     \n");
    terminal_writestring("\\______   \\__|  | _\\_____  \\  /   _____/     \n");
    terminal_writestring(" |     ___/  |  |/ //   |   \\ \\_____  \\      \n");
    terminal_writestring(" |    |   |  |    </    |    \\/        \\     \n");
    terminal_writestring(" |____|   |__|__|_ \\_______  /_______  /     \n");
    terminal_writestring("                  \\/       \\/        \\/      \n");

}

void kernel_main(void) {
    /* Initialize terminal interface */
    terminal_initialize();
    print_banner();

    terminal_writestring("PikOS Kernel\n");
    terminal_writestring("Version: 0.0.1-SNAPSHOT \n");
    terminal_writestring("Copyright (C) 2020, Riccardo Pittiglio <pikard86@gmail.com> \n");
}
