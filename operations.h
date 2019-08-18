#ifndef BINARYCALCULATOR_OPERATIONS_H
#define BINARYCALCULATOR_OPERATIONS_H

#define BYTESIZE 8

int add(bool first_number[BYTESIZE], bool second_number[BYTESIZE]);
int subtract(bool first_number[BYTESIZE], bool second_number[BYTESIZE]);
int multipy(bool first_number[BYTESIZE], bool second_number[BYTESIZE]);
int divide(bool first_number[BYTESIZE], bool second_number[BYTESIZE]);

void to_hex(const bool number[BYTESIZE], char* hex_string);

#endif //BINARYCALCULATOR_OPERATIONS_H
