/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
ListNode* sorting(ListNode* f,ListNode* s){
    if(s==NULL)return f;
    if(f==NULL)return s;
    ListNode* h;
    if(f->val < s->val){
        h = f;
        h->next = sorting(f->next,s);
    }else{
        h = s;
        h->next = sorting(f,s->next);
    }
    return h;
}
 
ListNode* findMid(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head->next->next;
    while(fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
  
ListNode* sortt(ListNode* head){
    if(head==NULL || head->next ==NULL)return head;
    ListNode* mid = findMid(head);
    ListNode* second = sortt(mid->next);
    mid->next=NULL;
    ListNode* first = sortt(head);
    return sorting(first,second);
}
 
 ListNode* Solution::sortList(ListNode* A) {
    return sortt(A);
}