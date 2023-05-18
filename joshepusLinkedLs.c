// Jospehpus using linked list 
// starting with 1 
#include<stdio.h>
#include<stdlib.h> 


struct node{
    int playerid;
    struct node* next;
};

struct node *start, *ptr, *new_node;

int main(){



    int n,k;
    printf("Enter number of people\n");
    scanf("%d",&n);

    printf("Enter k \n");
    scanf("%d",&k);

    start = malloc(sizeof(struct node));
    ptr = start;

    start->playerid =1;

    //now create N circular nodes 

    for(int i=2;i<=n;i++){

        new_node = malloc(sizeof(struct node));
        ptr->next = new_node;
        new_node->next=start;
        new_node->playerid=i;

        ptr=new_node;

    }


    //run this loop until 1 player is left

    for(int count=1;count<n;count++){

        for(int i=0;i<k-1;++i){

            ptr = ptr->next;

        }
        printf("Deleted player ID : %d \n", ptr->next->playerid);
        ptr->next= ptr->next->next;
    }

    printf("the winner is %d",ptr->playerid);
    

}