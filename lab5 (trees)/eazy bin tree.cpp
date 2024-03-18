#include <iostream>
struct Node {
    int key;
    Node* parent;
    Node *left, *right;
};

Node* max(Node* root);
Node* min(Node* root);
Node* pred (Node* root);
Node* sled(Node* root);
Node* search(Node* root, int val);
void print_BST(Node *x);
void insert_BST(Node* &root, int value);
void delete_BST(Node* &root, Node *z);
void Transplant(Node* &root, Node *u, Node *v);

int main() {
    Node *root = nullptr;
    std::string s;
    while(std::cin>>s) {
        if (s == "insert"){
            int val;
            std::cin>>val;
            insert_BST(root, val);
        }
        else if (s=="delete"){
            int val;
            std::cin>>val;
            Node *searchnode = search(root, val);
            if (searchnode!=nullptr){
                delete_BST(root, searchnode);
            }
        }
        else if (s == "exists"){
            int val;
            std::cin>>val;
            Node *searchnode = search(root, val);
            if (searchnode != nullptr){
                std::cout<<"true"<<"\n";
            }
            else{
                std::cout<<"false"<<"\n";
            }
        }
        else if (s == "next"){
            int val;
            std::cin>>val;
            if (root!=nullptr) {
                Node *node_dla_sled = search(root, val);
                bool flag = false;
                if (node_dla_sled == nullptr && max(root)->key > val) { //если элемента нет в списке
                    insert_BST(root, val);
                    node_dla_sled = search(root, val);
                    flag = true;
                }
                if (max(root)->key <= val) { //если элемент больше максимального
                    std::cout << "none" << "\n";
                } else {
                    Node *node_next = sled(node_dla_sled);
                    if (flag){
                        delete_BST(root, node_dla_sled);
                    }
                    std::cout << node_next->key << "\n";
                }
            }
            else{
                std::cout<<"none"<<"\n";
            }
        }
        else if (s == "prev"){
            int val;
            std::cin>>val;
            if (root!=nullptr) {
                Node *node_dla_pred = search(root, val);
                bool flag = false;
                if (node_dla_pred == nullptr && min(root)->key < val) { //если элемента нет в списке
                    insert_BST(root, val);
                    node_dla_pred = search(root, val);
                    flag = true;
                }
                if (min(root)->key >= val) { //если элемент меньше максимального
                    std::cout << "none" << "\n";
                } else {
                    Node *node_pred = pred(node_dla_pred);
                    if (flag) {
                        delete_BST(root, node_dla_pred);
                    }
                    std::cout << node_pred->key << "\n";
                }
            }
            else{
                std::cout<<"none"<<"\n";
            }
        }
        else{
            print_BST(root);
        }
    }
}

void insert_BST(Node* &root, int value) {
    Node *z = new Node;
    z->key = value;
    z->left = nullptr;
    z->right = nullptr;
    Node *x = root;
    Node *y = nullptr;
    while(x!=nullptr) {
        y = x;
        if(value < x->key)
            x = x->left;
        else if (value > x->key)
            x = x->right;
        else
            break;
    }
    if(root==nullptr)
        root = z;
    else if(value < y->key)
        y->left = z;
    else if (value > y->key)
        y->right = z;
    z->parent = y;
}
Node* max(Node* root){
    if (root->right == nullptr){
        return root;
    }
    return max(root->right);
}
Node* min(Node* root){
    if (root->left == nullptr){
        return root;
    }
    return min(root->left);
}
Node* pred (Node* root){
    if (root->left != nullptr){
        return max(root->left);
    }
    Node *y = root->parent;
    while (y!=nullptr && root == y->left){
        root = y;
        y = y->parent;
    }
    return y;
}
Node* sled(Node* root){
    if (root->right != nullptr){
        return min(root->right);
    }
    Node *y = root->parent;
    while (y != nullptr && root == y->right){
        root = y;
        y = y->parent;
    }
    return y;
}

void delete_BST(Node* &root, Node *z) {
    if(z->left==nullptr)
        Transplant(root, z, z->right);
    else if(z->right==nullptr)
        Transplant(root, z, z->left);
    else {
        Node *y = min(z->right);
        if(y->parent!=z) {
            Transplant(root, y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        y->left = z->left;
        y->left->parent = y;
        Transplant(root,z,y);
    }
}
void Transplant(Node* &root, Node *u, Node *v) {
    if(v!=nullptr)
        v->parent = u->parent;
    if(u->parent==nullptr)
        root = v;
    else if(u->parent->left == u)
        u->parent->left = v;
    else
        u->parent->right = v;
}
void print_BST(Node *x) {
    if(x!=NULL) {
        print_BST(x->left);
        std::cout<<x->key<<" ";
        print_BST(x->right);
    }
}
Node* search(Node* root, int val){
    if (root == nullptr || val == root->key){
        return root;
    }
    if (val<root->key){
        return search(root->left, val);
    }
    else{
        return search(root->right, val);
    }
}