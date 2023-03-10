#include <iostream>

int mult_7(int x){
    int dizaine=x/10*10+10;
    int res=dizaine-x;
    dizaine+= 10*(res%3==2)+20*(res%3==1);
    res+= 10*(res%3==2)+20*(res%3==1);
    dizaine+=30*(x/70);
    res+=30*(x/70);

    if ((res*10)==3*dizaine|| x%70==0){
        return 1;
    }

    return 0;
}
int main() {
    for (int i=0; i<300;i++){
        if (mult_7(i)){
            printf("%d ",i);
        }
    }

    return 0;
}
