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
int main() {
    word_list *list = new word_list;
    list -> first_word = NULL;
    add_word(list,"I");
    add_word(list,"love");
    add_word(list,"love");
    add_word(list,"love");
    add_word(list,"love");
    add_word(list,"love");
    add_word(list,"love");
    add_word(list,"you");
    add_word(list,"so");
    add_word(list,"much");
    cout<<"My sentences is: ";
    word_node *temp = list -> first_word;
    while(temp != NULL) {
        cout<<temp -> word<<' ';
        temp = temp -> next;
    }
    cout<<endl;
    cout<<"The word is duplicated max: ";
    count_word(list);
    word_node *maximum_word = max_word(list);
    output_check(list,maximum_word);
    cout<<"Size of my sentences is: ";
    int size = size_list(list);
    cout<<size;
}


