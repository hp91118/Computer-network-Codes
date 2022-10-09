//DIJIKSTRA ALGO
//2010044

#include<stdio.h>
#define INFINITY 1000000
#define MAX 10
int dist[MAX][MAX];
int path[20]={0};
int n;
int main()
{
	struct state
	{
		int predecessor;
		int length;
		enum{permanent,tentative}label;
	}
	state[MAX];
	struct state *p;
	int i,j,s,t,k,min;
	printf("\nEnter the number of nodes :");
	scanf("%d",&n);
	printf("\nEnter the distance between corresponding nodes :");
	printf("\nNote :\n1.Distance from i to j and j to i is same \n2.If there is no direct link then take distance as 0");
	for(i=0;i<n;i++)            //all distances
	{
		for(j=0;j<n;j++)
		{                                       
			if(i==j)               //i to j is distance of nodes
			{
				dist[i][j]=0;
			}
			else
			{
				printf("\nEnetr the distance between %d node to %d node:",i,j);
				scanf("%d",&dist[i][j]);
			}
		}
	}
	
	printf("\nEnetr the starting node:");
	scanf("%d",&s);
	printf("\nEnter the destination node:");
	scanf("%d",&t);
	
	for(p=&state[0];p<&state[n];p++)
	{
		p->predecessor=-1;              //initially no predecessor
		p->length=INFINITY;             //distance is unknown consider max
		p->label=tentative;            
	}
	state[t].length=0;
	state[t].label=permanent;             //searching from destination
	k=t;
	do
	{
	
		for(i=0;i<n;i++)                                                
		{                                                       // executed for all ngbr     
			if(dist[k][i]!=0 && state[i].label==tentative)    //direct link and tentative
			{
				if(state[k].length+dist[k][i]<state[i].length)         
				{
				    state[i].predecessor=k;                          //update prdc and distance
					state[i].length=state[k].length+dist[k][i];	      //
				}
			}
		}
		k=0;min=INFINITY;
		for(i=0;i<n;i++)
		{
			if(state[i].length<min && state[i].label==tentative)
			{
				min=state[i].length;
				k=i;
			}
			state[k].label=permanent;
		}
    }while(k!=s);           //prd and dist decided
    i=0,k=s;
    do
    {                                  //for printing path
    	path[i]=k;
    	printf("%d-->",path[i]);
      	k=state[k].predecessor;
    }while(k>=0);
	return 0;
    
}
