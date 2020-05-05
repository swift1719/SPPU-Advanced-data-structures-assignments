#include<iostream>
#include<vector>
#include<limits>
using namespace std;
int minnode(int n,int key[],bool mst[])
{
      int minval=numeric_limits<int>::max();
      int min_index;
      for(int i=0;i<n;i++)
      {
            if(mst[i]==false &&  key[i]<minval)
            {
                  minval=key[i];
                  min_index=i;
            }
      }
      return min_index;
}
void findmin(int n,int city[10][10])
{
      int parent[n];
      int i,u,j;
      int key[n];
      bool mst[n];
      
      for(i=0;i<n;i++)
      {
            mst[i]=false;
            key[i]=numeric_limits<int>::max();
      }
      parent[0]=-1;
      key[0]=0;

      for(i=0;i<n-1;i++)
      {
            u=minnode(n,key,mst);
            mst[u]=true;
            for(j=0;j<n;j++)
            {
                  if(city[u][j] && mst[j]==false && city[u][j]<key[j])
                  {
                        key[j]=city[u][j];
                        parent[j]=u;
                  }
            }
      }
      int cost=0;
      for(i=0;i<n;i++)
      {
            cost+=city[parent[i]][i];
      }
      cout<<endl;
      cout<<"MINIMUM COST OF LANDLINE IS : "<<cost<<endl;

}

int main()
{
      int n,i,j,temp;
      cout<<"Enter number of cities : ";
      cin>>n;
      int city[10][10];
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
      findmin(n,city);
      return 0;
}
