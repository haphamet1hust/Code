#include<iostream>
using namespace std;
//const int max_const =100;
struct File_node {
    int size;
    char const *name;
    double addr;
    double time;
    File_node *next;
};

struct Dir {
    File_node * head;
    File_node * tail;
};
File_node *make_file(int size,const char *name,double addr,double time) {
    File_node *new_file = new File_node;
    new_file -> size = size;
    new_file -> name = name;
    new_file -> addr = addr;
    new_file -> time = time;
    new_file -> next = NULL;
    return new_file;
}
void add_file (Dir *dir,int size,const char *name,double addr,double time) {
    File_node * new_file = make_file(size,name,addr,time);
    if (dir -> head == NULL) {
        dir -> head = new_file;
        dir -> tail = dir -> head;
    }
    if (dir -> head -> time >= new_file -> time) {
        new_file -> next = dir -> head;
        dir -> head = new_file;
    }
    if (dir -> tail -> time <= new_file -> time) {
        dir -> tail -> next = new_file;
        dir -> tail = new_file;
    }
}
void copy_paste(Dir *dir,int size,const char*name,double addr,double time) {
    File_node *new_file = make_file(size,name,addr,time);
    if (dir ->head == NULL) dir -> head = new_file;
    else if (dir -> head -> time >= new_file -> time) {
        new_file -> next = dir -> head;
        dir -> head = new_file;
    }
    else if (dir -> tail -> time <= new_file -> time ) {
        dir -> tail -> next = new_file;
        dir ->tail = new_file;
    }
    else {
    File_node *temp = dir -> head;
    while(temp != NULL && temp -> next -> time < new_file -> time) {
        temp = temp -> next;
    }
    new_file -> next = temp -> next;
    temp -> next = new_file;
    }
}
int dir_size(Dir *dir) {
    if (dir ->head == NULL) return 0;
    int dir_size = 0;
    File_node *temp = dir -> head;
    while(temp != NULL) {
        dir_size += temp -> size;
        temp = temp -> next;
    } 
    return dir_size;
}
File_node *insert_node(File_node *sorted,File_node *newNode) {
    if (sorted == NULL || sorted -> size >= newNode ->size) {
        newNode -> next = sorted;
        sorted = newNode;
    } 
    else {
        File_node *temp = sorted;
        while (temp -> next != NULL && temp -> next -> size < newNode -> size) {
            temp = temp -> next;
        }
        newNode -> next = temp -> next;
        temp -> next = newNode;
    }
    return sorted;
 }
void sort(Dir *dir) {
    File_node *sorted = NULL;
    if (dir -> head == NULL) return;
    File_node *temp = dir -> head;
    while (temp != NULL) {
        File_node *next = temp -> next;
        sorted = insert_node(sorted,temp);
        temp = next;
    }
 }
void delete_file(Dir *dir,int sum_size) {
    if (sum_size <= 32) return;
    else {
        File_node *delete_node = dir -> head;
        dir -> head = dir -> head ->next;
        sum_size -= delete_node -> size;
        delete delete_node;
        delete_file (dir,sum_size);
    }
}
int main() {
    Dir *dir = new Dir;
    dir->head=dir->tail=NULL;
    add_file(dir,3,"abc",3,15);
    add_file(dir,6,"def",6,20);
    add_file(dir,5,"ghi",5,10);
    add_file(dir,11,"abc",11,5);
    add_file(dir,1,"abc",1,100);
    copy_paste(dir,15,"xyz",10,1);
    copy_paste(dir,4,"xyz",4,1000);
    cout<<"Size of my directory is : ";
    cout<<dir_size(dir)<<endl;
    cout<<"List of file in my directory forwarding to time is: "<<endl;
    for(File_node *temp = dir -> head ;temp != NULL;temp = temp -> next) {
        cout<<temp -> time<<' ';
    }
    sort(dir);
    for(File_node *tmp = dir -> head ;tmp != NULL;tmp = tmp -> next) {
        cout<<tmp -> size<<endl;
    }
}






