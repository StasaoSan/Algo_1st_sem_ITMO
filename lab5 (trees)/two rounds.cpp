#include <iostream>
#include <vector>
int i = 0;

void postorder(std::vector<int> &vec, int min, int max) {
    if (i == vec.size() || vec[i]>max || vec[i]<min){
        return;
    }

    int val = vec[i];
    i++;

    postorder(vec, min, val);
    postorder(vec, val, max);
    std::cout<<val<<" ";
}

int main()
{
    int n;
    std::cin>>n;
    std::vector<int> vec(n);
    for (int j = 0; j < n; ++j) {
        std::cin>>vec[j];
    }
    postorder(vec, -200010, 200010);
    return 0;
}