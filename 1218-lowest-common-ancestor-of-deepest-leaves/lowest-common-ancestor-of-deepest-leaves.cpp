/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root == p || root == q) return root;
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        if(left == NULL) return right;
        else if(right == NULL) return left;
        return root;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        vector<TreeNode*> child;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            child.clear();
            while(n--){
                TreeNode *node = q.front();
                q.pop();
                child.push_back(node);
                if(node->left) {q.push(node->left);}
                if(node->right) {q.push(node->right);}
            }
        }
        TreeNode *p = child[0];
        for(int i=1; i<child.size(); i++){
            p = lowestCommonAncestor(root, p, child[i]);
        }
        return p;
    }
};