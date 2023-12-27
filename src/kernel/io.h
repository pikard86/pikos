//
// Created by phrometheus on 27/12/23.
//
#include "terminal.h"

#ifndef PIKOS_IO_H
#define PIKOS_IO_H

void init_system_out(){
    terminal_initialize();
}

void print(const char *data) {
    terminal_write(data, strlen(data));
}

void println(const char *data) {
    terminal_write(data, strlen(data));
    terminal_new_line();
}
#endif //PIKOS_IO_H
