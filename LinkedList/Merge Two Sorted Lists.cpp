
//problem :   Merge Two Sorted Lists

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    ListNode* head=NULL;
  
    ListNode* tail=NULL;
    while(A!=NULL && B!=NULL){
        if(A->val <= B->val){
        if(head==NULL){
            head=tail=A;
        }else{
            tail->next=A;
            tail=tail->next;
        }
        A=A->next;
    }else{
        if(head==NULL){
            head=tail=B;
        }else{
            tail->next=B;
            tail=tail->next;
        }
        B=B->next;
    }
    }
    
    if(A){
        tail->next=A;
    }
    if(B){
        tail->next=B;
    }
    return head;
}