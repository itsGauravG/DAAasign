// Joshepus using recursion 
//starting with 0th pos 

#include<stdio.h>


int jos(int n,int k){


    if(n==1){
        return 0;
    }
else{

    return (jos(n-1,k) + k )%n ;
}
}


int main(){

int n,k;
    printf("Enter number of people\n");
    scanf("%d",&n);

    printf("Enter k \n");
    scanf("%d",&k);


    int win  = jos(n,k);

    printf("The winner is at position : %d",win);
}