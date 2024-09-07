#include <stdio.h>
#include <stdlib.h>

void printObstacle(int height, int middleSeperation);

int main(void)
{
    int height = 0;
    int middle = 2;
    short condition = 1;

    while(condition == 1){
        printf("How tall should the obstacle be: \n");
        int result1 = scanf("%i", &height);
        if(result1 != 1 || height < 1 || height > 8){
            int c;
            system("cls");
            printf("Input for height must be of type Integer & must be within the range of 1 to and with 8, try again. \n");
            while (c = getchar() != '\n'){}
            continue;
        }
        printf("How wide should the hole of the obstacle be: \n");
        int result2 = scanf("%i", &middle);
        if(result2 != 1 || middle < 2 || middle > 4){
            int c;
            system("cls");
            printf("Input for width must be of type Integer & must be within the range of 2 to and with 4, try again. \n");
            while (c = getchar() != '\n'){}
            continue;
        }
        else{
            printObstacle(height, middle);
            condition = 0;
        }  
    }
    return 0;
}



void printObstacle(int height, int middleSeperation){
        // i represents a count of each printed row
    for(int i = 0; i < height; i++){
        int rowSize = height * 2 + middleSeperation;
        int numofDots = height- i - 1;
        int numofHashes = rowSize - numofDots;
        char *row = (char*)malloc((rowSize + 1) * sizeof(char));
        // i starting index = 0
        // The number of dots decreases as i increases
        for(int j = 0; j < numofDots;  j++){
            row[j] = ' ';
        }
        // j starting index = nomofDots
        // The number of hashes increases as it goes down the rows
        for(int j = numofDots; j < numofHashes; j++){
        // Since height defines the width of the left sided grid
        if(j < height || j > height - 1 + middleSeperation){
            row[j] = '#';
        }
        else{
            row[j] = ' ';
        }
        }
        row[rowSize] = '\0';    // String null-terminator
        printf("%s\n", row);
        free(row);              // Free alloc mem of arr
    }
}