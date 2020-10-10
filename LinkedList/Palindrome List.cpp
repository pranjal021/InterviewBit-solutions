//problem : Palindrome List

void reverseList(ListNode* &head){
    ListNode* curr=head;
    ListNode* prev=NULL;
    ListNode* n;
    while(curr){
        n=curr->next;
        curr->next = prev;
        prev=curr;
        curr=n;
    }
    head=prev;
    return;
}
 
bool compareList(ListNode* a,ListNode* b){
    while(a!=NULL && b!=NULL){
        if(a->val == b->val){
            a=a->next;
            b=b->next;
        }else{
            return false;
        }
    }
    if(a==NULL && b==NULL){
        return true;
    }
    return false;
}
 
int Solution::lPalin(ListNode* A) {
    ListNode* slow = A;
    ListNode* fast = A;
    ListNode* prev_slow = A;
    ListNode* second_list;
    ListNode* midNode=NULL;
    bool res = true;
    
    if(A!=NULL && A->next!=NULL){
        while(fast && fast->next){
            fast= fast->next->next;
            prev_slow = slow;
            slow=slow->next;
        }
        //for even ll, fast=NULL
        if(fast!=NULL){
            midNode = slow;
            slow=slow->next;
        }
        second_list = slow;
        prev_slow->next =  NULL;
        reverseList(second_list);
        res = compareList(A,second_list);
        reverseList(second_list);
        if(midNode!=NULL){
            prev_slow->next=midNode;
            midNode->next=second_list;
        }else{
            prev_slow->next=second_list;
        }
    }
    return res;
    
}