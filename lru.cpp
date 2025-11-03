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
    
        int miss=0;
        int hit=0;
        int k=0;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            int val=arr[i];
            if(mpp.find(val)!=mp.end()){
                hit++;
                mp[val]=i;
            }
            else{
                miss++;
                if(mp.size()<m){
                    mp[val]=i;
                }
                else{
                    int lru=INT_MAX;
                    int key;
                    for(auto it:mp){
                        if(it.second<lru){
                            lru=it.second;
                            key=it.first;
                        }
                    }
                    mp.erase(key);
                    mp[val]=i;
                }
        }
    
       
        printf("%d",miss);
        printf("%d",hit);
    
            return 0;
}