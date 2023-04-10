#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include "ArgumentManager.h"
#include "btree.h"
using namespace std;

int main(int argc, char *argv[])
{
    ArgumentManager am(argc, argv);

    string input = am.get("input");
    string output = am.get("output");

    // ifstream ifs(input);
    // ofstream ofs(output);

    ifstream ifs("input1.txt");
    ofstream ofs("output1.txt");

    btree tree = btree();

    // Ex of how to call preorder function - note bool value can be set true or false.
    string temp = "[x";
    tree.preorder(tree.getRoot(), temp, false, ofs);

    return 0;
}