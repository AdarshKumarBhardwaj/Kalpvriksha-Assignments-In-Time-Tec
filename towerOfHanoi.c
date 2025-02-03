#include <stdio.h>

void towerOfHanoi(int number,char start,char mid,char end){
    if(number<=0){
        printf("Enter valid number of disc\n");
    }
    else if(number==1){
        printf("\nMove disc from %c to %c ",start,end);
    }else{
        towerOfHanoi(number-1,start,end,mid);
        towerOfHanoi(1,start,mid,end);
        towerOfHanoi(number-1,mid,start,end);
    }
}

int main() {
   int number;
   printf("Enter number of disc\n");
   scanf("%d",&number);
   printf("Tower of hanoi of disc %d ",number);
   printf("\n");
   towerOfHanoi(number,'a','b','c');
    return 0;
}

