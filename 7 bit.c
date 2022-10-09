#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	long int n;
	int data[8],d,it=1,i,p1,p2,p4,loc,ch,r1,r2,r4,c1,c2,c4,check;
	printf("Enter 4 bit data :");
	scanf("%ld",&n);
	while(n>0)
	{
		d=n%10;
		n=n/10;
		if(it==1)
		data[3]=d;
		else if(it==2)
		data[5]=d;
		else if(it==3)
		data[6]=d;
		else
		data[7]=d;
		it++;
	}
	p1=data[3]+data[5]+data[7];
	if(p1%2==0)
	{
		data[1]=0;
	}
	else
	{
		data[1]=1;
	}
	p2=data[3]+data[6]+data[7];
	if(p2%2==0)
	{
		data[2]=0;
	}
	else
	{
		data[2]=1;
	}
	p4=data[5]+data[6]+data[7];
	if(p4%2==0)
	{
		data[4]=0;
	}
	else
	{
		data[4]=1;
	}
	printf("\nHamming at sender :");
	for(i=7;i>0;i--)
	{
		printf("%d",data[i]);
	}
	printf("\nPress y if u want to change bit");
	ch=getche();
	if(ch=='y')
	{
		printf("\nEnter loc to change : ");
		scanf("%d",&loc);
		if(data[loc]=1)
		{
			data[loc]=0;
			
		}
		else
		{
			data[loc]=1;
		}
	}
	printf("\ndata at receiver :");
	for(i=7;i>0;i--)
	{
		printf("%d",data[i]);
	}
	r1=data[1]+data[3]+data[5]+data[7];
	if(r1%2==0)
	{
		c1=0;
		
	}
	else
	{
		c1=1;
	}
	r2=data[2]+data[3]+data[6]+data[7];
	if(r2%2==0)
	{
		c2=0;
		
	}
	else
	{
		c2=1;
	}
	r4=data[4]+data[5]+data[6]+data[7];
	if(r4%2==0)
	{
		c4=0;
		
	}
	else
	{
		c4=1;
	}
	check=c4*4 + c2*2 +c1*1 ;
	printf("\ncheck : %d",check);
	if(check==0)
	{
		printf("\nNo error");
		printf("\nHamming at receiver :");
		for(i=7;i>0;i--)
		{
			printf("%d",data[i]);
		}
		
	}
	else
	{
		printf("\nWith error");
		if(data[check]==0)
		{
			data[check]=1;
			
		}
		else
		{
			data[check]=0;
		}
		printf("\nHamming at receiver :");
		for(i=7;i>0;i--)
		{
			printf("%d",data[i]);
		}
		
	}
	
	
	return 0;
	
}
