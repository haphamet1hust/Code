#include<iostream>
using namespace std;
const int MAX = 10;
struct goods {
    int price;
    const char* name_goods;
    bool is_paid = false;
    goods* next;
};
struct queue{
    goods* rear;
    goods* front;
    int count;
};
void init(queue* q) {
    q -> rear = q -> front = NULL;
    q -> count = 0;
}
int underflow(queue* q) {
    return q -> front == NULL? 1:0;
}
int overflow(queue* q) {
    return q -> count >= MAX;
}
goods* define_goods(int price,const char* name_goods) {
    goods* newnode = new goods;
    newnode -> price = price;
    newnode -> name_goods = name_goods;
    newnode -> next = NULL;
    return newnode;
}
void enqueue(queue* q,int price,const char* name_goods) {
    goods* newnode = define_goods(price,name_goods);
    if (overflow(q)) {
        return;
    }
    else if(q -> rear == NULL) {
        q -> rear = q -> front = newnode;
    }
    else {
        q -> rear -> next = newnode;
        q -> rear = newnode;
    }
    q -> count++;
}
void pay(goods* newnode) {
    newnode -> is_paid = true;
}
void confirm(queue* q,int n) {
    goods* temp = q -> front;
    for(int i = 1;i <= n;i++) {
        pay(temp);
        temp = temp -> next;
    }
}
void dequeue(queue* q) {
    if (underflow(q)) {
        cout<<"Queue empty!";
        return;
    }
    else{
        goods* customer = q -> front;
        if(customer -> is_paid == true) {
            q -> front = q -> front -> next;
            delete customer;
        }
    }
}
int sum_money(queue* q) {
    if (underflow(q)) return 0;
    else {
        int sum = 0;
    goods* temp = q -> front;
    while(temp != NULL) {
        sum += temp -> price;
        temp = temp -> next;
    }
    return sum;
    }
}
bool compare_name(const char*name_1,const char *name_2) {
    while(*name_1 != '\0' && *name_2 != '\0') {
        if (*name_1 != *name_2) return false;
        name_1++;
        name_2++; 
    }
    return *name_1 =='\0' && *name_2 =='\0'? true:false;
}
int same_goods(queue* q,const char* name_goods) {
   if (underflow(q)) return 0;
   else {
    int count = 0;
    goods* temp = q -> front;
    while (temp != NULL) {
        if (compare_name(temp -> name_goods,name_goods)) count++;
        temp = temp -> next;
    }
    return count;
   }
}
void print(queue* q) {
    goods* temp = q -> front;
    while(temp != NULL) {
        cout<< temp -> name_goods<<' '<< temp -> price<<endl;
        temp = temp -> next;
    }
}
int main() {
    queue* q = new queue;
    init(q);
    cout<<"Danh sach nhung nguoi cho thanh toan:"<<endl;
    enqueue(q,5000,"sua");
    enqueue(q,600,"nuoc ngot");
    enqueue(q,700,"bia");
    enqueue(q,800,"cocacola");
    enqueue(q,900,"rau");
    enqueue(q,1000,"nuoc ngot");
    enqueue(q,1100,"ca");
    enqueue(q,600,"nuoc ngot");
    print(q);
    cout<<"So tien thu duoc sau mot phien lam viec:"<<sum_money(q);
    cout<<endl;
    cout<<"Nhap hang hoa can kiem tra: ";
    char c[100];
    cin.getline(c,100);
    const char* name_goods = c;
    cout<<"So san pham "<<name_goods<<" da duoc mua la:"<<same_goods(q,name_goods)<<endl;
    cout<<"Nhap vao so nguoi da thanh toan: ";
    int n;
    do {
        cin>>n;
    }
    while (n <= 0 || n > MAX);
    cout<<"Danh sach nhung nguoi con lai: "<<endl;
    confirm(q,n);
    while (n > 0) {
        dequeue(q);
        n--;
    }
    print(q);
    delete q;
}
