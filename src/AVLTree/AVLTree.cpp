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
    return 1 + max(height(node->left), height(node->right));
}

shared_ptr<Node> AVLTree::insert(shared_ptr<Node> &node, int input) {


    // if empty tree add a root element
    if(node == nullptr)
    {
        node = make_shared<Node>(input);
        return nullptr;
    }

    // add to left subtree
    if(input < node->data)
    {
        insert(node->left, input);

        // rebalance
        int left_height = height(node->left);
        int right_height = height(node->right);
        if(left_height >= right_height + 2)
        {
            if(input < node->left->data)
            {
                leftRotate(node);
            }
            else
            {
                leftRightRotate(node);
            }
        }
        return nullptr;
    }

    // add to right subtree
    if(input > node->data)
    {
        insert(node->right, input);

        // rebalance
        int left_height = height(node->left);
        int right_height = height(node->right);
        if(left_height + 2 <= right_height)
        {
            if(input > node->right->data)
            {
                rightRotate(node);
            }
            else
            {
                rightLeftRotate(node);
            }
        }
        return nullptr;
    }

    return nullptr;
}

AVLTree::NODE_T AVLTree::insert(int input) {
    insert(this->m_root, input);
    return nullptr;
}

AVLTree::NODE_T AVLTree::create_tree(vector<int> &input) {
    for_each(input.begin(), input.end(),[&](int value){
        insert(value);
    });

    return this->m_root;
}

AVLTree::AVLTree(vector<int> &input) : binarySearchTree(input) {
    create_tree(input);
}

void AVLTree::deleteInAction(int input) {
    deleteInAction(this->m_root, input);
}

void AVLTree::deleteInAction(AVLTree::NODE_T &node, int input) {
    NODE_T iter = node;
    while(iter != nullptr)
    {
        if(iter->data == input)
            break;
        if(iter->data < input)
            iter = iter->right;
        else
            iter = iter->left;
    }
    if(iter == nullptr)
    {
        return;
    }
    if(iter->left == nullptr || iter->right == nullptr)
    {
        node = deleteInAction_withBalance(node, iter->data);
        return;
    }
    int tmp;
    NODE_T temp = iter->left;
    while(temp->right != nullptr)
    {
        temp = temp->right;
    }
    tmp = temp->data;
    deleteInAction_withBalance(node, temp->data);
    iter->data = tmp;
}

AVLTree::NODE_T AVLTree::deleteInAction_withBalance(AVLTree::NODE_T &node, int value) {
    if(node == nullptr)
    {
        return nullptr;
    }
    if(value < node->data)
    {
        node->left = deleteInAction_withBalance(node->left, value);
        int left_height = height(node->left);
        int right_height = height(node->right);
        if(left_height + 2 <= right_height)
        {
            if(height(node->right->left) <= height(node->right->right))
            {
                rightRotate(node);
            }
            else
            {
                rightLeftRotate(node);
            }
        }
        return node;
    }
    else if(value > node->data)
    {
        node->right = deleteInAction_withBalance(node->right, value);
        int left_height = height(node->left);
        int right_height = height(node->right);
        if(left_height >= right_height + 2)
        {
            if(height(node->left->left) >= height(node->left->right))
            {
                leftRotate(node);
            }
            else
            {
                leftRightRotate(node);
            }
        }
        return node;
    }
    else
    {
        if(node->left == nullptr && node->right == nullptr)
        {
            return nullptr;
        }
        if(node->left != nullptr)
        {
            return node->left;
        }
        else
        {
            return node->right;
        }
        return node;
    }
}

AVLTree::NODE_T AVLTree::rightRotate(AVLTree::NODE_T &node) {
    if (node == nullptr) {
        return node;
    }

    NODE_T temp = node->right;

    if (temp != nullptr) {
        node->right = temp->left;
    }

    if (temp != nullptr) {
        temp->left = node;
    }

    node = temp;
    return node;
}

AVLTree::NODE_T AVLTree::leftRotate(AVLTree::NODE_T &node) {
    if (node == nullptr) {
        return node;
    }

    NODE_T temp = node->left;

    if (temp != nullptr) {
        node->left = temp->right;
    }

    if (temp != nullptr) {
        temp->right = node;
    }

    node = temp;
    return node;
}

AVLTree::NODE_T AVLTree::leftRightRotate(AVLTree::NODE_T &node) {
    if (node == nullptr) {
        return node;
    }

    rightRotate(node->left);
    leftRotate(node);
    return node;
}

AVLTree::NODE_T AVLTree::rightLeftRotate(AVLTree::NODE_T &node) {
    if (node == nullptr) {
        return node;
    }

    leftRotate(node->right);
    rightRotate(node);
    return node;
}

void AVLTree::postOrder() {
    this->postOrder(this->m_root);
}

void AVLTree::preOrder() {
    this->preOrder(this->m_root);
}

void AVLTree::postOrder(AVLTree::NODE_T &root) {
    if (root == nullptr) {
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

void AVLTree::preOrder(AVLTree::NODE_T &root) {
    if (root == nullptr) {
        return;
    }

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
};

