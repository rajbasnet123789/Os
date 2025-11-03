#include<stdio.h>
int main(){
     int n;
     printf("Enter the size of array:");
     scanf("%d",&n);
     int arr[n];
     int m;
     printf("Enter the size of cache:");
     scanf("%d",&m);
     int lru[m];
     for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
     }
     for(int i=0;i<n;i++){
        lru[i]=0;
     }
     int miss=0;
     int hit=0;
     int k=0;

     for(int i=0;i<n;i++){
        int val=arr[i];
        int found=0;
        // for(int j=0;j<m;j++){
        //     printf("%d ",lru[j]);
        // }
        // printf("\n");
        for(int j=0;j<m;j++){
            if(lru[j]!=0 && val==lru[j]){
                hit++;
                found=1;
                break;
            }

            
        }
        if(found==0){
            miss++;
            lru[k]=val;
            k=(k+1)%m;
        }

       
     }
     printf("%d",miss);
     printf("%d",hit);

        return 0;
}