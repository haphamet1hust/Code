#include<iostream>
using namespace std;
const int MAX = 100;
struct wood {
    const char* type;
    int size;
    int year;
};
struct stack {
    int top;
    wood data[MAX];
};
void Init(stack& S) {
    S.top = 0;
}
int stack_empty(stack S) {
    return S.top == 0;
}
int stack_full (stack S) {
    return S.top == MAX;
}
void push_wood(stack& S,const char *type,int size,int year) {
    if (stack_full(S)) cout<<"Kho go day";
    else {
        wood w;
        w.type = type;
        w.size = size ;
        w.year = year;
        S.data[S.top] = w;
        S.top++;
    }
}
wood pop_wood(stack& S) {
    if (stack_empty(S)) {
        cout<<"Kho trong";
        return {};
    }
    else {
        S.top--;
        wood w = S.data[S.top];
        return w;
    }
}
void output(stack S) {
    while (S.top != 0) {
        wood w = pop_wood(S);
        cout<< w.type<<' '<<w.size<<' '<<w.year<<endl;
    }
}
int count(stack S,int x) {
    if (stack_empty(S)) return 0;
    else {
        int c = 0;
        while(S.top != 0) {
            S.top--;
            wood w = pop_wood(S);
            if (w.year == x) c++;
        }
        return c;
    }
}
int main() {
    stack S;
    Init(S);
    push_wood(S,"soi",20,10);
    push_wood(S,"gu",30,10);
    push_wood(S,"oc cho",10,30);
    push_wood(S,"lim",20,100);
    int x;
    do {
        cin>>x;
    }
    while(x < 0);
    count(S,x);
    output(S);
}
