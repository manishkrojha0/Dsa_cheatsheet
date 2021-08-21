#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left, *right;
};
struct Node* newNode(int data)
{
    struct Node* node = new Node;
    node->key = data;
    node->left = node->right = NULL;
    return node;
}

void traversal(Node *root,int level,map<int,vector<int>> &m)
{
    if(root==NULL) return;
    m[level].push_back(root->data);
    traversal(root->left,level+1,m);
    traversal(root->right,level,m);
}
vector<int> diagonal(Node *root)
{
   // your code here
   vector<int> v;
   map<int,vector<int>> m;
   traversal(root,0,m);
   for(auto it:m)
   {
       for(int i=0;i<it.second.size();i++)
       {
           v.push_back(it.second[i]);
       }
   }
   return v;
}
void print(Node *root)
{
  vector<int> v=diagonal(root);
  for(int i=0;i<v.size();i++)
  {
    cout<<v[i]<<endl;
  }
}
  
int main()
{
  
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    root->right->right->right = newNode(9); 
  
  
}
