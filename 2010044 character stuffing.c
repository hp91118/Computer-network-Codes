#include<stdio.h>
#include<string.h>
void main()
{
	char a[20],b[20];
	char c[20],d[20];
	char s,x,e;
	int len,i,len1=0,j=1,len2,k;
	printf("Enter the message :");
	gets(a);
	printf("\nEnter the starting character :");
	s=getche();
	printf("\nEnter the esc character :");
	x=getche();
	printf("\nEnter the ending character :");
	e=getche();
    
	b[0]=s;
    len=strlen(a);
      for(i=0;i<=len;i++)
    {
    	if(a[i]==s)
    	{
		  b[j]=x;
		  j++;
		  b[j]=a[i];
    	 
        }
        else if(a[i]==e)
        {
        	b[j]=x;
        	j++;
        	b[j]=a[i];
		}
		else
		{
			b[j]=a[i];
		}
		j++;
	}
	c[0]=e;         //shxello e slash 0   hello
	c[1]='\0';
	strcat(b,c);
	printf("\nMessage after stuffing is  : ");
	printf("%s\n",b);
  
  
  
  len1=strlen(b);
  len2=len1-1;
  j=0;
  printf("\nDestuffed message is         : ");
  for(i=1;i<len2;i++)
  {
  	if(b[i]==x)             //leaving starting and end ch
     {
     	i++;
     }  	
	 d[j]=b[i];
	 printf("%c",d[j]);
	 }
}
  
