//
// Created by phrometheus on 27/12/23.
//

#ifndef PIKOS_STRING_H
#define PIKOS_STRING_H

size_t strlen(const char *str) {
    size_t len = 0;
    while (str[len])
        len++;
    return len;
}

#endif //PIKOS_STRING_H
