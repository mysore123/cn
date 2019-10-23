#include<stdio.h>

void main()
{
int data[4];
int ham[7];
int rec[7];
int i,r3,r2,r1,p3,p2,p1;

printf("enter the data one by one:\n");
for(i=0;i<4;i++)
scanf("%d",&data[i]);

r1=(data[3]+data[2]+data[0])%2;
r2=(data[3]+data[1]+data[0])%2;
r3=(data[2]+data[1]+data[0])%2;
ham[0]=data[0];
ham[1]=data[1];
ham[2]=data[2];
ham[3]=r3;
ham[4]=data[3];
ham[5]=r2;
ham[6]=r1;
printf("the hamming code is:\n");
for(i=0;i<7;i++)
printf("%d",ham[i]);

printf("\nenter the recieved bits:\n");
for(i=0;i<7;i++)
scanf("%d",&rec[i]);

p3=(r3+rec[2]+rec[1]+rec[0])%2;
p2=(r2+rec[4]+rec[1]+rec[0])%2;
p1=(r1+rec[4]+rec[2]+rec[0])%2;

if(p3==0)
{
if(p2==0)
{
if(p1==0)
printf("no error");
else
{
rec[6] = (rec[6]+1)%2;
}
}
else
{
if(p1==0){
rec[5] = (rec[5]+1)%2;
}
else{
rec[4] = (rec[4]+1)%2;
}
}
}
else
{
if(p2==0)
{
if(p1==0){
rec[3] = (rec[3]+1)%2;
}
else{
rec[2] = (rec[2]+1)%2;
}
}
else
{
if(p1==0){
rec[1] = (rec[1]+1)%2;
}
else{
rec[0] = (rec[0]+1)%2;
}
}
}

printf("the correct code is:\n");
for(i=0;i<7;i++)
printf("%d",rec[i]);
return 0;
}

