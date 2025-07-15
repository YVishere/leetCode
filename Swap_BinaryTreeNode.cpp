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
    //Global variables to keep track of nodes while traversing
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

        //Inorder traversal, so get to the leftmost node first  
        toFind(node->left);

        //Will reach this line when we are done with left subtrees and start moving to the right
        if (prev && prev->val > node->val){ //Comparision in view that the right subtree should be greater than the current node
            if (!first){
                first = prev; //First time we find a node that is out of order. In future out of order nodes, we will only look for the second one because the out of order can be at different depths
            }
            second = node;
        }
        prev = node; // Update the previous node to the current one`

        //Now move to the right subtree
        toFind(node->right);
    }
};