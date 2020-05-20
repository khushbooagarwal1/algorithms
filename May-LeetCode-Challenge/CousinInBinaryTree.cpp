/* https://leetcode.com/explore/featured/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3322/ */

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
    pair<TreeNode*, int> findParentAndDepth(TreeNode* t, int x, int depth){
        if(t->val == x){
            return make_pair(t, depth);
        }
        if(t->left == NULL && t->right == NULL){
            return make_pair(new TreeNode(), -1);
        }
        if((t->left != NULL && t->left->val == x) || (t->right != NULL && t->right->val == x)){
            return make_pair(t, depth+1);
        }
        if(t->left != NULL) {
            pair<TreeNode*, int> p =findParentAndDepth(t->left, x, depth+1);
            if(p.second != -1){
                return p;
            }
        }
        if(t->right != NULL) {
            pair<TreeNode*, int> p =findParentAndDepth(t->right, x, depth+1);
            if(p.second != -1){
                return p;
            }
        }
        return make_pair(new TreeNode(), -1);
        
    }
public:
    bool isCousins(TreeNode* root, int x, int y) {
        pair<TreeNode*, int> firstNode = findParentAndDepth(root, x, 0);
        if(firstNode.second != -1){
            pair<TreeNode*, int> secondNode = findParentAndDepth(root, y, 0);
            if(secondNode.second != -1 && secondNode.second == firstNode.second && secondNode.first->val != firstNode.first->val){
                return true;
            }
        }
        return false;
        
    }
};
