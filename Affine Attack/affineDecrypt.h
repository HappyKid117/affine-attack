#include<stdio.h>
#include "weight.h"
#include "sentencecheck.h"

void printmsg(char str[], int ainv, int b){
    char msg[100000];
    int i;
    for(i=0; str[i]!='\0'; i++){
        if(str[i]==' '){
            msg[i] = ' ';
        }else{
            msg[i] = (char)(((ainv * ((str[i]+'A' - b)) % 26)) + 'A');
        }
    }
    msg[i] = '\0';
    printf("%s\n", msg);
}

void decrypt(char str[], int ainv, int b, int V[]){
    char msg[10000];
    int i;
    for(i=0; str[i]!='\0'; i++){
        if(str[i]==' '){
            msg[i] = ' ';
        }else{
            msg[i] = (char)(((ainv * ((str[i]-'A' - b+26)) % 26)) + 'A');
        }
    }
    msg[i] = '\0';
    V[0] = sencheck(msg);
    V[1] = weigh(msg);
    //printf("%s = %d %d %d %d\n", msg, V[0], V[1], ainv, b);
}

//int main(){
//    char str[] = "ZRC KEWSG NPAOV HAT BEQFCX AJCP ZRC LIDY XAM";
//    decrypt(str, 21, 8);
//}