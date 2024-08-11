class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> ans;
        inorder(root, ans);
        return ans[k-1];
    }
    void inorder(TreeNode* node, vector<int>& ans){
        if(node == nullptr)
            return;
        
        inorder(node->left, ans);
        ans.push_back(node->val);
        inorder(node->right, ans);
    }
};
