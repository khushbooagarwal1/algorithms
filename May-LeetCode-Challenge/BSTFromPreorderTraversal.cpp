/* https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/537/week-4-may-22nd-may-28th/3339/ */

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
    TreeNode* constructTree(vector<int>& preorder, int& cur, int min, int max){
        if(cur >= preorder.size()){
            return NULL;
        }
        TreeNode* root = NULL;
        if(preorder[cur]> min && preorder[cur] < max){
            root = new TreeNode;
            root->val = preorder[cur];
            cur++;
            if(cur<preorder.size()){
                root->left = constructTree(preorder, cur, min, preorder[cur-1]);
                root->right = constructTree(preorder, cur, preorder[cur-1], max);
            }
        }
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index = 0;
        return constructTree(preorder, index, 0, pow(10, 8) + 1);
    }
};
