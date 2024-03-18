#include <iostream>
#include <vector>
int main() {
    int kol;
    std::cin>>kol;
    std::vector<int> vec(kol);
    for (int i = 0; i < kol; ++i) {
        std::cin>>vec[i];
    }
    unsigned int q;
    std::cin>>q;
    for (unsigned int i = 0; i < q; ++i) {
        int l = 0, r=kol-1, key;
        std::cin>>key;
        //правая
        while (l<=r){
            int mid=(l+r)/2;
            if (vec[mid]<=key){
                l=mid+1;
            } else{
                r=mid-1;
            }
        }
        //
        int l1=0, r1=kol-1;
        while (l1<=r1){
            int mid=(l1+r1)/2;
            if (vec[mid]>=key){
                r1=mid-1;
            } else{
                l1=mid+1;
            }
        }

        if (l1>r){
            std::cout<<"-1 -1"<<"\n";
            continue;
        }
        std::cout<<l1+1<<" "<<r+1<<"\n";
    }
    return 0;
}
