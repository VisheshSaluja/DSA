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
    unordered_map<int, int> idx;
    int pre = 0;

    TreeNode* helper(vector<int> &preorder, int l, int r){
        if(l>r) return NULL;
        
        int root_val = preorder[pre++];
        TreeNode* root = new TreeNode(root_val);

        int mid = idx[root_val];

        root->left = helper(preorder, l, mid-1);
        root->right = helper(preorder, mid+1, r);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++){
            idx[inorder[i]] = i;
        }

        return helper(preorder, 0, inorder.size()-1);
    }
};