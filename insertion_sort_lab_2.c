#include <stdio.h>

int main() {
    int len;
    scanf("%d", &len);
    int sp[len];
    for (int i=0, n; i<len; i++){
        scanf("%d", &n);
        sp[i]=n;}
    for (int i=0;i<len;i++){
        int key, j;
        key=sp[i];
        j=i-1;
        while (j>=0 && sp[j]>key){
            sp[j+1]=sp[j];
            j=j-1;
        }
        sp[j+1]=key;
    }
    for (int i=0; i<len; i++){
        printf("%d ", sp[i]);
    }
}
