/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::swapPairs(ListNode* A) {
    ListNode* dummy = new ListNode(-1);
    ListNode* tail = dummy;
    tail->next = A;
    while(A && A->next){
        ListNode* nxtptr = A->next->next;
        tail->next= A->next;
        (A->next)->next = A;
        tail = A;
        tail->next = nxtptr;
        A= nxtptr;
    }
    A = dummy->next;
    delete dummy;
    return A;
}