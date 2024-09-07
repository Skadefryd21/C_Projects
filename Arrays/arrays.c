#include <stdio.h>

int main(void){
    int input = get_int();
// Dynamic arrays must have dynamic memory allocation.
// char, int, double &  etc.. differ in memory size, exmaple: double = 8 bytes.
// malloc has *void return type, our *row pointer should point to the pointer of the memory allocation.
// Incriment the size of the arr to have memory for null-termination at the end of the arr.
    char *row = (char*)malloc((input + 1) * sizeof(char));
    row[input] = '\0'; // Null-termination.
}
