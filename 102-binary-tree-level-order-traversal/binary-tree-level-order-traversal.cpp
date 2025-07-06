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
    vector<vector<int>> levelOrder(TreeNode* root) {

        

        vector<vector<int>> level;
        queue<TreeNode*> q;

        if(root==NULL) return level;

        

        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> subLevel;

            for(int i=0;i<size;i++){
                TreeNode* f = q.front();
                q.pop();

                subLevel.push_back(f->val);
                if(f->left!=NULL) q.push(f->left);
                if(f->right!=NULL) q.push(f->right);
            }
            level.push_back(subLevel);

        }

        return level;
        
    }
};