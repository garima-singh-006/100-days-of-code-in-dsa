#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* newNode(int data){
    struct Node* node=(struct Node*)malloc(sizeof(struct Node));
    node->data=data;
    node->next=NULL;
    return node;
}

void addEdge(struct Node** adj,int u,int v){
    struct Node* node=newNode(v);
    node->next=adj[u];
    adj[u]=node;

    node=newNode(u);
    node->next=adj[v];
    adj[v]=node;
}

int main(){
    int n,m;
    scanf("%d %d",&n,&m);

    struct Node** adj=(struct Node**)malloc(n*sizeof(struct Node*));
    for(int i=0;i<n;i++) adj[i]=NULL;

    for(int i=0;i<m;i++){
        int u,v;
        scanf("%d %d",&u,&v);
        addEdge(adj,u,v);
    }

    for(int i=0;i<n;i++){
        struct Node* temp=adj[i];
        printf("%d: ",i);
        while(temp){
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }

    return 0;
}