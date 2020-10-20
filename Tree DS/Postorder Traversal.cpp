/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::postorderTraversal(TreeNode* A) {
    vector<int> res;
    if(A==NULL)return res;
    stack<TreeNode*> s1;
    stack<TreeNode*> s2;
    
    s1.push(A);
    TreeNode* root;
    while(!s1.empty()){
        root = s1.top();
        s1.pop();
        if(root->left){
            s1.push(root->left);
        }
        if(root->right){
            s1.push(root->right);
        }
        s2.push(root);
    }
    
    while(!s2.empty()){
        res.push_back(s2.top()->val);
        s2.pop();
    }
    return res;
    
}
