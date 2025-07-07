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

    bool sameTree(TreeNode* node, TreeNode* subNode){
        if(node==NULL && subNode==NULL) return true;
        if(node==NULL || subNode==NULL) return false;
        

        if(node->val!=subNode->val){
            return false;
        }

        int left = sameTree(node->left, subNode->left);
        int right = sameTree(node->right, subNode->right);

        return left && right;

    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {


        if(subRoot==NULL) return true;
        if (root == nullptr) return false;

        if(sameTree(root, subRoot)){
            return true;
        }
        
        return (isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot));
    }
};