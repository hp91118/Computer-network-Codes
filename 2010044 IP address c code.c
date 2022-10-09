
// roll no 2010044 expt 8 ip address

#include<stdio.h>
#include<string.h>

char findClass(char str[])
{
	char arr[5];
	int i=0;
	int ip=0,j=1;

	while(str[i]!='.')
	{
		arr[i]=str[i];
		i++;
	}
	i--;

	while(i>=0)
	{
		ip=ip+(str[i]-'0')*j;
		j=j*10;
		i--;
	}

	if(ip>=0 &&ip<=127)
	{
		printf("\nThe default subnet mask for given ip address : 255.0.0.0 ");
		return 'A';
	}

	else if(ip>=128 &&ip<=191)
	{
		printf("\nThe default subnet mask for given ip address : 255.255.0.0 ");
		return 'B';
	}

	else if(ip>=192 &&ip<=223)
	{	
		printf("\nThe default subnet mask for given ip address : 255.255.255.0 ");
		return 'C';
	}

	else if(ip>=224 &&ip<=239)
	{
		printf("\nThe ip address is from multicast category ");
		return 'D';
	}

	else
	{
		printf("\nThe ip address is from reserved category");
		return 'E';
	}
}

void separate(char str[],char ipClass)
{
   int k;
   char network[20]=" ",host[20]=" ";

   if(ipClass =='A')
   {
	    int i=0,j=0;
	    
	    	while(str[j]!='.')
	    		network[i++]=str[j++];
	    		i=0;
	   			 j++;
    		while(str[j]!='\0')
      			host[i++]=str[j++];

    printf("\nNetwork id             : %s",network);
    printf("\nHost address           : %s",host);
    printf("\nFirst address of block : %s.0.0.0",network);
    printf("\nLast address of block  : %s.255.255.255",network);
  }

   else if(ipClass =='B')
   {
    	int i=0,j=0,dotCount=0;

    		while(dotCount<2)
			{
			     network[i++]=str[j++];
			     if(str[j]=='.')
			     dotCount++;
    		}
		    i=0;
		    j++;
    
		    while(str[j]!='\0')
      			host[i++]=str[j++];

    printf("\nNetwork id             : %s",network);
    printf("\nHost address           : %s",host);
    printf("\nFirst address of block : %s.0.0.0",network);
    printf("\nLast address of block  : %s.255.255.255",network);
   }

   else if(ipClass =='C')
   {
    	int i=0,j=0,dotCount=0;

    		while(dotCount<3)
    		{
			     network[i++]=str[j++];
			     if(str[j]=='.')
			     dotCount++;
    		}
    		i=0;
   			j++;


    		while(str[j]!='\0')
     	 		host[i++]=str[j++];
      
    printf("\nNetwork id             : %s",network);
    printf("\nHost address           : %s",host);
    printf("\nFirst address of block : %s.0.0.0",network);
    printf("\nLast address of block  : %s.255.255.255",network);
   
   }

   else
		printf("\nHere this class ip address is not divided into network id and host id");
}

int main()
{
	char str[20];
	char ipClass;	  
	printf("\nEnter the ip address(dotted decimal form)   : ");
	gets(str);
	ipClass=findClass(str);
	printf("\nGiven ip address belongs to Class   : %c ",ipClass);
	printf("\n--------------------------------------------");
	separate(str,ipClass);
	return 0;
}


 

