#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "io.h"
#include "string.h"
#include "disk.h"

/* Check if the compiler thinks you are targeting the wrong operating system. */
void print_footer();

#if defined(__linux__)
#error "You are not using a cross-compiler, you will most certainly run into trouble"
#endif

/* This project will only work for the 32-bit ix86 targets. */
#if !defined(__i386__)
#error "This project needs to be compiled with a ix86-elf compiler"
#endif

void print_banner(void) {

    println("__________.__ __   ________    _________     ");
    println("\\______   \\__|  | _\\_____  \\  /   _____/     ");
    println(" |     ___/  |  |/ //   |   \\ \\_____  \\      ");
    println(" |    |   |  |    </    |    \\/        \\     ");
    println(" |____|   |__|__|_ \\_______  /_______  /     ");
    println("                  \\/       \\/        \\/      ");

}

void print_footer() {
    println("PikOS Kernel");
    println("Version: 0.0.2-SNAPSHOT");
    println("Copyright (C) 2020, Riccardo Pittiglio <pikard86@gmail.com>");
}

void kernel_main(void) {
    /* Initialize terminal interface */
    init_system_out();
    print_banner();

    int params[2] = {12, 4};
    char *format = "Testing output form assembler and back input %d, %d";
    println(format);

    format_string(format, params);
    println(format);



    print_footer();
}
