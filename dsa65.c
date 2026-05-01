#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

int dfs(int v,int parent,struct Node** adj,int *vis){
    vis[v]=1;

    struct Node* temp=adj[v];
    while(temp){
        int u=temp->data;
        if(!vis[u]){
            if(dfs(u,v,adj,vis)) return 1;
        }
        else if(u!=parent){
            return 1;
        }
        temp=temp->next;
    }
    return 0;
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

    int *vis=(int*)calloc(n,sizeof(int));
    int ok=0;

    for(int i=0;i<n;i++){
        if(!vis[i]){
            if(dfs(i,-1,adj,vis)){
                ok=1;
                break;
            }
        }
    }

    if(ok) printf("YES");
    else printf("NO");

    free(vis);
    free(adj);
    return 0;
}