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
void bubble_sort(int a[],int n) {
    for(int i = 0;i < n-1;i++) {
        for(int j = n-1;j > i;j--) {
            if (a[j-1] > a[j]) swap(a[j],a[j-1]);
        }
    }
}
void partition(int a[],int left,int right) {
    if (left >= right) return;
    int x = a[left];
    int i = left + 1;
    int j =right;
    while(i <= j) {
        while(a[i] <= x && i <= j) i++;
        while(a[j] > x && i <= j) j--;
        if (i < j) swap(a[i],a[j]);
    }
    swap(a[left],a[j]);
    partition(a,left,j-1);
    partition(a,j+1,right);
}
void quick_sort(int a[],int n) {
    partition(a,0,n-1);
} 
int main() {
    int n;
    cin>>n;
    int a[n];
    for(int i = 0;i < n;i++) {
        cin>>a[i];
    }
    //quick_sort(a,n);
  // selection_sort(a,n);
   // insert_sort(a,n);
  // bubble_sort(a,n);
    for(int i = 0;i < n;i++) {
        cout<<a[i]<<' ';
    }
}