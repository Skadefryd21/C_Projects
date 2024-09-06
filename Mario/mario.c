#include <stdio.h>
#include <stdlib.h>

void printObstacle(int height);

int main(void)
{
    int height = 0;
    short condition = 1;

    while(condition == 1){
        printf("How tall should the obstacle be: \n");
        int result = scanf("%i", &height);
        if(result != 1 || height < 1 || height > 8){
            system("cls");
            while (getchar() != '\n'){
            printf("Input must be of type Integer & must be within the range of 1 to and with 8, try again. \n");
        }
    }
        else{
            printObstacle(height);
            condition = 0;
        }  
    }
    return 0;
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