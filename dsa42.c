#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    scanf("%d",&n);
    int *q=(int*)malloc(n*sizeof(int));
    int *s=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++) scanf("%d",&q[i]);
    int top=-1;
    for(int i=0;i<n;i++) s[++top]=q[i];
    for(int i=0;i<n;i++) q[i]=s[top--];
    for(int i=0;i<n;i++) printf("%d ",q[i]);
    free(q);
    free(s);
    return 0;
}