#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
    int data;
    struct Node* next;
};

struct Queue{
    struct Node* front;
    struct Node* rear;
};

void enqueue(struct Queue* q,int x){
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=x;
    temp->next=NULL;
    if(q->rear==NULL){
        q->front=q->rear=temp;
        return;
    }
    q->rear->next=temp;
    q->rear=temp;
}

int dequeue(struct Queue* q){
    if(q->front==NULL){
        return -1;
    }
    struct Node* temp=q->front;
    int val=temp->data;
    q->front=q->front->next;
    if(q->front==NULL){
        q->rear=NULL;
    }
    free(temp);
    return val;
}

int main(){
    struct Queue q;
    q.front=NULL;
    q.rear=NULL;
    int n;
    scanf("%d",&n);
    char op[20];
    for(int i=0;i<n;i++){
        scanf("%s",op);
        if(strcmp(op,"enqueue")==0){
            int x;
            scanf("%d",&x);
            enqueue(&q,x);
        } else {
            printf("%d\n",dequeue(&q));
        }
    }
    return 0;
}