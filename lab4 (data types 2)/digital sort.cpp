#include <iostream>
#include <vector>

int main(){
    int n, len, k;
    std::cin>>n>>len>>k;
    std::string st;
    std::vector<std::string> vec(n);
    for (int i = 0; i < n; ++i) {
        std::cin>>st;
        vec[i]=st;
    }
    for (int i = len-1; i > len-k-1; i--) {
        int qq;
        std::string vrp;
        for (int j = 1;j < n; j++) {
            vrp = vec[j];
            qq = j - 1;
            while (qq >= 0 && vec[qq][i] > vrp[i]) {
                swap(vec[qq + 1], vec[qq]);
                qq--;
            }
            vec[qq + 1] = vrp;
        }
    }
    for (int i = 0; i < n; ++i) {
        st=vec[i];
        std::cout<<st<<"\n";
    }
}