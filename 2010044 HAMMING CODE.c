#include<stdio.h>
#include<conio.h>
int main()

{
	long int n;
	int i,d,it=1,data[12],loc,sum1,sum2,sum4,sum8,alter,r1,r2,r4,r8,c1,c2,c3,c4,check;
	printf("Enter data (7 bit) :");
	scanf("%ld",&n);
	while(n>0)
	{
		d=n%10;
		n=n/10;
		if(it==1)
			{data[3]=d;}
		else if(it==2)
			{data[5]=d;}
		else if(it==3)
			 {	data[6]=d; }
		else if(it==4)
	       {	data[7]=d ;       }
		else if(it==5)
			{data[9]=d;         }
		else if(it==6)
			{ data[10]=d; }
		else
		       {  data[11]=d;}
		it++;
	}
		printf("\n***Sender hamming code***");
		sum1=data[3]+data[5]+data[7]+data[9]+data[11];
		if(sum1%2==0)
			data[1]=0;
		 else
			data[1]=1;

		 sum2=data[3]+data[6]+data[7]+data[10]+data[11];
		if(sum2%2==0)
			data[2]=0;
		 else
			data[2]=1;


		 sum4=data[5]+data[6]+data[7];
		if(sum4%2==0)
			data[4]=0;
		 else
			data[4]=1;

		 sum8=data[9]+data[10]+data[11];
		if(sum8%2==0)
			data[8]=0;
		 else
			data[8]=1;

	      //	 printf("Sender hamming code")
		 {
			for(i=11;i>0;i--)
			printf("%d",data[i]);

		 }

		printf("\nDo you want to change bit press Y");
		alter=getche();
		if(alter=='y' || alter=='Y')
		     {
		       printf("\nEnter location= ",loc);
		       scanf("%d",&loc);

		       if(data[loc]==0)
		       data[loc] =1;
		       else
		       data[loc]=0;
		     }
		 printf("\nReceived data is= ") ;
		 for(i=11;i>0;i--)
		 {
		 printf("%d",data[i]);
		 }
		 r1=data[1]+data[3]+data[5]+data[7]+data[9]+data[11];
		 if(r1%2==0)
			{
			c1=0;
			}
		 else
			c1=1;
		 r2=data[2]+data[3]+data[6]+data[7]+data[10]+data[11];
		   if(r2%2==0)
			{
			c2=0;
			}
		 else
			c2=1;
		 r4=data[4]+data[5]+data[6]+data[7];
		    if(r4%2==0)
			{
			c3=0;
			}
		 else
			c3=1;
		 r8=data[8]+data[9]+data[10]+data[11];
		   if(r8%2==0)
			{
			c4=0;
			}
		 else
			c4=1;
		 check=c1*1+c2*2+c3*4+c4*8;
		 if(check==0)
		{ printf("\nNo error");
		 printf("\nHamming code is=");
		 for(i=11;i>0;i--)
		 printf("%d",data[i]); }
		 else
		{ printf("\nError at  position =%d",check);
		 printf("\nCorrected code is=") ;
		if(data[check]==0)
	       {	data[check]=1 ; }
		else
		data[check]=0;

		
		//printf("hamming code is") ;
		for(i=11;i>0;i--)
		{
		printf("%d",data[i]);
		 }
	  }
	  //final code




 getch();
 return 0;

 }
