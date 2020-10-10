
// problem : Remove Duplicates from Sorted List

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    ListNode* curr=A;
    if(curr==NULL)return NULL;
    ListNode* temp;
    
    while(curr->next!=NULL){
        if(curr->val == curr->next->val){
            temp=curr->next->next;
            delete(curr->next);
            curr->next=temp;
        }else{
            curr=curr->next;
        }
    }
    return A;
}