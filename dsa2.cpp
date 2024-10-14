#include<iostream>
#include<cmath>
using namespace std;
bool prime(int n) {
    for(int i=2;i<sqrt(n);i++) {
        if(n%i==0) return false;
    }
    return true;
}
void insert_sort(int a[],int n) {
    for(int i=0;i<n;i++) {
        int x = a[i];
        int j = i;
        while(j>0 && a[j-1] > a[j]) {
            a[j] = a[j-1];
            j--;
        }
        a[j] = x;
    }
}
bool semi_prime(int n) {
    for(int i = 2;i < sqrt(n);i++) {
        if (prime(i) && n % i == 0){
            if (prime(n / i)) return true;
        }
    }
    return false;
}
void semiprime_sum(int b[],int n) {
    int sum;
    for(int i = 2;i < n;i++) {
        sum = b[i];
        for(int j = 0;j < i;j++) {
            for(int k = j+1;k < i;k++) {
                if(sum == b[j]+b[k]) cout<<b[j]<<' '<<b[k]<<endl;
            }
        }
    }
}
bool check_blum(int b[],int n,int x) {
    for (int i = 0;i < n;i++) {
        if (x == b[i]) return true;
    }
    return false;
}
int main() {
    int n;
    cin>>n;
    int a[n];
    int b[n];
    for(int i = 0;i < n;i++) {
        cin>>a[i];
        if (semi_prime(a[i])) b[i] = a[i];
    }
    int x;
    cin>>x;
    if (check_blum(b,n,x)) cout<<"Exist a blum number from input in array"<<endl;
    else cout<<"Not exist a blum number from input in array"<<endl;
    insert_sort(b,n);
    semiprime_sum(b,n);
}
