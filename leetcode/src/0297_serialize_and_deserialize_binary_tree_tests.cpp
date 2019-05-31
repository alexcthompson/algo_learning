#define CATCH_CONFIG_MAIN

#include <iostream>
#include "catch2/catch.hpp"
#include "0297_serialize_and_deserialize_binary_tree.hpp"


std::ostream& operator << (std::ostream& ostream, const TreeNode& t) {
    ostream << "TreeNode: val = " << t.val << "; left child = ";
    if (t.left == NULL) {
        ostream << "NULL; right child = ";
    }
    else {
        ostream << t.left->val << "; right child = ";
    }

    if (t.right == NULL) {
        ostream << "NULL.";
    }
    else {
        ostream << t.right->val << ".";
    }

    return ostream;
}


struct Tree {
    TreeNode* root;
    Tree(TreeNode* root_in) : root(root_in) {}
};


std::ostream& operator << (std::ostream& ostream, const Tree& tr) {
    ostream << *(tr.root) << std::endl;

    if (tr.root->left) {
        Tree left(tr.root->left);
        ostream << left;
    }
    if (tr.root->right) {
        Tree right(tr.root->right);
        ostream << right;
    }

    return ostream;
}


// recursive check for subtree equality
bool operator == (const TreeNode& A, const TreeNode& B) {
    if (A.val != B.val) {
        return false;
    }

    // left side
    if ((A.left == nullptr) != (B.left == nullptr)) {
        return false;
    }
    else if (A.left && !(*(A.left) == *(B.left))) {
        return false;
    }

    // right side
    if ((A.right == nullptr) != (B.right == nullptr)) {
        return false;
    }
    else if (A.right && !(*(A.right) == *(B.right))) {
        return false;
    }

    return true;
}

bool operator != (const TreeNode& A, const TreeNode& B) {
    return ! (A == B);
}


TEST_CASE( "all tests" ) {
    Codec c;

    TreeNode* root = new TreeNode(777);
    root->left = new TreeNode(778);
    (root->left)->left = new TreeNode(779);
    (root->left)->right = new TreeNode(11);
    ((root->left)->right)->left = new TreeNode(-23);
    root->right = NULL;

    Tree t(root);

    SECTION( "== overload check" ) {
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

        // checks
        CHECK ( *root2 == *root );
        CHECK ( *root3 != *root );
    }

    SECTION( "serialize" ) {
        std::string result = c.serialize(root);
        std::string expected = "777 778 779 * * 11 -23 * * * * ";
        CHECK( result == expected );
    }

    SECTION( "deserialize" ) {
        std::string encoded = "777 778 779 * * 11 -23 * * * * ";
        TreeNode* result = c.deserialize(encoded);
        REQUIRE( result != nullptr );
        CHECK( *result == *root );
    }
}