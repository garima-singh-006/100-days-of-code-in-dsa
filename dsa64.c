#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

int main(){
    int n,m;
    scanf("%d %d",&n,&m);

    struct Node** adj=(struct Node**)malloc(n*sizeof(struct Node*));
    for(int i=0;i<n;i++) adj[i]=NULL;

    for(int i=0;i<m;i++){
        int u,v;
        scanf("%d %d",&u,&v);

        struct Node* node=(struct Node*)malloc(sizeof(struct Node));
        node->data=v;
        node->next=adj[u];
        adj[u]=node;

        node=(struct Node*)malloc(sizeof(struct Node));
        node->data=u;
        node->next=adj[v];
        adj[v]=node;
    }

    int s;
    scanf("%d",&s);

    int *vis=(int*)calloc(n,sizeof(int));
    int *q=(int*)malloc(n*sizeof(int));
    int front=0,rear=0;

    q[rear++]=s;
    vis[s]=1;

    while(front<rear){
        int v=q[front++];
        printf("%d ",v);

        struct Node* temp=adj[v];
        while(temp){
            if(!vis[temp->data]){
                vis[temp->data]=1;
                q[rear++]=temp->data;
            }
            temp=temp->next;
        }
    }

    free(vis);
    free(q);
    free(adj);
    return 0;
}