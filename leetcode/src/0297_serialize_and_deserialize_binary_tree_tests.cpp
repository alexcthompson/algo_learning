#define CATCH_CONFIG_MAIN

#include <iostream>
#include "catch2/catch.hpp"
#include "0297_serialize_and_deserialize_binary_tree.hpp"


std::ostream& operator << (std::ostream& stream, const TreeNode& t) {
    std::cout << "TreeNode: val = " << t.val << "; left child = ";
    if (t.left == NULL) {
        std::cout << "NULL; right child = ";
    }
    else {
        std::cout << t.left->val << "; right child = ";
    }

    if (t.right == NULL) {
        std::cout << "NULL.";
    }
    else {
        std::cout << t.right->val << ".";
    }

    return stream;
}


struct Tree {
    TreeNode* root;
    Tree(TreeNode* root_in) : root(root_in) {}
};


std::ostream& operator << (std::ostream& stream, const Tree& tr) {
    stream << *(tr.root) << std::endl;

    if (tr.root->left) {
        Tree left(tr.root->left);
        stream << left;
    }
    if (tr.root->right) {
        Tree right(tr.root->right);
        stream << right;
    }

    return stream;
}


// recursive check for subtree equality
bool operator == (const TreeNode& A, const TreeNode& B) {
    if (A.val != B.val) {
        std::cout << A.val << " != " << B.val << std::endl;
        return false;
    }

    if (A.left) {
        std::cout << "left check" << std::endl;
        if(!B.left) {
            std::cout << "left check 1" << std::endl;
            return false;
        }
        else if (A.left != B.left) {
            std::cout << "left check 2" << std::endl;
            std::cout << "*(A.left) = " << *(A.left)
                      << "; *(B.left) = " << *(B.left) << std::endl;
            return false;
        }
    }

    if (A.right) {
        std::cout << "right check" << std::endl;
        if(!B.right) {
            std::cout << "right check 1" << std::endl;
            return false;
        }
        else if (A.right != B.right) {
            std::cout << "right check 2" << std::endl;
            return false;
        }
    }

    return true;
}

bool operator != (const TreeNode& A, const TreeNode& B) {
    return ! (A == B);
}


TEST_CASE("all tests") {
    TreeNode* root = new TreeNode(777);
    root->left = new TreeNode(778);
    (root->left)->left = new TreeNode(779);
    (root->left)->right = new TreeNode(11);
    ((root->left)->right)->left = new TreeNode(-23);
    root->right = NULL;

    Tree t(root);

    SECTION("== overload check") {
        TreeNode* root2 = new TreeNode(777);
        root2->left = new TreeNode(778);
        (root2->left)->left = new TreeNode(779);
        (root2->left)->right = new TreeNode(11);
        ((root2->left)->right)->left = new TreeNode(-23);
        root2->right = NULL;

        TreeNode* root3 = new TreeNode(777);
        root3->left = new TreeNode(778);
        (root3->left)->left = new TreeNode(779);
        (root3->left)->right = new TreeNode(666);
        ((root3->left)->right)->left = new TreeNode(-23);
        root3->right = NULL;

        Codec c;
        std::cout << c.serialize(root) << std::endl;
        std::cout << c.serialize(root2) << std::endl;
        std::cout << c.serialize(root3) << std::endl;

        CHECK ( *root2 == *root );
        CHECK ( *root3 != *root );
    }

    SECTION("serialize") {
        Codec c;
        std::string result = c.serialize(root);
        std::string expected = "777 778 779 * * 11 -23 * * * * ";
        CHECK( result == expected );
    }

    SECTION("deserialize") {
        Codec c;
        std::string encoded = "777 778 779 * * 11 -23 * * * * ";
        TreeNode* result = c.deserialize(encoded);
        CHECK( result == root );
    }
}