#include <iostream>
#include <vector>

struct Node{
    int key;
    int left, right, index;
};

int count(std::vector<Node> vec){
    if (vec.size()-1 == 0){
        return -1;
    }
    int len = vec.size()-1;
    for (int i = len; i > 0; i--) {
        if (vec[i].left!=0 && vec[i].right != 0){
            vec[i].index = std::max(vec[vec[i].left].index, vec[vec[i].right].index)+1;
        }
        else {
            if (vec[i].left != 0) {
                vec[i].index = vec[vec[i].left].index + 1;
            } else if (vec[i].right != 0) {
                vec[i].index = vec[vec[i].right].index + 1;
            }
        }
    }
    return vec[1].index;
}

int main(){
    int n, val, l, r;
    std::cin>>n;
    std::vector<Node> vec(n+1);
    for (int i = 1; i <= n; ++i) {
        std::cin>>val>>l>>r;
        Node *node = new Node;
        node -> key = val;
        node -> left = l;
        node -> right = r;
        node -> index = 0;
        vec[i]=*node;
    }
    int a = count(vec)+1;
    std::cout<<a;
}

//13
//9 2 3
//7 4 5
//15 6 7
//3 0 0
//8 0 0
//13 0 0
//25 8 0
//22 9 10
//20 11 12
//24 13 0
//19 0 0
//21 0 0
//23 0 0