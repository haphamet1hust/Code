#include <iostream>
using namespace std;
struct node_dt{
    int he_so;
    int so_mu;
    node_dt *next;
};
struct Da_thuc {
    node_dt *first_node;
    node_dt *last_node;
};
void Init_list(Da_thuc * List) {
    List->first_node = 0;
}
node_dt* CallNode(int a,int b) {
    node_dt* p = new node_dt;
    p->he_so = a;
    p->so_mu = b;
    p->next = NULL;
    return p;
}
void add_node (Da_thuc * List, node_dt* p) {
    if (List -> first_node == 0) {
        List -> first_node = List ->last_node = p;
    }
    else {
        List ->last_node ->next = p;
        List ->last_node = p;
    }
}
void attach_node(Da_thuc * List,int heso,int somu) {
    node_dt *newnode = CallNode(heso,somu);
    if(newnode == NULL) return;
    add_node (List,newnode);
}
void tao_DT(Da_thuc *List) {
    int heso;
    int somu;
    int i = 0;
    do {
        i++;
        cout<<"Nhap phan tu thu "<<i<<endl;
        cout<<"\n Nhap he so ";
        cin>>heso;
        cout<<"\n Nhap so mu = ";
        cin>>somu;
        attach_node(List,heso,somu);
    }
    while(heso != 0);
}
void in_dt(Da_thuc * List) {
    if (List ->first_node == NULL) return;
    node_dt * temp = List ->first_node;
    while(temp != NULL) {
        cout << temp->he_so <<" * x^"<<temp->so_mu;
        if (temp ->next != NULL && temp->he_so !=0) cout<<" + ";
        temp = temp->next;
    }
}
int main() {
    Da_thuc dt;
    Init_list(&dt);
    tao_DT(&dt);
    in_dt(&dt);
}