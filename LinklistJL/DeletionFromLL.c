#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main(){
  

    struct node *head,*newnode,*temp,*nextNode;
    head = 0;
    int choice = 1;
    int count=0;
    int i=0;

    while (choice)
    {
        newnode = (struct node *) malloc(sizeof(struct node));
        count++;
        printf("Enter Data: ");
        scanf("%d",&newnode->data);
        newnode->next = 0;

        if(head == 0){
            head = temp = newnode;
        }
        else{
            temp -> next = newnode;
            temp = newnode;

        }

        printf("Do you want to continue(0,1)? ");
        scanf("%d",&choice);
    }

    printf("Before Deleting any element : \n");
    temp = head ;
    while(temp != 0){
        printf("%d ",temp->data);
        temp = temp -> next;
    }

    int pos;
    printf("\n From which position you want to Delete data?");
    scanf("%d",&pos);

    if(pos == 0){
        temp = head;
        head = head ->next;
        free(temp);
    }

    else if(pos == count){
        struct node *prev;
        temp = head;
        while(temp->next != 0){
            prev = temp ;
            temp = temp->next;
        }

        if(temp == head ){
            head = 0;
        }
        else{
            prev->next = 0;
        }
        
        free(temp);
    }

    else{
        if(pos > count || pos < 0){
            printf("Invalid position.");
        }
        else{
        
            temp = head;
            while(i<pos-1){
                temp = temp ->next;
                i++;
            }

            nextNode = temp -> next;
            temp -> next = nextNode->next;
            free(nextNode);

        }
    }

    printf("\nAfter Deleting the element: \n");
    temp = head;
    while(temp != 0){
        printf("%d ",temp->data);
        temp = temp->next;
    }
}