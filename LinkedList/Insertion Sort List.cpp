/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
ListNode* sorting(ListNode* head){
    if(head==NULL || head->next ==NULL)return head;
    ListNode* h = sorting(head->next);
    if(head->val <= h->val){
        head->next = h;
        return head;
    }
    ListNode* node = h;
    while(node->next && head->val > node->next->val){
        node = node->next;
    }
    head->next = node->next;
    node->next = head;
    return h;
}
 
ListNode* Solution::insertionSortList(ListNode* A) {
    ListNode* ans = sorting(A);
    return ans;
}