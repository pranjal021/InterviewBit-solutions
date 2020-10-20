/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 //method 1: using recursion
 
void solve(TreeNode* root,vector<int> &res){
    if(root==NULL)return;
    queue<TreeNode*> q;
    q.push(root);
    
    while(!q.empty()){
        auto node = q.front();
        q.pop();
        res.push_back(node->val);
        if(node->left){
            q.push(node->left);
        }
        if(node->right){
            q.push(node->right);
        }
    }
    return;
}

vector<int> Solution::preorderTraversal(TreeNode* A) {
    vector<int> res;
    solve(A,res);
    return res;
}

//method 2: using stack

vector<int> Solution::preorderTraversal(TreeNode* A) {
     vector<int> res;

        if(A==NULL)return res;

        stack<TreeNode*> s;
        s.push(A);

        while(!s.empty()){
            auto node = s.top();
            s.pop();
            res.push_back(node->val);
            if(node->right)
                s.push(node->right);
            if(node->left)
                s.push(node->left);
        }
        
        return res;
}