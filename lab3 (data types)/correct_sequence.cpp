#include <iostream>

struct Node {
    char value;
    Node* next;
};

struct Stack {
    Node* head = nullptr;
};

void Push(Stack& stack, char value) {
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
    char value = stack.head->value;
    stack.head=stack.head->next;
    return value;
}

int empty(Stack& stack){
    if (stack.head == nullptr){
        return 0;
    }
    else{
        return 1;
    }
}

char el(Stack &stack){
    char a;
    a=stack.head->value;
    return a;
}

void yesno(Stack& stack){
    if (empty(stack)==0){
        std::cout<<"YES"<<"\n";
    }
    else{
        std::cout<<"NO"<<"\n";
    }
}


int main(){
    std::string s;
    while (std::cin>>s) {
        Stack st;
        int kol=s.size();
        for (int i = 0; i < kol; ++i) {
            if (s[i] == '(' || s[i] == '[') {
                Push(st, s[i]);
            } else {
                if (empty(st)!=0 && el(st) == '(' && s[i] == ')') {
                    Pop(st);
                } else if (empty(st)!=0 && el(st) == '[' && s[i] == ']') {
                    Pop(st);
                } else if (s[i] == ']' || s[i] == ')') {
                    Push(st, s[i]);
                }
            }
        }
        yesno(st);
    }
}
