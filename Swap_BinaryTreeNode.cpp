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
    TreeNode* first = nullptr;
    TreeNode* prev = nullptr;
    TreeNode* second = nullptr;
    void recoverTree(TreeNode* root) {
        toFind(root);
        int t = first->val;
        first->val = second->val;
        second->val = t;
    }

    void toFind(TreeNode* node){
        if(node == nullptr){
            return;
        }

        toFind(node->left);

        if (prev && prev->val > node->val){
            if (!first){
                first = prev;
            }
            second = node;
        }
        prev = node;
        toFind(node->right);
    }
};