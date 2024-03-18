#include <stdio.h>

int main() {
    int len, sp[1001][2];
    scanf("%d", &len);
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < 2; ++j) {
            scanf("%d", &sp[i][j]);
        }
    }
    for (int i = 1; i < len; ++i) {
        int num=sp[i][0], ball=sp[i][1];
        for (int j = i-1; j >=0; j--) {
            if (ball>sp[j][1]){
                sp[j+1][1]=sp[j][1];
                sp[j][1]=ball;
                sp[j+1][0]=sp[j][0];
                sp[j][0]=num;
            }
            if (ball == sp[j][1]){
                if (num<sp[j][0]){
                    sp[j+1][0]=sp[j][0];
                    sp[j][0]=num;
                }
            }
        }
    }
    for (int i = 0; i < len; i++){
        for (int j = 0; j < 2; j++) {
            printf("%d ", sp[i][j]);
        }
        printf("\n");
    }
    return 0;
}
