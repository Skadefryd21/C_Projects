#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void checkCreditCard(char *creditCard);
int checkSum(char *creditCard);

int main(void){
    int condition = 1;
    while(condition == 1){
        char *numberArr = (char*)malloc(17 * sizeof(char));
        printf("Number: ");
        int result = scanf("%16s", numberArr);
        if(result == 1){
        checkCreditCard(numberArr);
        free(numberArr);
        condition = 0;
        return 0;
    }
    }
}

void checkCreditCard(char *creditCard) {
    if(checkSum(creditCard) != 0){
        printf("INVALID\n");
        return;
    }

    int stringLength = strlen(creditCard);
    if (stringLength == 15 || 
        stringLength == 13 || 
        stringLength == 16) {
        if (creditCard[0] == '4') {
            printf("VISA\n");
        }
        else if (stringLength == 15 && (creditCard[0] == '3' && 
        (creditCard[1] == '4' || 
        creditCard[1] == '7'))) {
            printf("AMEX\n");
        }
        else if (stringLength == 16 && 
                 creditCard[0] == '5' && 
                 creditCard[1] >= '1' && 
                 creditCard[1] <= '5') {
            printf("MASTERCARD\n");
        } else {
            printf("INVALID\n");
        }
    } else {
        printf("INVALID\n");
    }
}

int checkSum(char *creditCard){
    int creditCardLength = strlen(creditCard);
    int walkCounter = 0;
    int sum1 = 0;
    int sum2 = 0;
        // Starting from the end
    for(int i = creditCardLength - 1; i >= 0; i--){
        int doubledDigit = (creditCard[i] - '0') * 2;
        // If the walkCounter MOD 2 != 0 AKA every other iteration
        if(walkCounter % 2 != 0){
        // Luhn's algorithm
        // doubledDigit = 13 --> 13 > 9 so 13 - 9 = (1) + (3))
        if (doubledDigit > 9) {
                doubledDigit -= 9;  
            }
            // Multiply digit by 2 and add to sum
            sum1 += doubledDigit;
        }
        else if(walkCounter % 2 == 0){
            sum2 += ((int)creditCard[i] - '0');
        }
        walkCounter++;
    }
    return ((sum1 + sum2) % 10 == 0) ? 0 : 1;
}