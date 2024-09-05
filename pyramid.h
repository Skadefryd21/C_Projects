#include <stdio.h>

void printPyramidL(int height){
    int width = 1;

    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            printf("#");
        }
        printf("\n");
        width++;
    }
}