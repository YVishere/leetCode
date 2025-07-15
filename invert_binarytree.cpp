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
    TreeNode* invertTree(TreeNode* root) {
        TreeNode *toRet = trav(root);
        return toRet;
    }
    
    TreeNode* trav(TreeNode* node){
        if (!node){
            return node;
        }
        TreeNode* r= trav(node->right);

        TreeNode *l= trav(node->left);

        node->left = r;
        node->right = l;

        return node;
    }
};