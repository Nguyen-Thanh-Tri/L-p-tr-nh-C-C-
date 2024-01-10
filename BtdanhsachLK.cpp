//  Cài đặt lại struct tập hợp SET sử dụng danh sách liên kết và định nghĩa
//  lại tất cả các hàm, phép toán trên tập hợp. (+, -, * tìm hợp, hiệu, giao của
//   02 tập hợp; +, - để thêm, xóa 01 phần tử trong tập hợp; () để kiểm tra 01 phần
//    tử có thuộc tập hợp; [ ] để truy cập 01 phần tử thứ i trong tập hợp; phép
//     toán gán =; phép toán << để in nội dung tập hợp)
#include <iostream>
using namespace std;
struct Node{
	int data;
	Node* next;
};
typedef struct Node* node;
struct SET{
        Node* head;
    node addNode(int value){
        node temp;
        node* temp = new node;
        temp ->data = value;
        temp ->next = NULL;
    }
    node delhead(node head){
        if(head == NULL){
            cout <<" k có để xoá"<<endl;
        }else{
            node p = head;
            head = head ->next;
            delete p;
        }
        return head;}
    node deltail(node head){
        if(head == NULL || head ->next == NULL){
            return delhead(head);
        }
        node p = head;
        while(p ->next ->next !=NULL){
            p = p ->next;
        }
        node q = p ->next;
        p ->next = p ->next ->next;
        delete q;
        return head;
    }
    node del(node head, int position){
        if(position == 0 || head == NULL || head ->next == NULL){
            head = delhead(head);
        }else{
            int k = 1;
            node p = head;
            while(p ->next ->next != NULL && k != position){
                p = p ->next;
                ++k;
            }
            if(k != position){
                head = deltail(head);
            }else{
                p ->next = p ->next ->next;
            }
    }
    return head;}
    //kiểm tra có phải thuộc tập hợp 
    bool contains(int value) {
        Node* current = head;
        while (current != NULL) {
            if (current->data == value) {
                return true;
            }
            current = current->next;
        }
        return false;
    }
    bool operator()(int element) {  
        return contains(element);
    }
    // Phép toán truy cập một phần tử thứ i trong tập hợp
    int operator[](int index) {
        Node* current = head;
        int count = 0;
        while (current != nullptr) {
            if (count == index) {
                return current->data;
            }
            count++;
            current = current->next;
        }
        // Nếu không tìm thấy, trả về -1     
    return -1;
    }
    // Phép toán gán =
    SET operator=(const SET& v) {
        if (this == &v) {
            return *this;
        }}
};
