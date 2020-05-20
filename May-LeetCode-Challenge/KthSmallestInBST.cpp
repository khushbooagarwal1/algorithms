/* https://leetcode.com/explore/featured/card/may-leetcoding-challenge/536/week-3-may-15th-may-21st/3335/ */

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
private:
    int getKthNode(TreeNode* root, int k, int& count){
        if(root == NULL){
            return -1;
        }
        int ans = -1;
        if(root->left != NULL){
            ans = getKthNode(root->left, k, count);
            if(ans != -1){
                return ans;
            }
        }
        count += 1;
        if(count == k){
            return root->val;
        }
        if(root->right != NULL){
            ans = getKthNode(root->right, k, count);
        }
        return ans;
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        return getKthNode(root, k, count);
    }
};
