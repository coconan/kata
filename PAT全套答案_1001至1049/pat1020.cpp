#include<stdio.h>
#include<stdlib.h>
#include<queue>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
vector<int> myrint;
struct node{
	int data;
	node *left;
	node *right;
};
queue<node *> result;

node * creatTree(int a[],int b[],int n){
	if(n<=0) return NULL;
	node * root = (node *)malloc(sizeof(node));
	root->data = a[n-1];
	root->left=NULL;
	root->right= NULL;
	int i;
	for(i=0;i<n;i++)
		if(b[i]==a[n-1]) break;
	root->left = creatTree(a,b,i);
	root->right = creatTree(a+i,b+i+1,n-i-1);
	return root;
}

void levelPrint(node * root){
	if(root!=NULL) result.push(root);
	while(!result.empty()){
		node * temp = result.front();
		if(temp->left!=NULL) result.push(temp->left);
		if(temp->right!=NULL) result.push(temp->right);
		myrint.push_back(temp->data);
		result.pop();
	}
}

int main(void){
	int a[32],b[32];
	int n,i,j;
	while(scanf("%d",&n)!=EOF){
		myrint.clear();
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(i=0;i<n;i++)
			scanf("%d",&b[i]);
		node * root = creatTree(a,b,n);
		levelPrint(root);
		for(i=0;i<myrint.size();i++)
			printf(i==myrint.size()-1?"%d\n":"%d ",myrint[i]);
	}
	

	return 0;
}