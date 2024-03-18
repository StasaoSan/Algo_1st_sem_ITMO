#include <stdio.h>

int main() {
    int nm[2], n, m;
    for (int i = 0, k; i < 2; i++) {
        scanf("%d", &k);
        nm[i] = k;}
    n = nm[0];
    m = nm[1];
    //Ввод плотов
    int plot[n * m], mesk;
    for (int j = 0, k; j < n * m; j++) {
        scanf("%d", &k);
        plot[j] = k;}
    //Начало ввода месклинтов
    scanf("%d", &mesk);
    int mmesk[mesk];
    for (int i = 0, k; i < mesk; i++) {
        scanf("%d", &k);
        mmesk[i] = k;}
    //Сортировка для массива плотов
    for (int i = 0; i < n * m; i++) {
        int key, j;
        key = plot[i];
        j = i - 1;
        while (j >= 0 && plot[j] > key) {
            plot[j + 1] = plot[j];
            j = j - 1;}
        plot[j + 1] = key;}
    //Сортировка для месклинтов
    for (int i = 0; i < mesk; i++) {
        int key, j;
        key = mmesk[i];
        j = i - 1;
        while (j >= 0 && mmesk[j] > key) {
            mmesk[j + 1] = mmesk[j];
            j = j - 1;}
        mmesk[j + 1] = key;}
    //смотрим что подходит а что нет) если подошло - замена на -1
    int count=0;
    for (int i=0; i<mesk;i++){ //по месклитам
        for (int j=0; j<n*m;j++) { //по плотам
            if (mmesk[i]<=plot[j] && mmesk[i]!=-1 && plot[j]!=-1) {
                plot[j]=-1;
                mmesk[i]=-1;
                count+=1;}}}
    printf("%d", count);}
