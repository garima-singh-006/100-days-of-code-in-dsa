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

int isMirror(struct Node* a,struct Node* b){
    if(a==NULL && b==NULL) return 1;
    if(a==NULL || b==NULL) return 0;
    if(a->data!=b->data) return 0;
    return isMirror(a->left,b->right) && isMirror(a->right,b->left);
}

int main(){
    int n;
    scanf("%d",&n);
    int *arr=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    if(n==0 || arr[0]==-1){
        printf("YES");
        return 0;
    }

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

    if(isMirror(nodes[0]->left,nodes[0]->right)) printf("YES");
    else printf("NO");

    free(arr);
    free(nodes);
    return 0;
}