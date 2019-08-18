#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <getopt.h>

#define BYTESIZE 8

void string_to_bits(const char* string, bool* bits) {
    for (int i = 0; i < BYTESIZE; ++i) {
        if (string[i] == '1') {
            bits[i] = 1;
        } else if (string[i] == '0') {
            bits[i] = 0;
        }
    }
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

int main(int argc, char** argv) {
    bool first_number_bits[BYTESIZE];
    char first_number_string[BYTESIZE];
    char hex_string[BYTESIZE / 4];

    int c;
    char opt;
    bool second_number_flag = false;

    while ((c = getopt (argc, argv, "asmdhf:i:")) != -1) {
        switch (c) {
            //show as hex
            case 'h':
                opt = 'h';
                break;

            case 'f':
                strcpy(first_number_string, optarg);
                break;

            default:
                printf("Option not available.\n");
        }
    }

    //convert first string to bits
    //first string has to be given
    string_to_bits(first_number_string, first_number_bits);

    switch (opt) {
        case 'h':
            to_hex(first_number_bits, hex_string);
            for (int i = 0; i < (BYTESIZE / 4); i++) {
                printf("%c", hex_string[i]);
            }
            printf("\n");
            break;
    }

    return 0;
}