#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    int hd;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data){
    struct Node* node=(struct Node*)malloc(sizeof(struct Node));
    node->data=data;
    node->hd=0;
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
    nodes[0]->hd=0;
    q[rear++]=nodes[0];

    int min=0,max=0;

    while(front<rear){
        struct Node* temp=q[front++];
        if(temp->hd<min) min=temp->hd;
        if(temp->hd>max) max=temp->hd;
        if(temp->left){
            temp->left->hd=temp->hd-1;
            q[rear++]=temp->left;
        }
        if(temp->right){
            temp->right->hd=temp->hd+1;
            q[rear++]=temp->right;
        }
    }

    for(int i=min;i<=max;i++){
        front=0;
        rear=0;
        nodes[0]->hd=0;
        q[rear++]=nodes[0];
        while(front<rear){
            struct Node* temp=q[front++];
            if(temp->hd==i) printf("%d ",temp->data);
            if(temp->left){
                temp->left->hd=temp->hd-1;
                q[rear++]=temp->left;
            }
            if(temp->right){
                temp->right->hd=temp->hd+1;
                q[rear++]=temp->right;
            }
        }
        printf("\n");
    }

    free(arr);
    free(nodes);
    free(q);
    return 0;
}