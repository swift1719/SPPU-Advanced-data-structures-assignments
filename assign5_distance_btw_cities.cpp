#include <bits/stdc++.h> 
using namespace std;

int minDistance(int dist[], bool sptSet[],int V) 
{ 
	int min = INT_MAX, min_index; 

	for (int v = 0; v < V; v++) 
		if (sptSet[v] == false && dist[v] <= min) 
			min = dist[v], min_index = v; 

	return min_index; 
} 

int printSolution(int dist[],int V,int src) 
{ 
    int dest;
    cout<<"Enter destination city  : ";
    cin>>dest;
	printf("source city \t Distance to destination\n"); 
	for (int i = 0; i < V; i++) 
    {
        if((dest-1)==i)
        {
            cout<<src+1<<"\t\t\t"<<dist[i];
        }
    } 
} 

void dijkstra(int graph[10][10], int src,int V) 
{ 
	int dist[V];  

	bool sptSet[V]; 

	
	for (int i = 0; i < V; i++) 
		dist[i] = INT_MAX, sptSet[i] = false; 
	
	dist[src] = 0; 

	
	for (int count = 0; count < V - 1; count++) { 
		int u = minDistance(dist, sptSet,V); 

		sptSet[u] = true; 
 
		for (int v = 0; v < V; v++)
			if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) 
				dist[v] = dist[u] + graph[u][v]; 
	} 

	
	printSolution(dist,V,src); 
} 
 
int main() 
{ 
	int city[10][10] ;
    int n,sc,i,j;
    cout<<"Enter number of cities: ";
    cin>>n;
    for(i=0;i<n;i++)
      {
            for(j=i;j<n;j++)
            {
                  cout<<"Enter distance between cities "<<i+1<<" and "<<j+1<<" : ";
                  if(i==j)
                  {
                        city[i][j]=0;
                        cout<<0<<endl;
                  }
                  else
                  {
                        cin>>city[i][j];
                        city[j][i]=city[i][j];
                  }
            }
            cout<<endl;
      }
      for(i=0;i<n;i++)
      {
            for(j=0;j<n;j++)
                  cout<<city[i][j]<<" ";
            cout<<endl;
      }

    cout<<"Enter source city: ";
    cin>>sc;
	dijkstra(city, sc-1,n); 

	return 0; 
} 
