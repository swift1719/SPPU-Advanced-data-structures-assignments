#include<bits/stdc++.h>
using namespace std;

class graph
{
    int N;
    list<int>*l;
public:
    graph(int n)
    {
        this->N=n;
        l=new list<int>[N];
    }
    void check_adj(int v,bool visit[],stack<int>&St);
    void topological_sort();
    void add_edge(int a,int b);
};
void graph::add_edge(int a,int b)
{
    l[a].push_back(b);
}
void graph::check_adj(int v,bool visit[],stack<int>&St)
{
    visit[v]=true;
    list<int>::iterator i;
    for(i=l[v].begin();i!=l[v].end();++i)
    {
        if(!visit[*i])
        {
            check_adj(*i,visit,St);
        }
    }
    St.push(v);
}
void graph::topological_sort()
{
    bool visit[N];
    for(int i=0;i<N;i++)
        visit[i]=false;
    stack<int>St;

    for(int i=0;i<N;i++)
    {
        if(!visit[i])
        {
            check_adj(i,visit,St);
        }
    }
    while (!St.empty())
    {
        cout<<St.top()<<" ";
        St.pop();
    }
}
int main() 
{ 
	int n,a,b;
	cout<<"Enter no of vertices: ";
	cin>>n;
	graph g(n);
	for(int i=0;i<n;i++)
	{	
		cout<<"Enter edges : ";
		cin>>a>>b;
		g.add_edge(a,b);
	}

	cout << "Topological Sort of the given graph \n"; 
	g.topological_sort();

	return 0; 
}