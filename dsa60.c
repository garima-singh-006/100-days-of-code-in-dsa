#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    scanf("%d",&n);
    int *arr=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);

    int ok=1;

    for(int i=0;i<n;i++){
        int l=2*i+1;
        int r=2*i+2;

        if(l<n && arr[i]>arr[l]){
            ok=0;
            break;
        }
        if(r<n && arr[i]>arr[r]){
            ok=0;
            break;
        }
    }

    if(ok) printf("YES");
    else printf("NO");

    free(arr);
    return 0;
}