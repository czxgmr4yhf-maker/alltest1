#include <stdio.h>

int main() {
    //input
    char input[14] = {0};
    int numArray[14] = {0};
    scanf("%s", input);
    int j = 0;

    //get corret numArray
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] >= '0' && input[i] <= '9') {
            numArray[j++] = input[i] - '0';        
        }else if (input[i] == 'X'){
            numArray[j++] = 10;
        }
    }

    // calulate
    int corretNumber = 0;
    for (int i = 0; i < j - 1; i++) {
        corretNumber += numArray[i] * (i + 1);
    }
    
    //compare 
    if (corretNumber % 11 == 10 && input[12] == 'X') {
        printf("Right");         
    }else if(corretNumber % 11 == 10 && input[12] != 'X'){
        input[12] = 'X';
        for (int i = 0; i < 13; i++){
            printf("%c", input[i]);
        }
    }else if(corretNumber % 11 != 10 && input[12] == '0' + corretNumber % 11) {
        printf("Right");
    }else {
        input[12] = '0' + corretNumber % 11;
        for (int i = 0; i < 13; i++){
            printf("%c", input[i]);
        }
    }

    return 0;
}