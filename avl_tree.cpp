#include<iostream>
using namespace std;
struct AVL_Node {
    int data;
    AVL_Node *left;
    AVL_Node *right;
    int height;
};
AVL_Node *Create_node(int data,int height) {
    AVL_Node *Newnode = new AVL_Node;
    Newnode -> data = data;
    Newnode -> left = NULL;
    Newnode -> right = NULL;
    Newnode -> height = height;
    return Newnode;
}
int High_Node(AVL_Node *P) {
    return P == NULL? -1: P ->height;
}
void Rootate_Right(AVL_Node *&K_2) {
    AVL_Node *K_1 = K_2 -> left;
    K_1 -> right = K_2;
    K_2 -> left = K_1 -> right;
    if (K_2 -> left -> height < K_2 -> right -> height)  K_2 -> height = K_2 -> right -> height + 1;
    else K_2 -> height = K_2 -> left -> height + 1;
    if (K_1 -> left -> height < K_2 -> height) K_1 -> height = K_2 -> height + 1;
    else K_1 -> height = K_1 -> left -> height + 1;
    K_2 = K_1;
}
void Rootate_Left(AVL_Node *&K_2) {
    AVL_Node *K_1 = K_2 -> right;
    K_1 -> left = K_2;
    K_2 -> right = K_1 -> left;
    if (K_2 -> left -> height < K_2 -> right -> height)  K_2 -> height = K_2 -> right -> height + 1;
    else K_2 -> height = K_2 -> left -> height + 1;
    if (K_1 -> left -> height < K_2 -> height) K_1 -> height = K_2 -> height + 1;
    else K_1 -> height = K_1 -> left -> height + 1;
    K_2 = K_1;
}
void DoubleWith_Left(AVL_Node *K_3) {
    Rootate_Right(K_3 -> left);
    Rootate_Left(K_3);
}
void DoubleWith_Right(AVL_Node *&K_3) {
    Rootate_Left(K_3->right); 
    Rootate_Right(K_3);       
}

AVL_Node* Balance(AVL_Node *T) {
    if (T == NULL) return T;

    // Kiểm tra hệ số cân bằng
    int balance = High_Node(T->left) - High_Node(T->right);

    // Nặng bên trái
    if (balance > 1) {
        if (High_Node(T->left->left) >= High_Node(T->left->right)) {
            Rootate_Right(T); // Xoay đơn bên phải
        } else {
            DoubleWith_Left(T); // Xoay kép trái-phải
        }
    }
    // Nặng bên phải
    else if (balance < -1) {
        if (High_Node(T->right->right) >= High_Node(T->right->left)) {
            Rootate_Left(T); // Xoay đơn bên trái
        } else {
            DoubleWith_Right(T); // Xoay kép phải-trái
        }
    }

    // Cập nhật lại chiều cao
    T->height = max(High_Node(T->left), High_Node(T->right)) + 1;
    return T;
}

AVL_Node* Insert(AVL_Node *T, int data) {
    if (T == NULL) {
        return Create_node(data, 0); // Tạo nút mới
    }

    if (data < T->data) {
        T->left = Insert(T->left, data); // Thêm vào nhánh trái
    } else if (data > T->data) {
        T->right = Insert(T->right, data); // Thêm vào nhánh phải
    } else {
        // Dữ liệu trùng lặp, không thêm
        return T;
    }

    // Cân bằng lại cây sau khi thêm nút
    return Balance(T);
}
void InOrder(AVL_Node *T) {
    if (T != NULL) {
        InOrder(T->left);
        cout << T->data << " ";
        InOrder(T->right);
    }
}
void PreOrder(AVL_Node *T) {
    if (T != NULL) {
        cout << T->data << " ";
        PreOrder(T->left);
        PreOrder(T->right);
    }
}
void PostOrder(AVL_Node *T) {
    if (T != NULL) {
        PostOrder(T->left);
        PostOrder(T->right);
        cout << T->data << " ";
    }
}

int main() {
    AVL_Node *root = NULL;

    int numbers[] = {50, 30, 70, 20, 40, 60, 80};
    for (int num : numbers) {
        root = Insert(root, num);
    }

    cout << "Duyệt cây theo thứ tự in-order: ";
    InOrder(root);
    cout << "\n";

    cout << "Duyệt cây theo thứ tự pre-order: ";
    PreOrder(root);
    cout << "\n";

    cout << "Duyệt cây theo thứ tự post-order: ";
    PostOrder(root);
    cout << "\n";

    return 0;
}