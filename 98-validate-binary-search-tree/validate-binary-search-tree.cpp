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
    bool helper(TreeNode* root, long minVal, long maxVal){


        if(root==NULL) return true;

        if(minVal>=root->val) return false;
        if(maxVal<=root->val) return false;

            return helper(root->left, minVal, root->val) && helper(root->right, root->val, maxVal);

    }

    bool isValidBST(TreeNode* root) {
        return helper(root, LONG_MIN, LONG_MAX);
        
    }
};