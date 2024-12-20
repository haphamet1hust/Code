#include<iostream>
using namespace std;
const int MAX = 100;
struct Node{
    string title;//ten tieu de
    int page_number;//so trang
    Node * firstChild;//con dau tien
    Node* nextSibling;//anh em ke tiep
};
//Ham tao mot node moi
Node *create_node(string title,int page_number) {
    Node* newnode = new Node;
    newnode -> title = title;
    newnode -> page_number = page_number;
    newnode -> firstChild = newnode -> nextSibling = NULL;
    return newnode;
}
// Hàm xây dựng cây 
Node* buildTree(Node *root,string title,int page_number) {
    Node * newnode = create_node(title,page_number); //tạo node mớimới
    if (root == NULL) root = newnode; 
    else {
        Node *temp = root;
    if (temp->firstChild == NULL) {
            temp->firstChild = newnode; 
        } 
        else {
            temp = temp->firstChild;
            while (temp->nextSibling != NULL) {
                temp = temp->nextSibling;
            }
            temp->nextSibling = newnode;
        }
    }
}
void printtree (Node *root,int level) {
    if (root == NULL) return;
    for (int i = 0;i <= level;i++) {
        cout<<" ";
    }
    cout<<root -> title<<' '<<root -> page_number<<endl;
    printtree(root -> firstChild,level + 1);
    printtree (root -> nextSibling,level);
}
int countChapters(Node* root) {
    if (root == NULL) return 0;

    // Đếm node trong danh sách anh em (cùng cấp)
    int count = 0;
    Node* temp = root;
    while (temp != NULL) {
        count++;
        temp = temp->nextSibling;
    }

    return count;
}
Node* findLongestChapter(Node* root) {
    if (root == NULL) return NULL;

    Node* longest = root;
    Node* temp = root->nextSibling;

    // Duyệt qua các node anh em để tìm node có `page_number` lớn nhất
    while (temp != NULL) {
        if (temp->page_number > longest->page_number) {
            longest = temp;
        }
        temp = temp->nextSibling;
    }

    return longest;
}
Node* deleteNode(Node* root, string title) {
    if (root == NULL) return NULL;

    // Nếu node cần xóa là root
    if (root->title == title) {
        // Nếu có con, chuyển con đầu tiên thành root mới
        if (root->firstChild != NULL) {
            Node* newRoot = root->firstChild;

            // Gắn các anh em của root vào cuối danh sách anh em của con đầu tiên
            Node* temp = newRoot;
            while (temp->nextSibling != NULL) {
                temp = temp->nextSibling;
            }
            temp->nextSibling = root->nextSibling;

            delete root; // Xóa node cũ
            return newRoot;
        } else {
            // Nếu không có con, trả về anh em tiếp theo
            Node* newRoot = root->nextSibling;
            delete root;
            return newRoot;
        }
    }

    // Tìm trong danh sách con
    root->firstChild = deleteNode(root->firstChild, title);

    // Tìm trong danh sách anh em
    root->nextSibling = deleteNode(root->nextSibling, title);

    return root;
}
int updatePageNumbers(Node* root) {
    if (root == NULL) return 0;

    // Cập nhật số trang của các node con
    int totalPages = root->page_number;
    Node* temp = root->firstChild;

    while (temp != NULL) {
        totalPages += updatePageNumbers(temp);
        temp = temp->nextSibling;
    }

    root->page_number = totalPages;
    return totalPages;
}
int main() {
    // Tạo cây mục lục
    Node* root = create_node("Chapter 1", 10);
    root->firstChild = create_node("Section 1.1", 5);
    root->firstChild->nextSibling = create_node("Section 1.2", 8);
    root->firstChild->firstChild = create_node("Subsection 1.1.1", 3);

    // 1. Đếm số chương
    cout << "Số chương: " << countChapters(root) << endl;

    // 2. Tìm chương dài nhất
    Node* longest = findLongestChapter(root);
    if (longest != NULL) {
        cout << "Chương dài nhất: " << longest->title << " (" << longest->page_number << " trang)" << endl;
    }

    // 3. Xóa một mục
    root = deleteNode(root, "Section 1.1");
    cout << "Sau khi xóa, số chương: " << countChapters(root) << endl;

    // 4. Cập nhật lại số trang
    updatePageNumbers(root);
    cout << "Tổng số trang: " << root->page_number << endl;

    return 0;
}
