#include<stdio.h>
int main(){

    int N,K,item;
    printf("Enter the size of Array: ");
    scanf("%d",&N);

    int LA[N];
    printf("Enter array elements:\n");
    for(int i=0;i<N;i++){
        scanf("%d",&LA[i]);
    }

    printf("Array before deletion th""e item: \n");
    for(int i=0;i<N;i++){
        printf("LA[%d]: %d ",i,LA[i]);
    }

    printf("\nEnter the position you want to delete from array: ");
    scanf("%d",&K);

if(K<0 || K>N){

    printf("Error!!Please enter a valid position:");
    scanf("%d",&K);

}

item = LA[K-1];

for(int i=K-1;i<N;i++){
    LA[i] = LA[i+1];
}
N--;

for(int i=0;i<N;i++){
    printf("LA[%d]: %d  ",i,LA[i]);
}

printf("\nThe item Delete from array : %d\n",item);
    


}