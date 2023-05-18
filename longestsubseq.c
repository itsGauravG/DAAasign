// Longest Interger  Subsequence 

#include<stdio.h>

int LIS(int arr[],int n){

    int maxlen=0;
    int prev;

    for(int i=0;i<n;i++){
        int currlen=1;

        prev = arr[i];

        for(int j=i+1;j<n;j++){

            if(arr[j]>prev){
                currlen+=1;
                prev=arr[j];
            }
        }

        if(currlen>maxlen){
            maxlen = currlen;
        }

    }

return maxlen;


}


int main(){

    int arr[] = {10,22,9,33,21,50,41,60};
    int n= 8;

    int ans = LIS(arr,n);
    printf("Longest subseq is %d",ans);
}