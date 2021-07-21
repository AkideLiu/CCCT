// Author : Akide Liu 
// Date : 21/7/21
// License and copyright notice: GNU General Public License v3.0 
// https://www.gnu.org/licenses/gpl-3.0.en.html
// Description : 

//

// helper :

#include <gtest/gtest.h>
#include <fmt/core.h>
#include <memory>
#include <dbg.h>
#include <cmath>
#include <algorithm>
#include <exception>

// test target :

using namespace std;

TEST(AVLTree, testing) {
    cout << "hello" << endl;
}

#include <binarySearchTree.h>
#include <AVLTree.h>


TEST(AVLTree, BST) {

    vector<int> array1 = {2, 10, 9, 4, 6, 8, 5, 3, 7};

    shared_ptr<binarySearchTree> BST = make_shared<binarySearchTree>(array1);

    BST->inOrder();

    // insert
    BST->insert(-1);
    BST->insert(99);

    BST->inOrder();

    // search

    auto result = BST->search(7);

    BST->inOrder(result);

    shared_ptr<binarySearchTree> AVL = make_shared<AVLTree>();

    AVL->inOrder();

};



TEST(AVLTree, AVL) {

    shared_ptr<binarySearchTree> AVL = make_shared<AVLTree>();

    vector<int> array1 = {2, 10, 9, 4, 6, 8, 5, 3, 7};

    for (int i : array1) {
        // cout << "inserting : " + to_string(i) << endl;

        fmt::print("inserting : {} \n",to_string(i));

        AVL->insert(i);
        AVL->inOrder();
    }

    AVL->inOrder();
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
