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

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int ans;
        inorder(root, ans, k);
        return ans;
    }
    void inorder(TreeNode* node, int& ans, int &k){
        if(node == nullptr)
            return;
        
        inorder(node->left, ans, k);
        if(k == 0)
            return;
        if(--k == 0){
            ans = node->val;
            return;
        }
        
        inorder(node->right, ans, k);
    }
};
