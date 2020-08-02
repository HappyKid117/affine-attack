#include <stdio.h>
#include <math.h>
#include "affinedecrypt.h"

int Ainv[] = {1, 8, 21, 15, 3, 19, 7, 23, 11, 5, 17, 25};

void printmsgi(char str[], int i){
    int ainv, b;
    ainv = Ainv[(i/26 + (i%26>0))-1];
    b = (i%26);
    printmsg(str, ainv, b);

}

int main(){
    char ciphertxt[100000];
    int Devoid[312], Weights[312];
    scanf("%[^\n]", ciphertxt);
    //printf("\n");

    int n; // length of cipher text
    for(n=0; ciphertxt[n]!='\0'; n++);

    int k=0;
    for(int i=0; i<12; i++){
        for(int j=1; j<=26; j++){
            int Val[2];
            decrypt(ciphertxt, Ainv[i], j, Val);
            Devoid[k] = Val[0];
            Weights[k] = Val[1];
            k++;
        }
    }

    int min = 99999, index;
    for(int i=0; i<312; i++){
        if(Devoid[i]<min){
            min = Devoid[i];
            index = i;
        }
        if(Devoid[i]<=min+1){
            if(Weights[i]<Weights[index]){
                index = i;
            }
        }
    }

    printf("A few possible decryptions are:\n\n");
    for(int i=0; i<312; i++){
        if(Devoid[i]<=min+1 && Weights[i]<n*5){
            printmsgi(ciphertxt, i+1);
        }
    }

    printf("\n\nA possible decryption is:\n\n");
    printmsgi(ciphertxt, index+1);
}