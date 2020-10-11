/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
ListNode* reverseNode(ListNode* start){
    ListNode* curr=start;
    ListNode* n = NULL;
    ListNode* prev = NULL;
    while(curr){
        n = curr->next;
        curr->next = prev;
        prev = curr;
        curr = n;
    }
    return prev;
} 
 
ListNode* Solution::reverseBetween(ListNode* A, int B, int C) {
  //  if(A==NULL || A->next == NULL)return A;
    if(B==C)return A;
    ListNode* start = NULL;
    ListNode* end = NULL;
    ListNode* n = NULL;
    ListNode* prev = NULL;
    
    int i=1;
    ListNode* curr=A;
    while(i<=C && curr){
        if(i<B){
            prev = curr;
        }
        if(i==B){
            start = curr;
        }
        if(i==C){
            end = curr;
            n = end->next;
        }
        i++;
        curr = curr->next;
    }
    end->next = NULL;
    end = reverseNode(start);
    if(prev){
        prev->next = end;
    }else{
        A = end;
    }
    
    start->next = n;
    return A;
}