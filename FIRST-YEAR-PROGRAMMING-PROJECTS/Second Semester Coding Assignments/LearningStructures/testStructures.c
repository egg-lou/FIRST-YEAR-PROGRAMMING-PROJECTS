#include<stdio.h>
#include<conio.h>
void main()
{
struct myStruct
{
int a, b;
};
struct myStruct myArray[5];
int i;
for(i=0;i<5;i++)
{
myArray[i].a=i;
myArray[i].b=5-i;
}
for(i=0;i<5;i++)
{
printf("%d %d %d\n",i, myArray[i].a,myArray[i].b);
}
getch();
}