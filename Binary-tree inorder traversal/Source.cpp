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
    std::vector<int> vec;
    
    void inorderStore(std::vector<int>& vec, TreeNode* node);
    
    std::vector<int> inorderTraversal(TreeNode* root) {
        inorderStore(vec, root); 
        return vec;
    }
};

void Solution::inorderStore(std::vector<int>& vec, TreeNode* node)
{
       if(node!=nullptr){
           inorderStore(vec, node->left);
           vec.push_back(node->val);
           inorderStore(vec, node->right);
       }
    else{}
}
