#include <iostream>
using namespace std;
void swap(int &a,int &b) {
    int temp = a;
    a = b;
    b = temp;
}
void sap_xep(int a[],int n) {
    for(int i=0;i<n-1;i++) {
        for(int j=i+1;j<n;j++) {
            if (a[i]>a[j]) {
                swap(a[i],a[j]);
            }
        }
    }
}
void ma_hoa(int x) {
    switch (x) {
        case 0: {
            cout<<"red";
            break;
        }
        case 1: {
            cout<<"white";
            break;
        }
        case 2: {
            cout<<"blue";
            break;
        }
    }
}
int main() {
    int n;
    cout<<"Nhap n:"<<endl;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) {
        cin>>a[i];
        ma_hoa(a[i]);
        cout<<" ";
    }
    sap_xep(a,n);
    cout<<endl;
    for(int i=0;i<n;i++) {
       ma_hoa(a[i]);
       cout<<" ";
    }   
    return 0;
}