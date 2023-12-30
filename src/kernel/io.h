//
// Created by phrometheus on 27/12/23.
//
#include "terminal.h"

#ifndef PIKOS_IO_H
#define PIKOS_IO_H

void init_system_out() {
    terminal_initialize();
}

void print(const char *string_ptr) {
    terminal_write(string_ptr, strlen(string_ptr));
}

void println(const char *string_ptr) {
    terminal_write(string_ptr, strlen(string_ptr));
    terminal_new_line();
}

#endif //PIKOS_IO_H
