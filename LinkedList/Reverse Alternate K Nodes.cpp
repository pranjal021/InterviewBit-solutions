/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
ListNode* reverseK(ListNode* head,int k){
    ListNode* curr = head;
    ListNode* prev = NULL;
    ListNode* n;
    int count = 0;
    
    while(count<k && curr!=NULL){
        n = curr->next;
        curr->next = prev;
        prev = curr;
        curr=n;
        count++;
    }
    if(head!=NULL){
        head->next = curr;
    }
    count = 0 ;
    while(curr!=NULL && count<k-1){
        curr = curr->next;
        count++;
    }
    if(curr!=NULL){
        curr->next = reverseK(curr->next,k);
    }
    return prev;
}
 
ListNode* Solution::solve(ListNode* A, int B) {
    return reverseK(A,B);
}