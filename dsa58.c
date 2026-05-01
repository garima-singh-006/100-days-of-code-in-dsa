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

int search(int inorder[],int start,int end,int val){
    for(int i=start;i<=end;i++){
        if(inorder[i]==val) return i;
    }
    return -1;
}

struct Node* build(int preorder[],int inorder[],int inStart,int inEnd,int* preIndex){
    if(inStart>inEnd) return NULL;

    struct Node* root=newNode(preorder[*preIndex]);
    (*preIndex)++;

    if(inStart==inEnd) return root;

    int inIndex=search(inorder,inStart,inEnd,root->data);

    root->left=build(preorder,inorder,inStart,inIndex-1,preIndex);
    root->right=build(preorder,inorder,inIndex+1,inEnd,preIndex);

    return root;
}

void postorder(struct Node* root){
    if(root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}

int main(){
    int n;
    scanf("%d",&n);

    int *pre=(int*)malloc(n*sizeof(int));
    int *in=(int*)malloc(n*sizeof(int));

    for(int i=0;i<n;i++) scanf("%d",&pre[i]);
    for(int i=0;i<n;i++) scanf("%d",&in[i]);

    int preIndex=0;
    struct Node* root=build(pre,in,0,n-1,&preIndex);

    postorder(root);

    free(pre);
    free(in);
    return 0;
}