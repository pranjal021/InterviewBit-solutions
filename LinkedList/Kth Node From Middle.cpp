/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
int getLen(ListNode* curr){
    int len =0;
    while(curr){
        len++;
        curr = curr->next;
    }
    return len;
}
 
int Solution::solve(ListNode* A, int B) {
    int len = getLen(A);
    int n = (len/2 + 1 -B);
    if(n<=0){
        return -1;
    }else{
        ListNode* curr = A;
        int count =1;
        while(curr!=NULL){
            if(count == n){
                return curr->val;
            }
            count++;
            curr=curr->next;
        }
    }
}