#include <iostream>
#include <cmath>
struct Node {
    int value;
    int qmax;
    Node* next;
};

struct Stack {
    Node* head = nullptr;
};

int empty(Stack& stack){
    if (stack.head == nullptr){
        return 0;
    }
    else{
        return 1;
    }
}

void Push(Stack& stack, int value) {
    Node* added = new Node{value, 0, nullptr};
    if (empty(stack)==0) {
        stack.head = added;
        stack.head->qmax=value;
    }
    else{
        Node* var = stack.head;
        stack.head=added;
        added->next=var;
        if (value>stack.head->next->qmax){
            stack.head->qmax=value;
        }
        else {
            stack.head->qmax = stack.head->next->qmax;
        }
    }
}

void Pop(Stack& stack) {
    int locmax = stack.head->qmax;
    stack.head=stack.head->next;
    if (locmax<stack.head->qmax){
        stack.head->qmax=locmax;
    }
}

void qmax(Stack &stack){
    int max;
    max=stack.head->qmax;
    std::cout<<max<<"\n";
}

int main(){
    Stack st;
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int kol;
    char sim;
    std::cin>>kol;

    for (int i = 0; i < kol; i++) {
        std::string s;
        std::cin>>s;
        if (s[0] == 'x' || s[0] == '+'){
            int val;
            std::cin>>val;
            Push(st ,val);
        }
        else if (s[0] == '-'){
            Pop(st);
        }
        else if (s=="max"){
            qmax(st);
        }
    }
}