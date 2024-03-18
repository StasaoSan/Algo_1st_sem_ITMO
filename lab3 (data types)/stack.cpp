#include <iostream>

struct Node {
    int value;
    Node* next;
};

struct Stack {
    Node* head = nullptr;
};

void Push(Stack& stack, int value) {
    Node* added = new Node{ value, nullptr };
    if (stack.head == nullptr) {
        stack.head = added;
    }
    else{
        Node* var = stack.head;
        stack.head=added;
        added->next=var;
    }

}

int Pop(Stack& stack) {
    int value = stack.head->value;
    Node* head=stack.head;
    stack.head=stack.head->next;
    delete head;
    return value;
}


int main(){
    Stack st;
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
            Push(st ,val);
        }
        else if (sim == '-'){
            mas[flag]=Pop(st);
            flag++;
        }
    }
    for (int i = 0; i < flag; ++i) {
        std::cout<<mas[i]<<"\n";
    }
}
