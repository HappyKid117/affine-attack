#include <stdio.h>

int check(char a){
    if(a=='A'|| a=='E' || a=='I' || a=='O' || a=='U' || a=='Y'){
        return 1;
    }else{
        return 0;
    }
}


int sencheck(char str[]){
    int maxdevoid=0, devoid=0, ok=0;

    for(int i=0; str[i]!='\0'; i++){
        if(str[i] == ' '){
            if(ok==0){
                maxdevoid = 1000;
                break;
            }else{
                if(devoid>maxdevoid){
                    maxdevoid = devoid;
                }
            }

            ok = 0;
            devoid = 0;
            continue;
        }

        if(check(str[i])){
            if(devoid>maxdevoid){
                maxdevoid=devoid;
            }
            ok = 1;
            devoid = 0;
        }else{
            devoid++;
        }
    }

    if(ok==0){               //
        maxdevoid = 1000;    //
    }                        //
    if(devoid>=maxdevoid){   //for the last word in the sentence
        maxdevoid = devoid;  //
    }                        //

    return maxdevoid;
}