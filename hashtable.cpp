#include<bits/stdc++.h>
using namespace std;
#define n 10

class hasht
{
  public:
  int hashtable[100],t[100];
  hasht()
  {
    for(int i=0;i<100;i++)
    {
      t[i]=0;
    }
  }
  void display();
  void insert(int );
  void find(int );
  void loadFactor(int);
};
void hasht::loadFactor(int c)
{
  float l=(float)c/10;
  cout<<"Load Factor: "<<l<<endl;
  if(l>0.7)
  {
    cout<<"Load Factor greater than 0.7  ........."<<"\n\t Increase table size\n";
  }

}
void hasht::display()
{
  cout<<" Sr No."<<"       "<<"Telephone No."<<endl;
  for(int i=0;i<100;i++)
  {
    if(t[i]==1)
    {
      cout<<" "<<i<<"       "<<hashtable[i]<<endl;
    }
  }
}
void hasht::insert(int x)
{
  int loc;
  loc=x%n;
  int u=7-(x%7);
  for(int i=0;i<n;i++)
  {
    loc=(loc+i*u)%n;
    if(t[loc]==0)
    {
      t[loc]=1;
      hashtable[loc]=x;
      break;
    }
  }
  
}

void hasht:: find(int x)
{
  int loc,flag=0;
  loc=x%n;
  int u=7-(x%7);
  for(int i=0;i<n;i++)
  {
    loc=(loc+i*u)%n;
    if(t[loc]==1 && hashtable[loc]==x)
    {
      flag=1;
      cout<<x<<" found at cell "<<loc<<endl;
      break;
    }
    
  }
  if(flag==0)
  {
    cout<<" Not Found"<<endl;
  }
}

int main()
{
  hasht t;
  int d,c;
  int ch;
  c=0;
  for(;;)
  {
    cout<<"Press:\n1.to insert a record \n.2.to display a record\n3.to find a record \n4.to increase the size of the array\n5.to exit \n";
    cin>>ch;
    switch(ch)
    {
      case 1: cout<<"Enter a name and telephone no. :";
              cin>>d;
              t.insert(d);
              c++;
              t.loadFactor(c);
        break;
      case 2: cout<<"\t\t***RECORDS***\n";
              t.display();
        break;
      case 3: cout<<"Enter a telephone no. to search: ";
              cin>>d;
              t.find(d);
        break;
      case 4:
        return 0;
        break;
      default:
        cout<<"Invalid choice "<<endl;
    }
  }
  return 0;
}
