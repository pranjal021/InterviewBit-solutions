/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reorderList(ListNode* A) {
    if(A==NULL)return NULL;
    ListNode* temp=A;
    vector<int> a,b;
    while(temp){
        a.push_back(temp->val);
        temp=temp->next;
    }
    int i=0;
    int j=a.size()-1;
    int k=0;
    while(i<j){
        b.push_back(a[i]);
        b.push_back(a[j]);
        i++; j--;
        k+=2;
    }
    if(i==j){
        b.push_back(a[i]);
        k++;
    }
    int l=k;
    ListNode* tmp=A;
    while(tmp!=NULL && l>=0){
        tmp->val = b[k-l];
        l--;
        tmp=tmp->next;
    }
    return A;
}