#include <stdio.h>

int check1(char a){
    if(a=='A'|| a=='E' || a=='I' || a=='O' || a=='U' || a=='Y'){
        return 1;
    }else{
        return 0;
    }
}

int weigh(char str[]){
    int w = 0;
    
    int n;
    for(n=0; str[n]!='\0'; n++);

    for(int i=0; str[i]!=0; i++){
        if(str[i]=='Y'){
            w++;
        }
        if(str[i]=='Z' || str[i]=='V'){
            w+=2;
        }
        if(i<n-1 && str[i+1]!=' ' && str[i]=='Q' && str[i+1]!='U'){
            w=1000;
        }else if(i<n-1 && str[i+1]!=' ' && str[i]=='Q' && str[i+1]=='U'){
            w=-100;
        }
        if(i<n-1 && str[i+1]!=' ' && str[i]=='X' && check1(str[i+1])==0 ){
            w=1000;
        }
        if(i<n-1 && (str[i]=='O' && str[i+1] == 'O')){
            w-=5;
        }
        if(i<n-1 && (str[i]=='E' && str[i+1]=='E')){
            w-=5;
        }
        if(i<n-1 && (str[i]=='S' && str[i+1]=='H')){
            w-=5;
        }
        if(i<n-1 && (str[i]=='S' && str[i+1]=='C')){
            w-=10;
        }
        if(i<n-1 && (str[i]=='S' && str[i+1]=='S')){
            w-=10;
        }
        if(i<n-1 && (str[i]=='S' && str[i+1]=='T')){
            w-=5;
        }
        if(i<n-1 && (str[i]=='I' && str[i+1]=='E')){
            w-=5;
        }
        if(i<n-1 && (str[i]=='T' && str[i+1]=='H')){
            w-=5;
        }
        if(i<n-1 && (str[i]=='O' && str[i+1]=='U')){
            w-=5;
        }
        if(i<n-1 && (str[i]=='I' && str[i+1]=='S')){
            w-=50;
        }
        if(i<n-2 && (str[i]=='I' && str[i+1]=='O' && str[i+2]=='N')){
            w-=100;
        }
        if(i<n-2 && (str[i]=='I' && str[i+1]=='N' && str[i+2]=='G')){
            w-=100;
        }
        if(i<n-2 && (str[i]=='A' && str[i+1]=='N' && str[i+2]=='D')){
            w-=100;
        }
    }

    return w;
}