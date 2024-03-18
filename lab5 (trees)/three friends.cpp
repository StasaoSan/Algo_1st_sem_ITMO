#include <iostream>

struct Node {
    std::string key;
    Node *parent;
    Node *left, *right;
};

int compare(std::string s1, std::string s2);
bool search(Node* root, const std::string& val);
void insert_BST(Node* &root, std::string value);

int main() {
    Node *dr1 = nullptr;
    Node *dr2 = nullptr;
    Node *dr3 = nullptr;
    int c1 = 0, c2 = 0, c3 = 0;
    std::string s;
    int n;
    std::cin >> n;
    for (int i = 0;  i< n; ++i) {
        std::cin >> s;
        insert_BST(dr1, s);
        c1+=3;
    }
    for (int i = 0; i < n; ++i) {
        std::cin>>s;
        c2+=3;
        insert_BST(dr2, s);
        if (search(dr1,s)){
            c1-=2;
            c2-=2;
        }
    }
    for (int i = 0; i < n; ++i) {
        std::cin>>s;
        c3+=3;
        insert_BST(dr3, s);
        if (search(dr1,s) && search(dr2, s)){
            c1--;
            c2--;
            c3-=3;
        }
        if (search(dr1, s) && !search(dr2, s)){
            c1-=2;
            c3-=2;
        }
        if (!search(dr1, s) && search(dr2, s)){
            c2-=2;
            c3-=2;
        }
    }
    std::cout<<c1<<" "<<c2<<" "<<c3;
}


void insert_BST(Node* &root, std::string value) {
    Node *z = new Node;
    z->key = value;
    z->left = nullptr;
    z->right = nullptr;
    Node *x = root;
    Node *y = nullptr;
    while(x!=nullptr) {
        y = x;
        if(compare(value, x->key)<0)
            x = x->left;
        else if (compare(value, x->key)>0)
            x = x->right;
        else
            break;
    }
    if(root==nullptr)
        root = z;
    else if(compare(value, y->key)<0)
        y->left = z;
    else if (compare(value, y->key)>0)
        y->right = z;
    z->parent = y;
}

int compare(std::string s1, std::string s2){
    for (int i = 0; i < s1.size(); ++i) {
        if (s1[i] != s2[i]){
            return s1[i] - s2[i];
        }
    }
    return s1.size() - s2.size();
}

bool search(Node* root, const std::string& val){
    if (root == nullptr){
        return false;
    }
    if (root->key == val){
        return true;
    }
    if (compare(root->key, val) > 0){
        return search(root->left, val);
    }
    else{
        return search(root->right, val);
    }
}