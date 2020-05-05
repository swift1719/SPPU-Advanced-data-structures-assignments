#include<bits/stdc++.h>
using namespace std;
struct Node
{
    char ch;
    int freq;
    Node* left ,*right;
};
struct comp
{
    bool operator()(Node* l,Node* r)
    {
        return l->freq > r->freq;
    }
};


void encode(Node* root,string enc,unordered_map<char ,string> &huff)
{
    if(root==NULL)
    {
        return;
    }
    if(!root->left && !root->right)
    {
        huff[root->ch]=enc;
    }

    encode(root->left,enc+"0",huff);
    encode(root->right,enc+"1",huff);
}
Node* getNode(char ch,int freq,Node* left,Node* right)
{
    Node* root;
    root=new Node;
    root->ch=ch;
    root->freq=freq;
    root->left=left;
    root->right=right;
    return root;
}
void decode(Node* root,int &index,string enc)
{
    if(root==nullptr)
    {
        return;
    }
    if(!root->left && !root->right)
    {
        cout<<root->ch;
        return;
    }
    index++;
    if(enc[index]=='0')
    {
        decode(root->left,index,enc);
    }
    else
    {
        decode(root->right,index,enc);
    }  
}
void huffmancode(string s)
{
    unordered_map<char,int>fr;
    for(char ch:s)
    {
        fr[ch]++;
    }
    priority_queue<Node*,vector<Node*>,comp>pq;

    for(auto pair:fr)
    {
        pq.push(getNode(pair.first,pair.second,nullptr,nullptr));
    }

    while(pq.size()!=1)
    {
        Node *left=pq.top();
        pq.pop();
        Node *right=pq.top();
        pq.pop();

        int sum=left->freq+right->freq;
        pq.push(getNode('\0',sum,left,right));

    }
    Node *root=pq.top();

    unordered_map<char,string>huffman;

    encode(root,"",huffman);
    cout<<"Huffman codes: "<<endl;
    for(auto pair:huffman)
    {
        cout<<pair.first<<" : "<<pair.second<<endl;
    }
    string enc="";
    cout<<"Original string : "<<s<<endl;
    for(char ch:s)
    {
        enc+=huffman[ch];
    }
    cout<<"Encoded string : "<<enc<<endl;
    int index=-1;
    cout<<"Decoded string : ";
    while (index < (int)enc.size()-2)
    {
        decode(root,index,enc);
    }
}


int main()
{
    string a;
    cout<<"Enter a sentence : ";
    cin>>a;
    huffmancode(a);
    return 0;
}