#include<iostream>
using namespace std;
void swap(int &a,int &b) {
    int temp = a;
    a = b;
    b = temp;
}
void selection_sort(int a[],int n) {
    for(int i = 0;i < n - 1;i++) {
        int min_index = i;
        for(int j = i + 1;j < n;j++) {
            if (a[min_index] > a[j]) min_index = j;
        }
        swap(a[i],a[min_index]);
    }
}
void insert_sort(int a[],int n) {
      for(int i = 0;i < n;i++) {
        int temp = a[i];
        int j = i;
        while(j > 0 && a[j-1] > temp)  {
            a[j] = a[j-1];
            j--;
        }
        a[j] = temp;
      }
}
int main() {
    int n;
    cin>>n;
    int a[n];
    for(int i = 0;i < n;i++) {
        cin>>a[i];
    }
    selection_sort(a,n);
    for(int i = 0;i < n;i++) {
        cout<<a[i]<<' ';
    }
}