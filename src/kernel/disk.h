//
// Created by phrometheus on 27/12/23.
//

#ifndef PIKOS_DISK_H
#define PIKOS_DISK_H


int read_sector(){
    uint32_t dwRes;

    asm ("bsfl %1,%0"
    : "=r" (dwRes)
    : "r" (dwSomeValue)
    : "cc");

    assert(dwRes > 3);
}


#endif //PIKOS_DISK_H
