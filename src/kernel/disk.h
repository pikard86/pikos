//
// Created by phrometheus on 27/12/23.
//

#ifndef PIKOS_DISK_H
#define PIKOS_DISK_H


int read_sector(int input) {
    int src = input;
    int dst;

    asm (
    "mov %1, %0\n\t"
    "add $1, %0"
    : "=r" (dst)
    : "r" (src)
    );

    return dst;
}


#endif //PIKOS_DISK_H
