#include<stdio.h>
#include<string.h>

void xor(char *temp,char *gen){
    int n = strlen(gen);
    for(int i=1;i<n;i++){
        temp[i] = (temp[i]==gen[i] ? '0': '1');
    }
}

void divide(char data[], char gen[], char rem[]){
    char temp[100];
    int dataLen = strlen(data);
    int genLen = strlen(gen);
    
    //copy data to temp
    for(int i=0;i<dataLen;i++){
        temp[i] = data[i];
    }
    
    for(int i=genLen;i<=dataLen;i++){
        //check if LMB is 1
        if(temp[0]=='1'){
            xor(temp,gen);
        }
        
        //shift left and append 
        for(int j=0;j<genLen-1;j++){
            temp[j] = temp[j+1];
        }
        
        if(i<dataLen){
            temp[genLen-1] = data[i];
        }
    }
    for(int i=0;i<genLen-1;i++){
        rem[i] = temp[i];
    }
    rem[genLen-1]='\0';
}

int main(){
    char message[100], generator[100];
    char appended[200], crc[100];
    printf("Enter Message bits:");
    scanf("%s",message);
    printf("Enter Generator bits:");
    scanf("%s",generator);
    int genLen = strlen(generator);
    //append genLen - 1 0s to message
    strcpy(appended,message);
    int n = strlen(message);
    for(int j=0;j<genLen-1;j++){
        appended[n+j] = '0';
    }
    appended[n+genLen-1] = '\0';
    printf("Message after appending: %s\n",appended);
    divide(appended,generator,crc);
    printf("CRC bits are: %s\n",crc);
    char rec_msg[100],rec_input[100];
    printf("Enter data recieved:");
    scanf("%s",rec_input);
    strcpy(rec_msg,rec_input);
    strcat(rec_msg,crc);
    printf("Reciever side (dividend to check):%s\n",rec_msg);
    char rec_rem[100];
    divide(rec_msg,generator,rec_rem);
    printf("Reciever remainder is:%s\n",rec_rem);
    int error = 0;
    for(int i=0;i<genLen-1;i++){
        if(rec_rem[i] == '1'){
            error = 1;
            break;
        }
    }
    if(error){
        printf("Data has been corrupted\n");
    }else{
        printf("Data is Valid\n");
    }
    return 0;
}
