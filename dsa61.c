#include <stdio.h>
#include <stdlib.h>

int main(){
    int n,m;
    scanf("%d %d",&n,&m);

    int **mat=(int**)malloc(n*sizeof(int*));
    for(int i=0;i<n;i++){
        mat[i]=(int*)calloc(n,sizeof(int));
    }

    for(int i=0;i<m;i++){
        int u,v;
        scanf("%d %d",&u,&v);
        mat[u][v]=1;
        mat[v][u]=1;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }

    for(int i=0;i<n;i++) free(mat[i]);
    free(mat);
    return 0;
}