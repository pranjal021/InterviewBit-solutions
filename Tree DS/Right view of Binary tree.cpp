/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
void printRightView(TreeNode* head,int level,int &maxLevel,vector<int> &res){
    if(head== NULL)return;
    
    if(maxLevel<level){
        res.push_back(head->val);
        maxLevel=level;
    }
    
    printRightView(head->right,level+1,maxLevel,res);
    printRightView(head->left,level+1,maxLevel,res);
    return;
}

vector<int> Solution::solve(TreeNode* A) {
    vector<int> res;
    int maxLevel = -1;
    printRightView(A,0,maxLevel,res);
    return res;
}