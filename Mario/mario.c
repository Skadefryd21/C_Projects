#include <stdio.h>
#include <stdlib.h>

void printObstacle(int height);

int main(void)
{
    int height;
    short condition = 1;

    while(condition == 1){
        printf("How tall should the obstacle be: \n");
        int result = scanf("%i", &height);
        if(result == 1){
            if(height > 0 && height < 9){
            printObstacle(height);
            condition = 0;
        }
        else{
            //Integer has size of 4 bytes.
            if(sizeof(height) != sizeof(int)){
                printf("Input must be of type Integer.");
            }
            else{
                printf("Input must be from 1 to and with 8.");
            }
        }
        }
    }
}

void printObstacle(int height){
    for(int i = 0; i < height; i++){
        for(int j = 0; j < height; j++){
            if(j < height - 1){
                printf(".");
            }
            else{
                printf("#..#\n");
            }
        }

    }
}