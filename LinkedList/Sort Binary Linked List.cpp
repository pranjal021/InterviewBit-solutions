/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::solve(ListNode* A) {
    vector<int> v;
    ListNode* temp = A;
    while(temp){
        v.push_back(temp->val);
        temp=temp->next;
    }
    sort(v.begin(),v.end());
    int i=0;
    temp = A;
    while(temp){
        temp->val = v[i];
        i++;
        temp = temp->next;
    }
    return A;
}