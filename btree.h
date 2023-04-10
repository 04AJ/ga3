#ifndef BTREE_H
#define BTREE_H
#include <fstream>
#include <string>

struct node
{
    int num;
    node *left;
    node *right;
    string path;

    node()
    {
        num = 0;
        left = nullptr;
        right = nullptr;
        path = "";
    }

    node(int n)
    {
        num = n;
        left = nullptr;
        right = nullptr;
        path = "";
    }
};

class btree
{
private:
    node *root;

public:
    btree() { root = nullptr; }

    bool empty() { return root == nullptr; }

    node *getRoot() { return root; };

    bool insert(int num)
    {
        if (empty())
        {
            node *tmp = new node(num);
            root = tmp;
            return true;
        }
        return insertR(num, root);
    }

    bool insertR(int num, node *r)
    {
        bool retVal = false;
        if (r != nullptr)
        {
            if (num == r->num)
                return false;
            if (num < r->num)
            {
                if (r->left == nullptr)
                    r->left = new node(num);
                else
                    retVal = insertR(num, r->left);
            }
            else
            {
                if (r->right == nullptr)
                    r->right = new node(num);
                else
                    retVal = insertR(num, r->right);
            }
        }
        return retVal;
    }

    void preorder(node *r, string &s, bool direction, ofstream &ofs)
    {
        if (r == nullptr)
            return;
        else
        {
            if (r != root)
                s += (direction) ? "l" : "r";

            r->path = s;

            ofs << s << "] " << to_string(r->num) << endl;
            preorder(r->left, s, true, ofs);
            s = r->path;
            preorder(r->right, s, false, ofs);
        }
    }
};

#endif