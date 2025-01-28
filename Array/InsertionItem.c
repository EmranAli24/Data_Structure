#include<stdio.h>
int main(){
    int N,K,item;
    printf("Enter The array size: ");
    scanf("%d",&N);
    int LA[N];

    printf("Enter array elements: ");
    for(int i=0;i<N;i++){
        scanf("%d",&LA[i]);
    }
    printf("Before inserting the item array elements are:\n");
    for(int i=0;i<N;i++){
        printf("LA[%d]: %d  ",i,LA[i]);
    }
    printf("\nEnter the item: ");
    scanf("%d",&item);
    printf("Enter the position of item you want to insert: ");
    scanf("%d",&K);

    if(K<0 || K > N){
        printf("Invalid position.\n");
        printf("Enter the position: ");
        scanf("%d",&K);
    }

    for(int j=N-1;j>=K-1;j--){
        LA[j+1] = LA[j];
    }
    LA[K-1] = item;
    N++;

    printf("After inserting the item %d the array is:\n",item);
    for(int i=0;i<N;i++){
        printf("LA[%d] : %d  ",i,LA[i]);
    }

    return 0;

}