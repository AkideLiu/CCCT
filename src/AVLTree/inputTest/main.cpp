// Author : Akide Liu 
// Date : 18/9/21
// License and copyright notice: GNU General Public License v3.0 
// https://www.gnu.org/licenses/gpl-3.0.en.html
// Description : 

//

#include "../AVLTree.h"

using namespace std;

class Provider {

public:

    // flag = true --> run on web submission
    // flag = false --> run on test
    static void init (bool flag,const vector<string>& replace) {
        shared_ptr<AVLTree> avlTree = make_shared<AVLTree>();

        // get input
        vector<string> input;

        if (flag) {

            while (cin.good()) {
                try {

                    string input_value;
                    cin >> input_value;

                    if(input_value.length() == 0)
                        continue;

                    input.push_back(input_value.substr(0, input_value.find(' ')));

                    //cout << input_value.substr(0, input_value.find(' ')) << endl;

                }catch(exception& e) {
                    cout << e.what() << endl;
                }
            }

        } else {

            input = replace;

        }

        for (int i = 0; i < input.size() - 1; ++i) {
            string identifier = input[i].substr(0, 1);
            int value = stoi(input[i].substr(1, input[i].size() - 1));
            if (identifier.find('A') != string::npos) {
                //cout << "Add! " << value << endl;
                avlTree->insert(value);
            } else if (identifier.find('D') != string::npos) {
                //cout << "Del! " << value << endl;
                avlTree->deleteInAction(value);
            }

            // cout << input[i] << endl;
        }

        if (avlTree->getMRoot() == nullptr) {
            cout << "EMPTY" << endl;
        }

        if (input[input.size() - 1] == "PRE") {
            avlTree->preOrder();
        }

        if (input[input.size() - 1] == "POST") {
            avlTree->postOrder();
        }

        if (input[input.size() - 1] == "IN") {
            avlTree->inOrder();
        }

    }

};

#ifndef GTEST_LOCAL_TEST

int main(){

    Provider::init(true, vector<string>{});

}

#endif

#ifdef GTEST_LOCAL_TEST
#include <gtest/gtest.h>
#include <sstream>


vector<string> formatInput(string input) {
    vector<string> result;
    istringstream iss(input);

    while (iss) {
        string subs;
        iss >> subs;
        result.push_back(subs);
        // cout << subs << endl;
    }

    result.pop_back();

    return result;
}


TEST(test,case1){
    string input = "D29 D7 A43 D28 D90 A82 A68 D56 D46 A58 D26 D34 A46 A56 A84 A55 D34 D98 D33 D45 D35 A52 A31 D73 D62 D61 D92 A43 A100 A81 A83 D10 D82 D58 A91 D20 D7 D90 A28 A93 D2 A50 A7 A9 D91 A5 D51 A66 A56 A40 A74 D66 A57 D35 D64 A95 D73 A24 D23 A13 D98 D1 D74 A22 D69 A24 A33 A71 A58 A9 A77 A29 A98 A64 D50 D47 D33 A72 D21 D93 A4 A79 A61 D61 A34 D82 D71 D65 D8 A96 A25 A62 A31 A87 D20 A13 D80 A36 A56 D51 PRE";

    string expected = "56 31 9 5 4 7 24 13 22 28 25 29 46 40 34 36 43 52 55 81 68 58 57 64 62 77 72 79 95 84 83 87 98 96 100 ";

    testing::internal::CaptureStdout();

    Provider::init(false, formatInput(input));

    string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, expected);

}


#endif
