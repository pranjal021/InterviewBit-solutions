/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
int solve(TreeNode* root){
    if(root==NULL)return 0;
    int l = solve(root->left);
    int r = solve(root->right);
    return max(l,r)+1;
}
 
int Solution::maxDepth(TreeNode* A) {
    return solve(A);
}
