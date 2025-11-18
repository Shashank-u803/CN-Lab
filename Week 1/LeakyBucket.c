#include<stdio.h>
#include<stdbool.h>
int main(){
    int incoming,output_rate,bucket_size,stored=0,n;
    printf("=====Leaky Bucket algorithm=====\n");
    printf("Enter no of inputs:");
    scanf("%d",&n);
    printf("Enter Bucket Capacity:");
    scanf("%d",&bucket_size);
    printf("Enter Output Rate:");
    scanf("%d",&output_rate);
    
    printf("Enter input packet sizes:");
    int input[n];
    for(int i=0;i<n;i++){
        scanf("%d",&input[i]);
    }
    //Table of Contents
    printf("Bucket Before\t\tEmpty\t\t\tInput\t\t\tDiscarded\t\tPackets Dropped\t\tOutput rate\t\tBucket After\n");
    for(int i=0;i<n;i++){
        int before = stored;
        int incoming = input[i];
        bool discard = false;
        int rem = bucket_size - stored;
        int pkt_dropped = 0;
        if(incoming <= rem){
            stored += incoming;
        }else{
            stored = bucket_size;
            discard = true;
            pkt_dropped = incoming - rem;
        }
        //leak the bucket
        stored -= output_rate;
        if(stored<0){
            stored = 0;
        }
        //print entries
        printf("%d\t\t\t%d\t\t\t%d\t\t\t%s\t\t\t%d\t\t\t%d\t\t\t%d\n",before,bucket_size-before,incoming,discard?"Yes":"No",pkt_dropped,output_rate,stored);
    }
    return 0;
}
