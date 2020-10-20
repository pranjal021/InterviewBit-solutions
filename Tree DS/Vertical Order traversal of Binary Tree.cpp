/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//this question is solved using level-order traversal;

vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* A) {
    map<int,vector<int>> m;
    queue<pair<int,TreeNode*>> q;
    if(!A)return {};
    q.emplace(0,A);
    while(!q.empty()){
        auto[dist,temp] = q.front();
        q.pop();
        m[dist].push_back(temp->val);
        if(temp->left) q.emplace(dist-1,temp->left);
        if(temp->right) q.emplace(dist+1,temp->right);
    }
    
    vector<vector<int>> res;
    for(auto &i:m) res.push_back(i.second);
    return res;
}