#include <stdio.h>

int main(void){
    int input = get_int();
//Dynamic arrays must have dynamic memory allocation.
//char, int, double &  etc.. differ in memory size, exmaple: double = 8 bytes.
//malloc has *void return type, our *row pointer should point to the pointer of the memory allocation.
    char *row = (char*)malloc(input * sizeof(char));
}
