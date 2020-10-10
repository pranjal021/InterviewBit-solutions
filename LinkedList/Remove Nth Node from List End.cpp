
//problem :   Remove Nth Node from List End

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    int len =0;
    ListNode* temp=A;
    
    while(temp){
        len++;
        temp=temp->next;
    }
    
    if(B>=len){
        return A->next;
    }else{
        int diff = len-B;
        ListNode* prev=NULL;
        ListNode* curr=A;
        while(diff--){
            prev=curr;
            curr=curr->next;
        }
        prev->next=curr->next;
       // delete(curr);
        return A;
    }
}