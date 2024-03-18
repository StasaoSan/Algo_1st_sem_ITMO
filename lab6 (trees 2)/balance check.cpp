#include <iostream>
#include <vector>

struct Node{
    int key, left, right, balance;
};

int main(){
    int n, val, le, ri, l, r;
    std::cin>>n;
    std::vector<Node> vec(n+1);

    for (int i = 1; i < n+1; ++i) {
        std::cin>>val>>le>>ri;
        Node *node = new Node;
        *node = {0, le, ri, 0};
        vec[i]=*node;
    }

    for (int i = n; i > 0; i--){
        if (vec[i].left!=0) {
            l = vec[vec[i].left].balance + 1;
        }
        else l = 0;

        if (vec[i].right!=0){
            r = vec[vec[i].right].balance + 1;
        }
        else r = 0;
        vec[i].key = r - l;
        vec[i].balance = std::max(l, r);
    }

    for (int i = 1; i < n+1; ++i) {
        std::cout<<vec[i].key<<'\n';
    }
}