#include <iostream>
#include <vector>

struct Node{
    int key, left, right;
};

void zapoln(std::vector<Node> &vec, int i, int &val){
    if (vec[i].left>0){
        zapoln(vec, vec[i].left, val);
    }
    vec[i].key = val++;
    if (vec[i].right>0){
        zapoln(vec, vec[i].right, val);
    }
    return;
}

int main(){
    int n, val = 1;
    std::cin>>n;
    std::vector<Node> vec(n+1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> vec[i].left >> vec[i].right;
    }
    zapoln(vec, 1, val);
    for (int i = 1; i <= n; ++i) {
        std::cout<<vec[i].key<<" ";
    }
}