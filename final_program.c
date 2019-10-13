#include<stdio.h>
#define INFINITY 9999
#define MAX 10

int stack[MAX], top=-1;
void push(int st[], int i);
int pop(int st[]);
int peek(int st[]);
void display(int st[]);
 
void dijkstra(int G[MAX][MAX],int n,int startnode,int endnode);
 
int main()
{
    int G[MAX][MAX],i,j,n,u,e;
    printf("Enter no. of vertices:");
    scanf("%d",&n);
    printf("\nEnter the adjacency matrix:\n");
    
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&G[i][j]);
    
    printf("\nEnter the starting node:");
    scanf("%d",&u);
    printf("\nEnter the end node:");
    scanf("%d",&e);
    dijkstra(G,n,u,e);
	display(stack);
    return 0;
}

void push(int st[], int val) {
if(top==MAX-1)
printf("\n Stack Overflow");
else
{
top++;
st[top] = val;
}
}

int pop(int st[]) {
int val;
if(top==-1) {
printf("\n Stack Underflow");
return -1;
}
else {
val = st[top];
top--;
return val;
}
}

int peek(int st[]) {
if(top==-1) {printf("\n Staqck is empty");
return -1;
}
else
return st[top];
}
void display(int st[]) {
if(top==-1)
printf("\n Stack is empty");
else {
for(int i=top;i>-1;i--) {
printf("\n %d",st[i]);
}
}
}
 
void dijkstra(int G[MAX][MAX],int n,int startnode,int endnode)
{
 
    int cost[MAX][MAX],distance[MAX],pred[MAX];
    int visited[MAX],count,mindistance,nextnode,i,j;
    
    //pred[] stores the predecessor of each node
    //count gives the number of nodes seen so far
    //create the cost matrix
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(G[i][j]==0)
                cost[i][j]=INFINITY;
            else
                cost[i][j]=G[i][j];
    
    //initialize pred[],distance[] and visited[]
    for(i=0;i<n;i++)
    {
        distance[i]=cost[startnode][i];
        pred[i]=startnode;
        visited[i]=0;
    }
    
    distance[startnode]=0;
    visited[startnode]=1;
    count=1;
    
    while(count<n-1)
    {
        mindistance=INFINITY;
        
        //nextnode gives the node at minimum distance
        for(i=0;i<n;i++)
            if(distance[i]<mindistance && visited[i]==0)
            {
                mindistance=distance[i];
                nextnode=i;
            }
            
            //check if a better path exists through nextnode            
            visited[nextnode]=1;
            for(i=0;i<n;i++)
                if(visited[i]==0)
                    if(mindistance+cost[nextnode][i]<distance[i])
                    {
                        distance[i]=mindistance+cost[nextnode][i];
                        pred[i]=nextnode;
                    }
        count++;
    }
 
    //print the path and distance of each node
    for(i=0;i<n;i++)
        if(i!=startnode && i==endnode)
        {
            printf("\nDistance of node %d = %d",i,distance[i]);
//            printf("\nPath = %c",i+65);
		push(stack, i);
            j=i;
            do
            {
                j=pred[j];
               // printf(" <- %c",j+65);
		push(stack, j);
            }while(j!=startnode);
	}
}
