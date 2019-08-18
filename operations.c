#include <stdbool.h>
#include <math.h>

#include "operations.h"


int add(bool *first_number, bool *second_number) {
    return 0;
}

int subtract(bool *first_number, bool *second_number) {
    return 0;
}

int multipy(bool *first_number, bool *second_number) {
    return 0;
}

int divide(bool *first_number, bool *second_number) {
    return 0;
}

void to_hex(const bool *number, char* hex_string) {
    char hex_table[] = {'A', 'B', 'C', 'D', 'E', 'F'};

    int cur_value = 0;
    int bool_to_int = 0;

    int pos_overall = 0;
    int pos_hex_string = 0;

    //go through all quartets
    for (int i = 0; i < (BYTESIZE / 4); ++i) {

        //process quartet
        for (int j = 3; j >= 0; --j) {
            if (number[pos_overall]) {
                bool_to_int = 1;
            } else {
                bool_to_int = 0;
            }
            cur_value += pow(2, j) * bool_to_int;

            pos_overall++;
        }

        //add hex number to array
        //when value is under 10 just use normal number
        //else convert to hex character through global hex table
        if (cur_value < 10) {
            hex_string[pos_hex_string] = cur_value + '0';
        } else {
            hex_string[pos_hex_string] = hex_table[cur_value - 10];
        }

        pos_hex_string++;
        cur_value = 0;
    }
}
