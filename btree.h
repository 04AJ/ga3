struct node {
    int num;
    node *left;
    node *right;

    node() {
        num = 0;
        left = nullptr;
        right = nullptr;
    }

    node(int n) { num = n; }
};

class btree {
   private:
    node *root;

   public:
    btree() { root = nullptr; }

    bool empty() { return root == nullptr; }

    bool insert(int num) {
        if (empty()) {
            node *tmp = new node(num);
            root = tmp;
            return true;
        }
        return insertR(num, root);
    }

    bool insertR(int num, node *r) {
        bool retVal = false;
        if (r != nullptr) {
            if (num == r->num) return false;
            if (num < r->num) {
                if (r->left == nullptr)
                    r->left = new node(num);
                else
                    retVal = insertR(num, r->left);
            } else {
                if (r->right == nullptr)
                    r->right = new node(num);
                else
                    retVal = retVal || insertR(num, r->right);
            }
        }
        return retVal;
    }
};