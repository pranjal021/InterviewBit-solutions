/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
ListNode* reverseLL(ListNode* head,int k){
    ListNode* temp = head;
    for(int i=0;i<k;i++){
        if(temp==NULL)return head;
        temp =temp->next;
    }
    temp = head;
    ListNode* prev = NULL;
    ListNode* nex;
    for(int i=0;i<k;i++){
        nex = temp->next;
        temp->next = prev;
        prev =temp;
        temp=nex;
    }
    if(nex!=NULL){
        head->next = reverseLL(nex,k);
    }
    return prev;
}
 
ListNode* Solution::reverseList(ListNode* A, int B) {
    ListNode* ans = reverseLL(A,B);
    return ans;
}