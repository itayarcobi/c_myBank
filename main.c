#include "myBank.h"
#include <stdio.h>
extern double arr[50][2];

int main(){
for(int a=0;a<50;a++){
arr[a][0]=0;
arr[a][1]=0;
}
int t=1;
while(t==1){
transaction();
char usertr;
scanf(" %c",&usertr);
if(usertr=='O'){
double userfamdep=0;
printf("Please enter amount for deposit: ");
if(scanf(" %lf",&userfamdep)!=1){
        printf("Failed to read the amount\n");
       // double userfamdep=0;
}
else
{
open(userfamdep);
}
}
else if(usertr=='B'){
int useracnum=0;
printf("Please enter account number: ");
if(scanf(" %d",&useracnum)!=1){
        printf("Failed to read the account number\n");
}
else
{
balance(useracnum);
}
}
else if(usertr=='D'){
int useracnum=0;
printf("Please enter account number: ");
if(scanf(" %d",&useracnum)!=1){
printf("Failed to read the account number\n");
}
else
{
    if(useracnum>900 && useracnum<951){
        if(arr[useracnum-901][0]==0){
            printf("This account is closed\n");
        }
        else{
double userdep=0;
printf("Please enter the amount to deposit: ");
if(scanf(" %lf",&userdep)!=1){
printf("Failed to read the amount\n");
}
else{
deposit(useracnum,userdep);
}
        }
}  else
        {
            printf("Invalid account number\n");
        }  
}
}
else if(usertr=='W'){
int useracnum=0;
printf("Please enter account number: ");
if(scanf(" %d",&useracnum)!=1){
        printf("Failed to read the account number\n");
}
else
{
    if(useracnum>900 && useracnum<951){
        if(arr[useracnum-901][0]==0){
            printf("This account is closed\n");
        }
        else{
printf("Please enter the amount to withdraw: ");
double userwith=0;
if(scanf(" %lf",&userwith)!=1){
printf("Failed to read the withdrawal number\n");
}
else{
withdrawal(useracnum,userwith);
}
}
    }
    else
    {  
            printf("Invalid account number\n"); 
}
    }
    
}
else if(usertr=='C'){
int useracnum=0;
printf("Please enter account number: ");
if(scanf(" %d",&useracnum)!=1){
        printf("Failed to read the account number\n");
}
else
{
close(useracnum);
}
}
else if(usertr=='I'){
int userinter=0;
printf("Please enter interest rate: ");
//make sure is int the intereset
if(scanf(" %d",&userinter)!=1){
        printf("Failed to read the interest rate\n");
}
else
{
interest(userinter);
}
}
else if(usertr=='P'){
print();
}
else if(usertr=='E'){
endp();
t=0;
}
else
{
    printf("Invalid transaction type\n");
}



}
return 0;
}