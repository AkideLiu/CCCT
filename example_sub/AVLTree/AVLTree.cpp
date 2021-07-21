// Author : Akide Liu 
// Date : 3/6/21
// License and copyright notice: GNU General Public License v3.0 
// https://www.gnu.org/licenses/gpl-3.0.en.html
// Description : 

//

#include "AVLTree.h"

AVLTree::AVLTree() {}

void AVLTree::inOrder() {
    binarySearchTree::inOrder();
}

void AVLTree::inOrder(shared_ptr<Node> &root) {
    binarySearchTree::inOrder(root);
}

const shared_ptr<Node> &AVLTree::getMRoot() const {
    return binarySearchTree::getMRoot();
}

shared_ptr<Node> AVLTree::search(int key) {
    return binarySearchTree::search(key);
}

shared_ptr<Node> AVLTree::search(shared_ptr<Node> &root, int key) {
    return binarySearchTree::search(root, key);
}

int AVLTree::height(shared_ptr<Node> node) {
    if (node == nullptr) {
        return 0;
    }
    return node->height;
}

shared_ptr<Node> AVLTree::newNode(int key) {
    auto node = make_shared<Node>(key);
    node->height = 1;
    return node;
}

shared_ptr<Node> AVLTree::rightRotate(const shared_ptr<Node>& y) {

    shared_ptr<Node> x = y->left;
    shared_ptr<Node> tmp = x->right;

    x->right = y;
    y->left = tmp;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(y->right)) + 1;


    return x;
}

shared_ptr<Node> AVLTree::leftRotate(const shared_ptr<Node>& x) {

    shared_ptr<Node> y = x->right;
    shared_ptr<Node> tmp = y->left;

    y->left = x;
    x->right = tmp;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

int AVLTree::getBalance(const shared_ptr<Node> &node) {

    if (node == nullptr) {
        return 0;
    }

    return height(node->left) - height(node->right);

}

shared_ptr<Node> AVLTree::insert(shared_ptr<Node> &root, int input) {


    /* 1. Perform the normal BST insertion */

    if (root == nullptr) {
        return newNode(input);
    }

    if (input < root->data) {
        root->left = insert(root->left, input);
    } else if (input > root->data) {
        root->right = insert(root->right, input);
    } else {
        return root;
    }

    /* 2. Update height of this ancestor node */

    root->height = 1 + max(height(root->left), height(root->right));


    /* 3. Get the balance factor of this ancestor
        node to check whether this node became
        unbalanced */

    int balance = getBalance(root);

    if (balance > 1 && input < root->left->data) {
        return rightRotate(root);
    }

    if (balance < -1 && input > root->right->data) {
        return leftRotate(root);
    }

    if (balance > 1 && input > root->left->data) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && input < root->right->data) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;

}

shared_ptr<Node> AVLTree::insert(int input) {
    this->m_root = insert(this->m_root, input);
    return this->m_root;
}
