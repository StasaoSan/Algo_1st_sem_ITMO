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

int polnch(std::string s, int kol){
    int nach = kol;
    while (s[kol] != ' '){
        kol++;
    }
    int a;
    std::string s2 = s.substr(nach, kol);
    a=atoi(s2.c_str());
    return a;
}

int lenpolnch(std::string s, int kol){
    while (s[kol] != ' '){
        kol++;
    }
    return kol;
}

int main(){
    Stack st;
    std::string s;
    getline(std::cin, s);
    int len=s.size();
    int i=0;
    while (i<len){
        if (s[i] != ' ') {
            if (s[i]=='+'){
                int a, b, res;
                b = Pop(st);
                a = Pop(st);
                res=a+b;
                Push(st, res);
            }
            else if (s[i]=='-'){
                int a, b, res;
                b = Pop(st);
                a = Pop(st);
                res=a-b;
                Push(st, res);
            }
            else if (s[i]=='*'){
                int a, b, res;
                b = Pop(st);
                a = Pop(st);
                res=a*b;
                Push(st, res);
            }
            else if (s[i]=='/'){
                int a, b, res;
                b = Pop(st);
                a = Pop(st);
                res=a/b;
                Push(st, res);
            }
            else{
                int ch = polnch(s, i);
                int k = lenpolnch(s, i);
                Push(st, ch);
                i=k;
            }
        }
        i++;
    }
    int res;
    res=Pop(st);
    std::cout<<res;
}
