#include<stdio.h>
int main(){
    int N,item,loc;
    printf("Enter array size: ");
    scanf("%d",&N);
    int Data[N];

    printf("Enter Array elements: ");
    for(int i=0;i<N;i++){

        scanf("%d",&Data[i]);

    }

    printf("Enter the item you want to search: ");
    scanf("%d",&item);

    Data[N+1] = item;

    loc = 0;
    while (Data[loc] != item)   
    {
        loc +=1;
    }

    if(loc == N+1){
        printf("The item %d is not found in the array.\n",item);
    }
    else{
        printf("The item %d is found at position %d.\n",item,loc);
    }
    

}