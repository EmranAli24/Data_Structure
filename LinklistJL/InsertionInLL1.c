// Insertion at beginning,at end,after a given position
#include<stdio.h>
#include<stdlib.h>

int main(){

    struct node {
        int data;
        struct node *next;
    };

    struct node *head,*newnode,*temp;
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

    printf("Before Inserting : \n");
    temp = head ;
    while(temp != 0){
        printf("%d ",temp->data);
        temp = temp -> next;
    }

    int pos;
    printf("\n At which position you want to insert data?");
    scanf("%d",&pos);

    if(pos == 0){
        newnode = (struct node *) malloc (sizeof(struct node));
        printf("Enter data you want to insert: ");
        scanf("%d",&newnode->data);
        newnode->next = head;
        head = newnode;
    }
    else if( pos == count){
        newnode = (struct node *) malloc (sizeof(struct node));
        printf("Enter data you want to insert: ");
        scanf("%d",&newnode->data);
        newnode->next = 0;
        temp = head;
        while (temp->next != 0)
        {
            temp = temp->next;
        }
        
        temp->next = newnode;
        
    }
    else{
         if(pos > count){
            printf("Invalid position.");
         }
         else{
            temp = head;
            while(i<pos-1){
                temp = temp -> next;
                i++;
            }
        newnode = (struct node *) malloc (sizeof(struct node));
        printf("Enter data: ");
        scanf("%d",&newnode->data);
        newnode->next = temp->next;
        temp->next = newnode;

         }

        


    }

    printf("After Inserting data: \n");

    
    temp = head;
    while(temp != 0){
       printf("%d ",temp->data);
       temp = temp->next;

    }


    
}