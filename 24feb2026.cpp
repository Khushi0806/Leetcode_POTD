class Solution {
public:
    int dfs(TreeNode* node, int currentSum) {
        if (!node) return 0;
        
        // Update current binary value
        currentSum = currentSum * 2 + node->val;
        
        // If leaf node
        if (!node->left && !node->right)
            return currentSum;
        
        // Recur left and right
        return dfs(node->left, currentSum) + 
               dfs(node->right, currentSum);
    }
    
    int sumRootToLeaf(TreeNode* root) {
        return dfs(root, 0);
    }
};
