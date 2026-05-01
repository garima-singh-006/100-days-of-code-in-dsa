#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data){
    struct Node* node=(struct Node*)malloc(sizeof(struct Node));
    node->data=data;
    node->left=NULL;
    node->right=NULL;
    return node;
}

struct Node* insert(struct Node* root,int key){
    if(root==NULL) return newNode(key);
    if(key<root->data) root->left=insert(root->left,key);
    else root->right=insert(root->right,key);
    return root;
}

struct Node* lca(struct Node* root,int p,int q){
    if(root==NULL) return NULL;
    if(p<root->data && q<root->data) return lca(root->left,p,q);
    if(p>root->data && q>root->data) return lca(root->right,p,q);
    return root;
}

int main(){
    int n;
    scanf("%d",&n);
    struct Node* root=NULL;
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        root=insert(root,x);
    }
    int p,q;
    scanf("%d %d",&p,&q);
    struct Node* ans=lca(root,p,q);
    if(ans) printf("%d",ans->data);
    return 0;
}