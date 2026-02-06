#include<stdio.h>
#include<stdlib.h>
struct ListNode{
    int val;
    struct ListNode* next;
};
struct ListNode* CreateNode(int value){
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val=value;
    newNode->next=NULL;
    return newNode;
}
struct ListNode* InputLinkedlist(int n){
    struct ListNode dummy;
    dummy.next=NULL;
    struct ListNode* current=&dummy;
    int val;
    printf("enter element of linked list \n");
    for(int i=0;i<n;i++){
        scanf("%d",&val);
        struct ListNode* newNode =CreateNode(val);
        current->next=newNode;
        current=current->next;
    }
    return dummy.next;
}
void PrintLinkedList(struct ListNode* l){ 
    while(l!=NULL){
        printf(" %d ",l->val);
        if(l->next!=NULL){
            printf(" -> ");
        }
        l=l->next;
    }
    printf("\n");

}
struct ListNode* addsum(struct ListNode *l1,struct ListNode *l2){
    struct ListNode dummy;
    dummy.next=NULL;
    struct ListNode* current = &dummy;  
    int carry = 0;
    int val1,val2;
    while(l1!=NULL||l2!=NULL||carry!=0){
        if(l1!=NULL){
            val1=l1->val;
        }else{
            val1=0;
        }
        if(l2!=NULL){
            val2=l2->val;
        }else{
            val2=0;
        }
        int sum=val1+val2+carry;
        carry=sum/10;
        current->next=CreateNode(sum%10);
        current=current->next;
        if(l1!=NULL) l1=l1->next;
        if(l2!=NULL) l2=l2->next;
    }
    return dummy.next;
}
int main(){
    int n1,n2;
    printf("enter number element of linked list 1 \n");
    scanf("%d",&n1);
    printf("enter linked list 1 \n");
    struct ListNode* l1=InputLinkedlist(n1);
    printf("enter number element of linked list 2 \n");
    scanf("%d",&n2);
    printf("enter linked list 2 \n");
    struct ListNode* l2=InputLinkedlist(n2);
    printf("result: \n");
    PrintLinkedList(addsum(l1,l2));
    return 0;
  
}
