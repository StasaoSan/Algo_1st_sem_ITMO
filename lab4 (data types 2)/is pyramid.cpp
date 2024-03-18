#include <iostream>
#include <vector>

int main() {
    int len;
    std::cin>>len;
    std::vector<int> vec(len+1);
    for (int i = 1; i < len+1; ++i) {
        std::cin>>vec[i];
    }
    bool flag=true;
    for (int i = 1; i < len/2; ++i) {
        if (vec[i]>vec[2*i]){
            if (2*i<len){
                flag=false;
                break;
            }
        }
        if (vec[i]>vec[(2*i)+1]){
            if (2*i+1<len){
                flag=false;
                break;
            }
        }
    }
    if (flag){
        std::cout<<"YES";
    }
    else{
        std::cout<<"NO";
    }
    return 0;
}
