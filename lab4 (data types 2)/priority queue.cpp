#include <iostream>
#include <vector>
#include <unordered_map>


void siftup(std::vector<std::pair<int, int>>& vec1, int i) {
    if (i == 0) {
        return;
    }
    int parent = (i - 1) / 2;
    if (vec1[parent].first > vec1[i].first) {
        std::swap(vec1[parent], vec1[i]);
        siftup(vec1, parent);
    }
}

void siftdown(std::vector<std::pair<int, int>>& vec1, int i) {
    if (2 * i + 1 >= vec1.size()) {
        return;
    }
    int j = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (vec1[left].first < vec1[j].first) {
        j = left;
    }
    if (right < vec1.size() && vec1[right].first < vec1[j].first) {
        j = right;
    }
    if (j == i) {
        return;
    }
    std::swap(vec1[j], vec1[i]);
    siftdown(vec1, j);
}

void push(std::vector<std::pair<int, int>>& vec1, int pos, int key) {
    vec1.push_back({ key, pos });
    siftup(vec1, vec1.size() - 1);
}

int64_t ExtractMin(std::vector<std::pair<int, int>>& vec1) {
    if (vec1.size() != 0) {
        int res = vec1[0].first;
        std::swap(vec1[0], vec1[vec1.size() - 1]);
        vec1.pop_back();
        siftdown(vec1, 0);
        return res;
    }
}

void DecreaseKey(std::vector<std::pair<int, int>>& vec1, std::unordered_map<int, int>& vec2, int pos, int y) {
    for (int i = 0; i < vec1.size(); ++i)
    {
        if (vec1[i].second == pos) {
            if (vec1[i].first > y) {
                vec1[i].first = y;
                siftup(vec1, i);
            }
        }
    }
}

int main() {
    std::string a;
    std::vector<std::pair<int, int>> vec1;
    std::unordered_map<int, int> vec2;
    int number = 1;
    while (std::cin >> a) {
        if (a == "push") {
            int ch;
            std::cin >> ch;
            push(vec1, number, ch);
        }
        else if (a == "extract-min") {
            int c;
            if (vec1.empty()) {
                std::cout << "*" << "\n";
                number++;
                continue;
            }
            c = ExtractMin(vec1);
            std::cout << c << "\n";
        }
        else if (a == "decrease-key") {
            int x;
            int y;
            std::cin >> x >> y;
            DecreaseKey(vec1, vec2, x, y);
        }
        ++number;
    }
}