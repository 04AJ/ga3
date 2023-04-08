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
    btree tree = btree();
    tree.insert(9);
    tree.insert(6);
    tree.insert(3);
    tree.insert(2);
    tree.insert(5);
    tree.insert(4);
    tree.insert(1);

    string temp = "[x";
    tree.preorder(tree.getRoot(), temp, false);
    return 0;
}