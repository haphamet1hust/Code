#include<iostream>
using namespace std;
struct word_node {
    const char *word;
    int check;
    word_node *next;
};
struct word_list {
    word_node *first_word;
};
word_node *create_word(const char *word) {
    word_node *new_word = new word_node;
    new_word -> word = word;
    new_word -> check = 0;
    new_word -> next =NULL;
    return new_word;
}
void add_word(word_list *list,const char *word) {
    word_node *new_node = create_word(word);
    if (list -> first_word == NULL) list -> first_word = new_node;
    else {
        word_node *temp = list -> first_word;
        while (temp -> next != NULL) {
            temp = temp -> next;
        }
        temp -> next = new_node;
    }
}
void count_word(word_list *list) {
    if (list -> first_word == NULL) return;
    else {
        for (word_node *temp = list -> first_word;temp -> next != NULL;temp = temp -> next) {
            for(word_node *tmp = temp -> next;tmp != NULL;tmp = tmp -> next) {
                if (temp -> word == tmp -> word) temp -> check += 1;
            }
        }
    }
}
word_node *max_word(word_list *list) {
    if (list -> first_word == NULL) return 0;
    word_node *max_word = list -> first_word;
    word_node *temp = list -> first_word;
    while(temp != NULL) {
        if(temp -> check >= max_word -> check) max_word = temp;
        temp = temp -> next;
    }
    return max_word;
}
void output_check(word_list *list,word_node *max_word) {
  cout << max_word -> word << endl;
}
int size_list(word_list *list) {
    int size_list = 0;
    for(word_node *temp = list -> first_word;temp != NULL;temp = temp -> next) {
        size_list += 1;
    }
    return size_list;
}
void same_word(word_list *list) {
    if (list -> first_word == NULL) return;
    for(word_node *temp = list -> first_word;temp -> next != NULL;temp = temp -> next) {
        if (temp -> next -> word == temp -> word) {
            word_node *delete_word = temp;
            delete delete_word; 
        }
    }
}
void output(word_list *list) {
     word_node *temp = list -> first_word;
     while(temp != NULL) {
        cout<<temp -> word<<' ';
        temp = temp -> next;
     }
}
int main() {
    word_list *list = new word_list;
    list -> first_word = NULL;
    add_word(list,"que");
    add_word(list,"em");
    add_word(list,"co");
    add_word(list,"canh");
    add_word(list,"dong");
    add_word(list,"xanh");
    add_word(list,"xanh");
    add_word(list,"thang");
    add_word(list,"canh");
    add_word(list,"co");
    add_word(list,"bay");
    cout<<"Cau nhap vao la: ";
    word_node *temp = list -> first_word;
    output(list);
    cout<<endl;
    cout<<"Tu xuat hien nhieu nhat trong cau la:  ";
    count_word(list);
    word_node *maximum_word = max_word(list);
    output_check(list,maximum_word);
    cout<<"So tu vung trong cau la:  ";
    int size = size_list(list);
    cout<<size<<endl;
    same_word(list);
   // cout<<"Cau sau khi loai bo tu la: ";
    output(list);
}


