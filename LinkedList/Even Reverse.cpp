/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* reverse(ListNode* head)
{
    ListNode* prev = NULL;
    ListNode* next = NULL;
    ListNode* curr = head;
 
    while(curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
ListNode* Solution::solve(ListNode* A) {
 
if(A == NULL || A->next == NULL)    return A;
 
ListNode* odd = A;
ListNode* oddhead = A;
ListNode* even = A->next;
ListNode* evenhead = even;
int cnt = 0;
ListNode* curr = even->next;
while(curr)
{
    cnt++;
    if(cnt%2 == 0)
    {
        even->next = curr;
        even = even->next;
    }
    else
    {
        odd->next = curr;
        odd = odd->next;
    }
    curr = curr->next;
}
if(even)    even->next = NULL;
if(odd)     odd->next = NULL;
 
ListNode* revhead = reverse(evenhead);
ListNode* head = oddhead;
curr = oddhead;
int f = 1;
while(curr)
{
    if(f)
    {
        oddhead = oddhead->next;
        curr->next = revhead;
        curr = curr->next;
    }
    else
    {
        revhead = revhead->next;
        curr->next = oddhead;
        curr = curr->next;
    }
    f ^= 1;
    
}
return head;
}