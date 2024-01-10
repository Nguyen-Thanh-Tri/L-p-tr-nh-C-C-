#include <iostream>
using namespace std;
void NhapXuat(int x[],int n);
void Kichthuoc(int x[],int n);
int Layphantu(int x[], int n, int vt);
void Sapxepchont(int x[], int n);
int Timpt(int x[], int n, int k);
void Sapxepchong(int x[], int n);
int main(){
    int n;
    cout <<"Nhap n:";
    cin >> n;
    int x[n];
    NhapXuat(x,n);
    int choice;
        cout << "Chọn tùy chọn:" << endl;
        cout << "1. Xắp xếp tăng dần" << endl;
        cout << "2. Sắp xếp giảm dần" << endl;
        cout << "0. Thoát" << endl;
        cout << "Nhập lựa chọn: ";
        cin >> choice;
        if(choice == 0) exit(0);
    switch (choice){
        case 1:
            Sapxepchont(x,n);
            for(int j=0;j<n;j++){
                cout <<x[j]<<" ";}
            cout << endl;
            int choice1;
            do {
                cout << "Chọn tùy chọn:" << endl;
                cout << "1. Lấy kích thước mảng:" << endl;
                cout << "2. Lấy phần tử tại vị trí:" << endl;
                cout << "3. Tìm phần tử trong mảng:" << endl;
                cout << "0. Thoát" << endl;
                cout << "Nhập lựa chọn: ";
                cin >> choice1;
                switch(choice1){
                    case 1:{
                        Kichthuoc(x,n);}
                        break;
                    case 2:{
                        int vt;
                        cout<<"Nhap vt:";cin >>vt;
                        int tk = Layphantu(x,n,vt);
                        if (tk == -1) cout <<"Vi tri khong hop le"<<endl;
                            else cout <<"Phan tu tai vi tri "<< vt <<" trong mang la "<< tk <<endl;}
                        break;
                    case 3:{
                        int pt;
                        cout <<"Nhập phần tử cần tìm :";
                        cin >> pt;
                        int vitri = Timpt(x,n,pt);
                        if (vitri == -1) 
                                cout << "không có phần tử " <<pt<<" trong mảng."<<endl;
                            else
                                cout << " phần tử được tìm thấy tại vị trí " << vitri << " trong mảng."<<endl;}
                        break;
                    case 0:
                        break;
                    }
                } while (choice1 != 0);   
        case 2:
            Sapxepchong(x,n);
            for(int j=0;j<n;j++){
                cout <<x[j]<<" ";}
            cout << endl;
            int choice2;
            do {
                cout << "Chọn tùy chọn:" << endl;
                cout << "1. Lấy kích thước mảng:" << endl;
                cout << "2. Lấy phần tử tại vị trí:" << endl;
                cout << "3. Tìm phần tử trong mảng:" << endl;
                cout << "0. Thoát" << endl;
                cout << "Nhập lựa chọn: ";
                cin >> choice2;
                switch(choice2){
                    case 1:{
                        Kichthuoc(x,n);}
                        break;
                    case 2:{
                        int vt1;
                        cout<<"Nhập vị trí:";cin >>vt1;
                        int tk1 = Layphantu(x,n,vt1);
                        if (tk1 == -1) cout <<"Vi tri khong hop le"<<endl;
                            else cout <<"Phan tu tai vi tri "<< vt1 <<" trong mang la "<< tk1 <<endl;}
                        break;
                    case 3:{
                        int pt1;
                        cout <<"Nhập phần tử cần tìm :";
                        cin >> pt1;
                        int vitri1 = Timpt(x,n,pt1);
                        if (vitri1 == -1) 
                                cout << "không có phần tử " <<pt1<<" trong mảng."<<endl;
                            else
                                cout << " phần tử được tìm thấy tại vị trí " << vitri1 << " trong mảng."<<endl;}
                        break;
                    case 0:
                        break;
                    }
                }while (choice2 != 0);   

                }

    }
    
// Hàm Nhập Xuất
void NhapXuat(int x[],int n){
    for(int i=0;i<n;i++){
        cout <<"Nhap phan tu thu a["<<i<<"]:";
        cin >>x[i];
    }
    for(int j=0;j<n;j++){
        cout <<x[j]<<" "<<endl;
    }
}
//Hàm lấy kích thước
void Kichthuoc(int x[], int n){
    int size = n*sizeof(x[0]);
    cout<<"kich thuoc mang la :" << size<<endl;
}
//Hàm lấy phần tử
int Layphantu(int x[], int n, int vt){
    if(vt >= 0 && vt<n)
        return x[vt];
    return -1;
}
//Hàm sắp xếp chon tăng dần
void Sapxepchont(int x[], int n){
    for(int i=0;i<n-1;i++)
        for(int j = i+1; j<n; j++)
            if (x[i] > x[j]) {
                swap(x[i],x[j]);
            }}
//Hàm sắp xếp chon giảm dần
void Sapxepchong(int x[], int n){
    for(int i=0;i<n-1;i++)
        for(int j = i+1; j<n; j++)
            if (x[i] < x[j]) {
                swap(x[i],x[j]);
            }}
//tìm kiếm
int Timpt(int x[], int n, int k){
    int l = 0;
    int r = n -1;
    do{
        int mid = (l + r)/2;
        if(k == x[mid]) return mid;
        else 
            if(k <x[mid]) r = mid -1;
            else l =mid +1;
    } while(l<=r);
    return -1;
}