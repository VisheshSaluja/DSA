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
    vector<int> postorderTraversal(TreeNode* root) {

        vector<int> post;
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        s1.push(root);

        if(root==NULL) return post;


        
        while(!s1.empty()){
            
                TreeNode* f = s1.top();
                s1.pop();
                s2.push(f);
                if(f->left) s1.push(f->left);
                if(f->right) s1.push(f->right);
                f=f->left;
            
                

        }
        while(!s2.empty()){
            TreeNode* f2 = s2.top();
                s2.pop();
                post.push_back(f2->val);
 
        }
            
        

        return post;
        
    }
};