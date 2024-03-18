#include <stdio.h>

void sort(int sp[], int len);

int main(){
    int len;
    scanf("%d", &len);
    int sp[len];
    for (int i = 0, n; i < len; i++) {
        scanf("%d", &n);
        sp[i] = n;
    }
    sort(sp, len);
    for (int i = 0; i < len; ++i) {
        printf("%d ", sp[i]);
    }
}


void sort(int sp[], int len) {
    int i = 0, j = len - 1, mid = sp[len / 2];

    while (i <= j) {
        while(sp[i] < mid) {
            i++;
        }
        while(sp[j] > mid) {
            j--;
        }
        if (i <= j) {
            int t = sp[i];
            sp[i] = sp[j];
            sp[j] = t;
            i++;
            j--;
        }
    }
    if (j > 0) {
        sort(sp, j+1);
    }
    if (i < len) {
        sort(sp+i, len - i);
    }
}