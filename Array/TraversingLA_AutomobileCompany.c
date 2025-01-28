#include<stdio.h>
int main(){
    int LB,UB,len;
    printf("Enter Lower Bound and Upper Bound of Array: ");
    scanf("%d %d",&LB,&UB);

    len = UB - LB + 1;
    int AUTO[len];

    for(int i=0;i<len;i++){
        printf("Enter the number of automobiles sold in %d year: ",i+LB);
        scanf("%d",&AUTO[i]);
    }

    for(int i=0;i<len;i++){
        printf("Number of automobiles sold in year %d is : %d\n",i+LB,AUTO[i]);
        printf("The address of the index %d is: %p\n",i+LB,(void *)&AUTO[i]);
    }
}