/*
Solution for LeetCode #297 'Serialize and Deserialize Binary Tree'
https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
Runtime: 28 ms for 48 test cases, 99th percentile
Time complexity: O(n)
Space complexity: O(n)
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
        std::stringstream stream(data);

        return deserialize(stream);
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

    TreeNode* deserialize(std::stringstream& stream) {
        TreeNode* res = nullptr;
        std::string temp;
        stream >> temp;

        if (temp != "*") {
            res = new TreeNode(std::stoi(temp));
            res->left = deserialize(stream);
            res->right = deserialize(stream);
        }

        return res;
    }
};