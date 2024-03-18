#include <iostream>

struct Node {
    int value;
    Node* next;
};

struct Queue {
    Node* head = nullptr;
    Node* tail = nullptr;
};

void Push(Queue& queue, int value) {
    Node* added = new Node{ value, nullptr };
    if (queue.head == nullptr) {
        queue.head = added;
    }
    else {
        queue.tail->next = added;
    }
    queue.tail = added;
}

int Pop(Queue& queue) {
    int value = queue.head->value;
    if (queue.head == queue.tail) {
        queue.tail = nullptr;
    }
    Node* next = queue.head->next;
    delete queue.head;
    queue.head = next;
    return value;
}


int main(){
    Queue och;
    int kol;
    char sim;
    std::cin>>kol;
    int mas[kol];
    int flag=0;
    for (int i = 0; i < kol; i++) {
        std::cin>>sim;
        if (sim=='x' || sim =='+'){
            int val;
            std::cin>>val;
            Push(och ,val);
        }
        else if (sim == '-'){
            mas[flag]=Pop(och);
            flag++;
        }
    }
    for (int i = 0; i < flag; ++i) {
        std::cout<<mas[i]<<"\n";
    }
}
