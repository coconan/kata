#include<iostream>

#define NODE_SUM 1000

using namespace std;

class Node{
public:
       int value;
       Node * left;
       Node * right;
};

int preorder[NODE_SUM];
bool construct;

void BST(Node* root,int left,int right)
{
     if(construct == false)return;
      
   
      int middle = left+1;
      
      while(middle < right && preorder[middle] < preorder[left])middle++;
      
      int temp = middle;
      while(temp < right && preorder[temp] >= preorder[left])temp++;
      
      if(temp!=right)
      {
           construct = false;
           return;
      }
    
      root->value = preorder[left];
      
      if(left+1 == middle)root->left = NULL;
      else
      {
          root->left = new Node();
          BST(root->left, left+1,middle);
      }   
      
      if(middle == right)root->right = NULL;
      else
      {
          root->right = new Node();
          BST(root->right, middle, right);
      }
     
}

void BSTMirror(Node* root,int left,int right)
{
     if(construct == false)return;
      
   
      int middle = left+1;
      
      while(middle < right && preorder[middle] >= preorder[left])middle++;
      
      int temp = middle;
      while(temp < right && preorder[temp] < preorder[left])temp++;
      
      if(temp!=right)
      {
           construct = false;
           return;
      }
    
      root->value = preorder[left];
      
      
      
      if(left+1 == middle)root->left = NULL;
      else
      {
          root->left = new Node();
          BSTMirror(root->left, left+1,middle);
      }   
      
      if(middle == right)root->right = NULL;
      else
      {
          root->right = new Node();
          BSTMirror(root->right, middle, right);
      }
     
}

void PrintPosterorder(Node* root)
{
     if(root == NULL) return;
     else
     {
         PrintPosterorder(root->left);
         PrintPosterorder(root->right);
         printf("%d ",root->value);
     }
} 

void Print(Node* root)
{
     PrintPosterorder(root->left);
     PrintPosterorder(root->right);
     printf("%d\n",root->value);
}

void dealloc(Node* root)
{
     if(root == NULL) return;
     else
     {
         dealloc(root->left);
         dealloc(root->right);
         delete root;
     }     
}

int main(void){
    int node_sum;
    Node* root = new Node();
    
    scanf("%d",&node_sum);
    for(int i=0;i<node_sum;i++)scanf("%d",preorder+i);

    construct = true;
    BST(root,0,node_sum);
    
    
    
    if(construct)
    {
         printf("YES\n");
         Print(root);
         dealloc(root);
    }
    else
    {
         dealloc(root->left);
         dealloc(root->right);
         
         construct = true;
         BSTMirror(root,0,node_sum);
         
         if(construct)
         {
             printf("YES\n");
             Print(root);
             dealloc(root);
         }
         else
         {
             dealloc(root);
             printf("NO\n");
         }
    }
    
    return 0;
}