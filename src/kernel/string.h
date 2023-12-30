//
// Created by phrometheus on 27/12/23.
//

#ifndef PIKOS_STRING_H
#define PIKOS_STRING_H

char to_char(int num) {
    char digit = '\0';
    switch (num) {
        case 0:
            digit = '0';
            break;
        case 1:
            digit = '1';
            break;
        case 2:
            digit = '2';
            break;
        case 3:
            digit = '3';
            break;
        case 4:
            digit = '4';
            break;
        case 5:
            digit = '5';
            break;
        case 6:
            digit = '6';
            break;
        case 7:
            digit = '7';
            break;
        case 8:
            digit = '8';
            break;
        case 9:
            digit = '9';
            break;
    }
    return digit;
}

size_t strlen(const char *str) {
    size_t len = 0;
    while (str[len]) {
        len++;
    }
    return len;
}

void clear_string(char *str, size_t len) {
    for (size_t i = 0; i < len; i++) {
        str[i] = '\0';
    }
}

void int_to_string(int value, char *out_buf) {
    int digit;
    float decimal_value;
    int i = 0;
    int current_value = value;

    char *stack;

    while (current_value > 0) {
        decimal_value = current_value / 10.0;
        digit = (decimal_value - ((int) decimal_value)) * 10;
        stack[i] = to_char(digit);
        current_value = (int) decimal_value;
        i++;
    }
    int num = i;
    for (int c = 0; c < num; c++) {
        out_buf[c] = stack[num - 1 - c];
    }
}

void format_string(char *format, int *params) {
    int size = strlen(format);
    int param_idx = 0;
    for (int pos = 0; pos < size; pos++) {

        if (format[pos] == '%' && pos < size - 1) {
            if (format[pos + 1] == 'd') {
                int_to_string(params[param_idx], format + pos);
                param_idx++;
            }
        }
    }
}

#endif //PIKOS_STRING_H
