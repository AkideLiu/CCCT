// Author : Akide Liu 
// Date : 3/6/21
// License and copyright notice: GNU General Public License v3.0 
// https://www.gnu.org/licenses/gpl-3.0.en.html
// Description : 

//

#ifndef ADDS_BINARYSEARCHTREE_H
#define ADDS_BINARYSEARCHTREE_H

#include "Node.cpp"
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class binarySearchTree {

public:
    binarySearchTree();

    explicit binarySearchTree(vector<int> &input);

    virtual std::shared_ptr<Node> create_tree(vector<int> &input);

    virtual std::shared_ptr<Node> insert(int input);

    virtual const shared_ptr<Node> &getMRoot() const;

    virtual shared_ptr<Node> search(int key);

    virtual void inOrder();

    virtual void inOrder(shared_ptr<Node> &root);

    virtual ~binarySearchTree();


protected:


    virtual std::shared_ptr<Node> insert(shared_ptr<Node> &root, int input);

    virtual shared_ptr<Node> search(shared_ptr<Node> &root,int key);

    shared_ptr<Node> m_root;
};


#endif //ADDS_BINARYSEARCHTREE_H
