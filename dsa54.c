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

    struct Node** q=(struct Node**)malloc(n*sizeof(struct Node*));
    int front=0,rear=0;
    q[rear++]=nodes[0];

    int leftToRight=1;

    while(front<rear){
        int size=rear-front;
        int *level=(int*)malloc(size*sizeof(int));
        for(int i=0;i<size;i++){
            struct Node* temp=q[front++];
            int idx=leftToRight?i:(size-1-i);
            level[idx]=temp->data;
            if(temp->left) q[rear++]=temp->left;
            if(temp->right) q[rear++]=temp->right;
        }
        for(int i=0;i<size;i++) printf("%d ",level[i]);
        free(level);
        leftToRight=!leftToRight;
    }

    free(arr);
    free(nodes);
    free(q);
    return 0;
}