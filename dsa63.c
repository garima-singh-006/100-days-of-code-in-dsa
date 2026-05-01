#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void dfs(int v,struct Node** adj,int *vis){
    vis[v]=1;
    printf("%d ",v);

    struct Node* temp=adj[v];
    while(temp){
        if(!vis[temp->data]){
            dfs(temp->data,adj,vis);
        }
        temp=temp->next;
    }
}

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

    dfs(s,adj,vis);

    free(vis);
    free(adj);
    return 0;
}