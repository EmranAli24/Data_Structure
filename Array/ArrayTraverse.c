#include<stdio.h>
int main(){

int LA[50],size,i;

printf("Enter Size of Array: ");
scanf("%d",&size);  

printf("Enter elements of Array: ");
for(i=0;i<size;i++){
    scanf("%d",&LA[i]);
}

printf("Elements of array are:\n");
for(i=0;i<size;i++){
    printf("LA[%d]: is %d\n",i,LA[i]);
}

}