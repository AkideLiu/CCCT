// Author : Akide Liu 
// Date : 3/6/21
// License and copyright notice: GNU General Public License v3.0 
// https://www.gnu.org/licenses/gpl-3.0.en.html
// Description :
// 18/9/21 update to v2 version
//

#ifndef ADDS_AVLTREE_H
#define ADDS_AVLTREE_H


#include "binarySearchTree.h"
#include <bits/stdc++.h>

class AVLTree : public binarySearchTree {
public:

    typedef shared_ptr<Node> NODE_T;

    AVLTree();

    explicit AVLTree(vector<int> &input);

    NODE_T create_tree(vector<int> &input) override;

    int height(NODE_T node);

    NODE_T insert(int input) override;

    void deleteInAction(int input);

    // From BST
    void inOrder() override;

    void postOrder();

    void preOrder();

    const NODE_T &getMRoot() const override;

    NODE_T search(int key) override;

private:

    void deleteInAction(NODE_T &node, int input);

    NODE_T search(NODE_T &root, int key) override;

    NODE_T insert(NODE_T &node, int input) override;

    NODE_T deleteInAction_withBalance(NODE_T &node, int value);

    NODE_T rightRotate(NODE_T &node);

    NODE_T leftRotate(NODE_T &node);

    NODE_T leftRightRotate(NODE_T &node);

    NODE_T rightLeftRotate(NODE_T &node);

    void inOrder(NODE_T &root) override;

    void postOrder(NODE_T &root);

    void preOrder(NODE_T &root);

};


#endif //ADDS_AVLTREE_H
