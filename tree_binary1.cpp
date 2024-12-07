#include<iostream>
using namespace std;
struct Node{
    char data;
    Node *left;
    Node *right; 
};
typedef struct Node Tree;
void Init_Tree(Tree *T) {
    T ->left = T -> right = NULL;
}
int Empty_tree(Tree *T) {
    return T == NULL;
}
Tree *Left_child(Tree *T) {
    if (Empty_tree(T)) return NULL;
    else return T -> left;
}
Tree *Right_child(Tree *T) {
    if (Empty_tree(T)) return NULL;
    else return T -> right;
}
Tree *Create_Node(char data) {
    Tree *new_node = new Tree;
    new_node -> data = data;
    new_node ->left = NULL;
    new_node -> right = NULL;
    return new_node;
}
bool Is_leaf(Tree *T) {
    if(Left_child(T) == NULL && Right_child(T) == NULL) return true;
    else return false;
}
void Add_node(Tree *&T,char data) {
    Tree *new_node = Create_Node(data);
    if (T == NULL) T = new_node;
    else if(Left_child(T) == NULL) {
        T -> left = new_node;
    }

    
}
void Preorder(Tree *T) {
    if (T != NULL) cout<<T -> data<<' ';
    Preorder(T -> left);
    Preorder(T -> right);
}
void Inorder(Tree *T) {
    if (T != NULL) {
        Inorder(T -> left);
        cout<<T -> data<<' ';
        Inorder(T -> right);
    }
} 
void Postorder(Tree *T) {
    if (T != NULL) {
        Postorder(T -> left);
        Postorder(T -> right);
        cout<< T -> data<<' ';
    }
}
int main() {
    Tree *T = new Tree;
    const char data[] = "a5*b6^c*d/-hf-e12/^*";
    cout << "Trung to: ";
    Inorder(T);
    cout << endl;
    cout << "Tien to: ";
    Preorder(T);
    cout << endl;
    cout << "Hau to: ";
    Postorder(T);
    cout << endl;
    return 0;
}
