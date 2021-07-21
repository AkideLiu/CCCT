// Author : Akide Liu 
// Date : 3/6/21
// License and copyright notice: GNU General Public License v3.0 
// https://www.gnu.org/licenses/gpl-3.0.en.html
// Description : 

//

#ifndef ADDS_AVLTREE_H
#define ADDS_AVLTREE_H


#include "binarySearchTree.h"

class AVLTree : public binarySearchTree {
public:
    AVLTree();


    int height(shared_ptr<Node> node);

    shared_ptr<Node> newNode(int key);

    shared_ptr<Node> rightRotate(const shared_ptr<Node>& y);

    shared_ptr<Node> leftRotate(const shared_ptr<Node>& x);

    int getBalance(const shared_ptr<Node> &node);

    shared_ptr<Node> insert(shared_ptr<Node> &root, int input) override;

    shared_ptr<Node> insert(int input) override;

    // From BST
    void inOrder() override;

    void inOrder(shared_ptr<Node> &root) override;

    const shared_ptr<Node> &getMRoot() const override;

    shared_ptr<Node> search(int key) override;

private:
    shared_ptr<Node> search(shared_ptr<Node> &root, int key) override;
};


#endif //ADDS_AVLTREE_H
