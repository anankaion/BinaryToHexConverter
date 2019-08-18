#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <getopt.h>

#include "operations.h"

void string_to_bits(const char* string, bool* bits) {
    for (int i = 0; i < BYTESIZE; ++i) {
        if (string[i] == '1') {
            bits[i] = 1;
        } else if (string[i] == '0') {
            bits[i] = 0;
        }
    }
}

int main(int argc, char** argv) {
    bool first_number_bits[BYTESIZE];
    bool second_number_bits[BYTESIZE];
    char first_number_string[BYTESIZE];
    char second_number_string[BYTESIZE];
    char hex_string[BYTESIZE / 4];

    int c;
    char opt;
    bool second_number_flag = false;

    while ((c = getopt (argc, argv, "asmdhf:i:")) != -1) {
        switch (c) {
            //add
            case 'a':
                opt = 'a';
                second_number_flag = true;
                break;

            //substract
            case 's':
                opt = 's';
                second_number_flag = true;
                break;

            //multiply
            case 'm':
                opt = 'm';
                second_number_flag = true;
                break;

            //division
            case 'd':
                opt = 'd';
                second_number_flag = true;
                break;

            //show as hex
            case 'h':
                opt = 'h';
                break;

            case 'f':
                strcpy(first_number_string, optarg);
                break;

            case 'i':
                if (second_number_flag) {
                    strcpy(second_number_string, optarg);
                }
                break;

            default:
                printf("Option not available.\n");
        }
    }

    //convert first string to bits
    //first string has to be given
    string_to_bits(first_number_string, first_number_bits);

    switch (opt) {
        case 'a':
            break;

        case 's':
            break;

        case 'm':
            break;

        case 'd':
            break;

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