#include<iostream>
using namespace std;
const int number = 51;
typedef struct population {
    int year;
    int people_number;
} population; //tạo struct quản lí dân số 
population p[number]; //tạo mảng chứa các đối tượng kiểu struct

/*Hàm đưa dữ liệu đầu vào*/
void input() {
    for (int i = 0;i < number;i++) {
        cout<<"Nhap thong tin nam ";
        cin>>p[i].year;
        cout<<"Nhap thong tin so nguoi sinh ra trong nam do ";
        cin>>p[i].people_number;
    }
}

/*Hàm in dữ liệu đầu ra từ đầu vào*/
void output() {
    for (int i = 0;i < number;i++) {
        cout<<p[i].year<<' ';
        cout<<p[i].people_number<<endl;
    }
}

/*Hàm in ra năm có số người sinh ra nhiều nhất*/
void max_people() {
    int max_index = 0;
    int max = p[0].people_number;
    for(int i = 1;i < number;i++) {
        if(max < p[i].people_number) {
            max = p[i].people_number;
            max_index = i;
        }
    }
    cout<<p[max_index].year<<endl;
}

/*Hàm in năm có số người sinh ra ít nhất*/
void min_people() {
    int min_index = 0;
    int min = p[0].people_number;
    for(int i = 1;i < number;i++) {
        if(min > p[i].people_number) {
            min = p[i].people_number;
            min_index = i;
        }
    }
    cout<<p[min_index].year<<endl;
}

/*Hàm đếm tổng số năm có cùng số người sinh ra*/
void same_numberpeople(int n) {
    int count = 0;
    for(int i = 0;i < number;i++) {
        if(n == p[i].people_number) count++;
    }
    cout<<count;
}

/*Hàm in ra số năm có cùng số người sinh ra*/
void numberyear_samenumber() {
    for(int i = 0;i < number;i++) {
        same_numberpeople(p[i].people_number);
        cout<<endl;
    }
}
int main() {
    input();
    output();
    max_people();
    min_people();
    numberyear_samenumber();
}