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

struct Node* lca(struct Node* root,int p,int q){
    if(root==NULL) return NULL;
    if(root->data==p || root->data==q) return root;
    struct Node* left=lca(root->left,p,q);
    struct Node* right=lca(root->right,p,q);
    if(left && right) return root;
    return left?left:right;
}

int main(){
    int n;
    scanf("%d",&n);
    int *arr=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    if(n==0 || arr[0]==-1) return 0;

    struct Node** nodes=(struct Node**)malloc(n*sizeof(struct Node*));
    for(int i=0;i<n;i++){
        if(arr[i]==-1) nodes[i]=NULL;
        else nodes[i]=newNode(arr[i]);
    }

    for(int i=0;i<n;i++){
        if(nodes[i]!=NULL){
            int l=2*i+1;
            int r=2*i+2;
            if(l<n) nodes[i]->left=nodes[l];
            if(r<n) nodes[i]->right=nodes[r];
        }
    }

    int p,q;
    scanf("%d %d",&p,&q);
    struct Node* ans=lca(nodes[0],p,q);
    if(ans) printf("%d",ans->data);

    free(arr);
    free(nodes);
    return 0;
}