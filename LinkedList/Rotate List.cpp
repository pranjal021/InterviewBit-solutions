/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::rotateRight(ListNode* A, int B) {
     if(A==NULL)return NULL;
        ListNode* temp = A;
        int len=0;
        
        while(temp){
            len++;
            temp=temp->next;
        }
        B = B%len;
        
        if(B==0)return A;
        int kfront = len - (B+1);
        temp=A;
        while(kfront--){
            temp=temp->next;
        }
        ListNode* newHead = temp->next;
        temp->next=NULL;
        ListNode* tmp=newHead;
        while(tmp->next){
            tmp=tmp->next;
        }
        tmp->next = A;
        return newHead;  
}