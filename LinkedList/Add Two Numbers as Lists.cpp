/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
    
    int c = 0; ListNode* res = new ListNode(0);
    ListNode* head = res;
    while(A || B || c){
        int sum = (A ? A->val : 0) + (B ? B->val : 0) + c;
        c = floor(sum/10);
        head->next = new ListNode(sum%10);
        A = A ? A->next : NULL;
        B = B ? B->next : NULL;
        head = head->next;
        }
      return res->next;  
 
}