/*
Solution for LeetCode #297 'Serialize and Deserialize Binary Tree'
https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
Runtime: X ms for Y test cases, Zth percentile
Time complexity:
Notes:
*/

#include <iostream>
#include <sstream>
#include <string>

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Codec {
public:

    // Encodes a tree to a single string.
    std::string serialize(TreeNode* root) {
        std::ostringstream oss;
        serialize(root, oss);
        return oss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(std::string data) {
        return new TreeNode(99);
    }

private:

    // Richer call for recursion
    void serialize(TreeNode* root, std::ostringstream& oss) {
        if (root != NULL) {
            oss << root->val << " ";
            serialize(root->left,  oss);
            serialize(root->right, oss);
        }
        else {
            oss << "* ";
        }
    }
};