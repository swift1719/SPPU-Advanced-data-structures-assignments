#include<iostream>
#include<string.h>
using namespace std;
class node
{
      public:
            string label;
            int cnt;
            node*chap[10];
};
int main()
{
	cout<<"*********************"<<endl;
	int i,j,k;

	node *root=new node;

	cout<<"Enter book name: ";
	cin>>root->label;
	cout<<"Enter no. of chapters: ";
	cin>>root->cnt;
	cout<<"\t***Enter chapter names*** "<<endl;
	for(i=0;i<root->cnt;i++)
	{
		root->chap[i]=new node;
		cout<<"Chapter "<<i+1<<" :";
		cin>>root->chap[i]->label;
		cout<<"Enter no. of topics :";
		cin>>root->chap[i]->cnt;
		cout<<"\t**Enter topic names**"<<endl;
		for(j=0;j<root->chap[i]->cnt;j++)
		{
			root->chap[i]->chap[j]=new node;
			cout<<"\tTopic "<<j+1<<": ";
			cin>>root->chap[i]->chap[j]->label;
			cout<<"\t\tEnter no. of subtopics :";
			cin>>root->chap[i]->chap[j]->cnt;
			for(k=0;k<root->chap[i]->chap[j]->cnt;k++)
			{
				root->chap[i]->chap[j]->chap[k]=new node;
				cout<<"\t\tSub Topic "<<k+1<<": ";
				cin>>root->chap[i]->chap[j]->chap[k]->label;
			}
		}
	}


	cout<<endl<<"\t\tBOOK: "<<root->label<<endl;
	for(i=0;i<root->cnt;i++)
	{
		cout<<"Chapter "<<i+1<<" :";
		cout<<root->chap[i]->label<<endl;
		cout<<"\t**Topic names**"<<endl;
		for(j=0;j<root->chap[i]->cnt;j++)
		{
			cout<<"\tTopic "<<j+1<<": ";
			cout<<root->chap[i]->chap[j]->label<<endl;
			for(k=0;k<root->chap[i]->chap[j]->cnt;k++)
			{
				cout<<"\t\tSub Topic "<<k+1<<": ";
				cout<<root->chap[i]->chap[j]->chap[k]->label<<endl;
			}
		}
	}
return 0;
}
