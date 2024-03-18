#include <iostream>
#include <vector>


void sort(std::vector<int> &vec, int len, int i) {
    int max = i, lc = 2*i, rc= 2*i+1;

    if (lc < len){
        if (vec[lc]>vec[max]){
            max = lc;
        }
    }
    if (rc < len){
        if (vec[rc] > vec[max]){
            max = rc;
        }
    }
    if (max!=i){
        std::swap(vec[i], vec[max]);
        sort(vec, len, max);
    }
}

void buildheap(std::vector<int> &vec, int len){
    for (int i = len/2 ; i > 0; i--){
        sort(vec, len, i);
    }
}

void heap_sort(std::vector<int> &vec, int len){
    buildheap(vec, len+1);
    for (int i = len; i >=1 ; i--) {
        std::swap(vec[1], vec[i]);
        sort(vec, i, 1);
    }
}

int main() {
    int len;
    std::cin>>len;
    std::vector<int> vec(len+1);
    for (int i = 1; i <= len; ++i) {
        std::cin>>vec[i];
    }
    heap_sort(vec, len);
    for (int i=1; i<len+1; ++i) {
        std::cout << vec[i] << " ";
    }
}
