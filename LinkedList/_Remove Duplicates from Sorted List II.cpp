
//problem :  Remove Duplicates from Sorted List II

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    if(A==NULL)return A;
    ListNode* curr=A;
    ListNode* prev=NULL;
    ListNode* n=curr->next;
    bool duplicate = false;
    while(n!=NULL){
        if(curr->val == n->val){
            duplicate=true;
            n=n->next;
            if(n==NULL){
                if(prev==NULL) A=n;
                else
                prev->next = n;
            }
        }else{
            if(duplicate){
                duplicate = false;
                if(prev == NULL)
                    A = n;
                else
                    prev->next = n;
                
                curr = n;
                n = n->next;
            }else{
                prev = curr;
                curr = n;
                n = n->next;
            }
        }
    }
    return A;
}