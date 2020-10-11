/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::partition(ListNode* A, int B) {
    if(A==NULL || A->next==NULL)return A;
        vector<int> a,b;
        ListNode* temp=A;
        while(temp){
            if(temp->val <B){
                a.push_back(temp->val);
            }else{
                b.push_back(temp->val);
            }
            temp=temp->next;
        }
        int s=a.size();
        temp=A;
        for(int i=0;i<s;i++){
            temp->val = a[i];
            temp=temp->next;
        }
        s=b.size();
        for(int i=0;i<s;i++){
            temp->val = b[i];
            temp=temp->next;
        }
        return A;
}