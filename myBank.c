#include "myBank.h"
#include <stdio.h>
#define sa 901
#define arc 50
extern double arr[arc][2];

void open(double firstdeposit){
    int i=0;
    while(i<arc && arr[i][0]==1){
        i++;
    }
        if(i==arc) {
            printf("Faild open another account-to many accounts\n");
        }
        else if(firstdeposit<0){
         printf("Invalid Amount\n");
        }
    else
    {  
    arr[i][0]=1;
    arr[i][1]=firstdeposit;
    printf("New account number is: %d \n",sa+i);
    }
}
void balance(int account_number){
    if(account_number>900 && account_number<951){
    if(arr[account_number-sa][0]==0){
        printf("This account is closed\n");
    }
    else
    {
   printf("The balance of account number %d is: %0.2f\n",account_number,arr[account_number-sa][1]);
    }
    }
    else{
        printf("Invaild account number");
    }
}
void deposit(int account_number,double amount){
    if(account_number>900 && account_number<951){
     if(arr[account_number-sa][0]==0){
         printf("This account is closed\n");
     }
     else if(amount<0){
         printf("Cannot deposit a negative amount\n");
     }
     else {
     arr[account_number-sa][1]=arr[account_number-sa][1]+ amount;
     printf("The new balance is: %0.2f\n",arr[account_number-sa][1]);
     }
        }
         else{
        printf("Invaild account number");
    }
}
void withdrawal (int account_number,double amount){
    if(account_number>900 && account_number<951){
    if(arr[account_number-sa][0]==0){
         printf("This account is closed\n");
    }
    else if(arr[account_number-sa][1]<amount){
        printf("Cannot withdraw more than the balance\n");
    }
   // else if(amount<0){
     // printf("Cannot withdrawal a negative amount\n");
   // }
   else{ arr[account_number-sa][1]=arr[account_number-sa][1]- amount;
    printf("The new balance is: %0.2f\n",arr[account_number-sa][1]);
   }
    }
     else{
        printf("Invaild account number");
    }
}
void close(int account_number){
     if(account_number>900 && account_number<951){
    //check if need <50 accont number check
    if(arr[account_number-sa][0]==1){
        arr[account_number-sa][1]=0;
        arr[account_number-sa][0]=0;
        printf("Closed account number %d\n",account_number);
    }
    else
    {
        printf("This account is already closed\n");
    }
     }
      else{
        printf("Invaild account number");
    }
}
void interest (int interest){
    if(interest<0){
        printf("Invalid interest rate\n");
    }
     else
     {
       for(int j=0;j<arc;j++){
           if(arr[j][0]==1){
                arr[j][1]=((arr[j][1]*interest)/100)+arr[j][1];
           }
       }
     }  
    

}
void print(){
    
     for(int n=0;n<arc;n++){
           if(arr[n][0]==1){
        printf("The balance of account number %d is: %0.2f\n",n+sa,arr[n][1]);
}
     }
}
void endp(){
     for(int ed=0;ed<arc;ed++){
        arr[ed][1]=0;
        arr[ed][0]=0;
}    
}
void transaction(){
    printf("\nPlease choose a transaction type:\n O-Open Account\n B-Balance Inquiry\n D-Deposit\n W-Withdrawal\n C-Close Account\n I-Interest\n P-Print\n E-Exit\n");
}

