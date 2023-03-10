#include <stdio.h>
#include "fiizbuzz.h"
#include "string.h"
#include "stdlib.h"
typedef struct{
    char* number;
    int size
}Huge;

int maxi(int x, int y){
    if (x>y){
        return x;
    }
    return y;
}
char* inv_list(char* ch){
    int taille= strlen(ch),i=taille-1,j=0;
    char* ch2= malloc(taille);
    while (i>=0){
       ch2[j]=ch[i];
       i--;
       j++;
    }
    ch2[j]='\0';
    return ch2;
}
Huge creer_Huge(int size){
    Huge x;
    x.number= malloc(size);
    x.size=size;
    return x;
}
char* vide0(Huge n){
    char* ch2= malloc(n.size);
    int i=0,j=0;
    while(n.number[i]=='0'){
        i++;
    }
    if (i==0){
        return n.number;
    }
    for(i;i<n.size;i++){
        ch2[j]=n.number[i];
        j++;
    }
    ch2[j]='\0';
    return ch2;
};
Huge addition(Huge x,Huge y){
    x.number= inv_list(x.number);
    y.number= inv_list(y.number);
    Huge res= creer_Huge(maxi(x.size,y.size)+1);
    int a, b,i=0, retenue=0;
    while (i<res.size){
        if (i>=x.size){
            a=0;
        }
        else{
            a=(int)x.number[i]-48;
        }
        if (i>=y.size){
            b=0;
        }
        else{
            b=(int)y.number[i]-48;
        }
        res.number[i]=(char)((a+b+retenue)%10+48);
        retenue=(a+b+retenue)/10;
        i++;
    }
    res.number[res.size]='\0';
    res.number= inv_list(res.number);
    res.number= vide0(res);
    return res;

}
char* scanstr(){
    char* ch= malloc(1);
    scanf("%s",ch);
    ch[strlen(ch)]='\0';
    return ch;
}
int main() {




}
