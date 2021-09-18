// Author : Akide Liu 
// Date : 29/5/21
// License and copyright notice: GNU General Public License v3.0 
// https://www.gnu.org/licenses/gpl-3.0.en.html
// Description : 

//

#include <string>
#include <memory>
class Node{

public:
    int data, balance;
    std::shared_ptr<Node> left, right;
    // for AVI tree
    explicit Node(int data) {
        this->data = data;
        this->left = this->right = nullptr;
        balance = 0;
    }


};
