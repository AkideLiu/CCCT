// Author : Akide Liu 
// Date : 3/6/21
// License and copyright notice: GNU General Public License v3.0 
// https://www.gnu.org/licenses/gpl-3.0.en.html
// Description : 

//

#include "binarySearchTree.h"

binarySearchTree::binarySearchTree() = default;

std::shared_ptr<Node> binarySearchTree::create_tree(vector<int> &input) {


    for_each(input.begin(), input.end(),[&](int value){
        this->m_root = insert(this->m_root, value);
    });

    return this->m_root;
}

std::shared_ptr<Node> binarySearchTree::insert(shared_ptr<Node> &root, int input) {

    if (root == nullptr) {
        return make_shared<Node>(input);
    }

    if (input > root->data) {

        root->right = insert(root->right, input);

    } else {

        root->left = insert(root->left, input);
    }

    return root;
}

void binarySearchTree::inOrder(shared_ptr<Node> &root) {
    if (root == nullptr) {
        return;
    }

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

binarySearchTree::binarySearchTree(vector<int> &input) {

    create_tree(input);

}

void binarySearchTree::inOrder() {
    this->inOrder(this->m_root);
    cout << endl;
}

std::shared_ptr<Node> binarySearchTree::insert(int input) {
    this->m_root = insert(this->m_root, input);
    return this->m_root;
}

const shared_ptr<Node> &binarySearchTree::getMRoot() const {
    return m_root;
}

shared_ptr<Node> binarySearchTree::search(shared_ptr<Node> &root, int key) {

    if (root == nullptr || root->data == key) {
        return root;
    }

    if (root->data < key) {
        return search(root->right, key);
    }

    return search(root->left, key);
}

shared_ptr<Node> binarySearchTree::search(int key) {
    return search(this->m_root, key);
}

binarySearchTree::~binarySearchTree() = default;

