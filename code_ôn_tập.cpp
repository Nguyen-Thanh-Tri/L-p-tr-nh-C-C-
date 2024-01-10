// #include<iostream>
// #include<string>
// using namespace std;
// int main(){
//         try
//         {
//                 char* ptr;
//                 strcpy(ptr, "ITP");
//         }
//         catch(const exception & e)
//         {

//         }
//         return 0;
// }
//          RUNTIME ERROR

////////////////////////////////////////////////////////////////////////////

// #include<iostream>
// using namespace std;
// class Base
// {

// };
// class Derived: public Base
// {

// };
// void Func(){
//     throw Derived();
// }
// int main(){
//         try
//         {
//             Func();
//         }
//         catch (const Base&)
//         {
//             cerr << "Caught a exception";
//         }
//         return 0;
// }
//          Caught a exception

///////////////////////////////////////////////////////////////////////////

// #include<iostream>
// using namespace std;
// template<class T>
// class Exam
// {
//     public:
//         Exam();
//         ~Exam();
// };
// template<class T>
// Exam<T>::Exam() {
//     cout << "C";
// }
// template<class T>
// Exam<T>::~Exam() {
//     cout << "D";
// }
// int main(){
//     Exam<int> obj_i;
//     Exam<char> obj_c;
//     Exam<double> obj_d;
//     return 0;
// }
//          CCCDDD

///////////////////////////////////////////////////////////////////////////

// #include<iostream>
// using namespace std;
// template<class T>
// class Exam
// {   
//     T prop;
//     public:
//         static int count;
//         Exam();
//         ~Exam();
// };
// template<class T>
// int Exam<T>::count = 0;
// template<class T>
// Exam<T>::Exam() {
//     Exam<T>::count++;
// }
// template<class T>
// Exam<T>::~Exam() {
// }
// int main(){
//     Exam<int> obj_x;
//     Exam<int> obj_y;
//     Exam<double> obj_z;
//     cout << Exam<int>::count << Exam<double>::count;
//     return 0;
// }
//          21

///////////////////////////////////////////////////////////////////////////

// #include<iostream>
// #include<vector>
// using namespace std;
// int main(){
//     vector<int> a(3,0);
//     vector<int> b(5,0);
//     b = a;
//     a = vector<int>();
//     cout << int(a.size()) << int(b.size());
//     return 0;
// }
//          03

///////////////////////////////////////////////////////////////////////////

// #include<iostream>
// #include<string>
// using namespace std;
// class Base
// {
//     public:
//         virtual Base();
// };
// Base::Base()
// {
//     cout << "Base";
// }
// class Derived: public Base
// {
//     public:
//         Base();
// };
// Derived::Base()
// {
//     cout << "Derived";
// }
// int main(){
//         Base obj;
//         return 0;
// }
//          COMPILE ERROR

///////////////////////////////////////////////////////////////////////////

// #include<iostream>
// using namespace std;
// class One
// {
//     public:
//         double add(double x)
//         {
//             return x + 0.1;
//         }
// };
// class Two : public One
// {
//     public:
//         using One::add;
//         int add(int x)
//         {
//             return x + 1;
//         }
// };
// int main(){
//     Two obj;
//     cout << obj.add(10) << obj.add(10.5);
//     system("pause");
//     return 0;
// }
//          1110.6

///////////////////////////////////////////////////////////////////////////

// #include<iostream>
// using namespace std;
// class Base
// {
//     int prop;
//     public:
//         void setProp(int);
//         int getProp();
// };
// void Base::setProp(int prop)
// {
//     this->prop = prop;
// }
// int Base::getProp()
// {
//     return this->prop;
// }
// class Derived : public Base
// {
//     int prop;
//     public:
//         void SetProp(int);
//         int Func();
// };
// void Derived::SetProp(int prop)
// {
//     this->prop = prop;
// }
// int Derived::Func()
// {
//     return this->prop * getProp();
// }
// int main(){
//     Derived obj;
//     obj.setProp(10);
//     obj.SetProp(4);
//     cout << obj.Func();
//     return 0;
// }
//      40

///////////////////////////////////////////////////////////////////////////

// #include<iostream>
// using namespace std;
// class ClassA
// {
//     protected:
//         int x;
//     public:
//         ClassA();
//         friend void Show();
// };
// ClassA::ClassA()
// {
//     this->x = 0;
// }
// class ClassB : public ClassA
// {
//     public:
//         ClassB();
//     private:
//         int y;
// };
// ClassB::ClassB() : y(0)
// {}
// void Show()
// {
//     ClassA obj1;
//     ClassB obj2;
//     cout << obj1.x << obj2.y;
// }
// int main(){
//     Show();
//     system("pause");
//     return 0;
// }
//          COMPILE ERROR

///////////////////////////////////////////////////////////////////////////

// #include<iostream>
// using namespace std;
// class A
// {
//     public:
//         virtual void fun();
// };
// class B
// {
//     public:
//         void fun();
// };
// int main(){
//     int a = sizeof(A), b = sizeof(B);
//     if (a == b) cout << "a == b";
//     else if (a > b) cout << "a > b";
//     else cout << "a < b";
//     system("pause");
//     return 0;

// }
//      a > b

///////////////////////////////////////////////////////////////////////////

// #include<iostream>
// #include<string>
// using namespace std;
// template<class T>
// class Exam
// {
//     public:
//         void operator()(T);
// };
// template<class T>
// void Exam<T>::operator()(T obj)
// {
//     cout << obj;
// }
// int main(){
//     Exam<string> obj_s;
//     Exam<int> obj_i;
//     int var_i = 2019;
//     string str = "ITF";
//     obj_i(var_i);
//     obj_s(str);
//     return 0;

// }
//          2019ITF

///////////////////////////////////////////////////////////////////////////

// #include<iostream>
// using namespace std;
// class Base1
// {
//     public: 
//         Base1();
// };
// Base1::Base1()
// {
//     cout << "1";
// }
// class Base2
// {
//     public:
//         Base2();
// };
// Base2::Base2()
// {
//     cout << "2";
// }
// class Derived : public Base1, public Base2
// {
//     public:
//         Derived();
// };
// Derived::Derived()
// {
//     cout << "3";
// }
// int main(){
//     Derived d;
//     system("pause");
//     return 0;
// }
//          123

///////////////////////////////////////////////////////////////////////////

// #include<iostream>
// using namespace std;
// void Func_Empty() throw()
// {
//     cout << "1";
// }
// void Func_Type() throw(int)
// {
//     cout << "2";
//     throw(1);
// }
// int main(){
//     try
//     {
//         Func_Empty();
//         Func_Type();
//     }
//     catch(int)
//     {
//         cout << "3";
//     }
//     return 0;
// }
//          123

///////////////////////////////////////////////////////////////////////////

// #include<iostream>
// using namespace std;
// template <class T, int max>
// int Func(T arr[], int var_x)
// {
//     int var_y = max;
//     for(int i = 0; i < var_x; i++)
//         if(arr[i] < var_y)
//             var_y = arr[i];
//     return var_y;
// }
// int main(){
//     int arr_x[] = {10, 20, 15, 12};
//     int var_x = sizeof(arr_x) / sizeof(arr_x[0]);
//     char arr_y[] = {1, 2, 3};
//     int var_y = sizeof(arr_y) / sizeof(arr_y[0]);
//     cout << Func<int, 10000>(arr_x, var_x) << Func<char, 256>(arr_y, var_y);
//     return 0;
// }
//          101

///////////////////////////////////////////////////////////////////////////

// #include<iostream>
// using namespace std;
// template <class T>
// class Exam
// {
//     public:
//         Exam();
//         ~Exam();
// };
// template<class T>
// Exam<T>::Exam() 
// {
//     cout << "C";
// }
// template<class T>
// Exam<T>::~Exam()
// {
//     cout << "D";
// }
// int main(){
//     Exam obj;
//     return 0;
// }
//          COOMPILE ERROR

///////////////////////////////////////////////////////////////////////////

// #include<iostream>
// using namespace std;
// const int bsize = 512;
// int *pa;
// bool allocate = true;
// void get_memory()
// {
//     cerr << " free store exhausted"<< endl;
//     delete[] pa;
//     allocate = false;
// }
// void eat_memory(int size)
// {
//     int *p = new int[size];
//     if ( allocate)
//         eat_memory(size);
//     else    
//         cerr << "free store addr = " << p << endl;
// }
// int main(){
//     set_new_handler(get_memory);
//     pa = new int[bsize];
//     cerr << "free store addr = "<< pa <<endl;
//     eat_memory(bsize);
//     return 0;
// }
/// có in kết quả nhưng SEGMENTATION FAULT

///////////////////////////////////////////////////////////////////////////

// #include<iostream>
// using namespace std;
// class ExamA
// {
//     mutable int prop;
//     public:
//         ExamA();
//         ~ExamA();
// };
// ExamA::ExamA()
// {
//     cout << "IT";
// }
// ExamA::~ExamA()
// {
//     cout << "ITF";
// }
// class ExamB : public ExamA
// {
//     public:
//         ExamB();
//         ~ExamB();
// };
// ExamB::ExamB()
// {
//     cout << "DUT";
// }
// ExamB::~ExamB()
// {
//     cout<< "DHBK";
// }
// int main(){
//     ExamB obj;
//     return 0;
// }
//          ITDUTDHBKITF

///////////////////////////////////////////////////////////////////////////

// #include<iostream>
// using namespace std;
// class Base
// {
//     int prop;
//     public:
//         Base();
//         void Func();
// };
// Base::Base()
//         :prop(0)
// {
// }
// void Base::Func()
// {
//     this->prop++;
//     cout << this ->prop;
// }
// class Derived : public Base
// {

// };
// int main(){
//     Derived obj;
//     obj.Func();
//     return 0;
// }
//          1

///////////////////////////////////////////////////////////////////////////

// #include<iostream>
// using namespace std;
// template <typename T = double, int count = 3>
// T Func(T var_x)
// {
//     for(int i = 0; i < count; ++i)
//     {
//         var_x = var_x * var_x;  
//     }
//     return var_x;
// };
// int main(){
//     double var_x = 2.1;
//     cout << var_x << Func<>(var_x);
//     return 0;
// }
//          2.1378.229

///////////////////////////////////////////////////////////////////////////

// #include<iostream>
// using namespace std;
// class Base
// {
//     public:
//         Base(); 
//         ~Base();
// };
// Base::Base()
// {
//     cout << "CB_";
// }
// Base::~Base()
// {
//     cout << "DB_";
// }
// class Derived : public Base
// {
//     public:
//         Derived();
//         ~Derived();
// };
// Derived::Derived()
// {
//     cout << "CD_";
// }
// Derived::~Derived()
// {
//     cout << "DD_";
// }
// int main(){
//     Base *Var = new Derived;
//     delete Var;
//     system("pause");
//     return 0;
// }
//              CB_CD_DB_

///////////////////////////////////////////////////////////////////////////

// #include<iostream>
// using namespace std;
// class Base
// {
//     int x,y,z;
//     public:
//         Base()
//         {
//             x = y = z = 0;
//         }
//         Base(int xx, int yy ='A', int zz = 'B')
//         {
//             x = xx; y = yy; z = x + y;
//         }
//         void Display()
//         {
//             cout << x << y << z;
//         }
// };
// class Derived : public Base
// {
//     int x, y;
//     public:
//         Derived(int xx = 65, int yy =66) : Base (xx,yy)
//         {
//             y =xx; x =yy;
//         }
//         void Display()
//         {
//             cout << x << y;
//         }
// };
// int main(){
//     Derived objD;
//     objD.Display();
//     system("pause");
//     return 0;
// }
//      6665

///////////////////////////////////////////////////////////////////////////

// #include<iostream>
// using namespace std;
// class Base
// {
//     double prop_b;
//     public:
//         virtual void Func();
// };
// void Base::Func()
// {
//     cout << "1";
// }
// class Derived : public Base
// {
//     int prop_d = 15;
//     public:
//         void Func();
// };
// void Derived::Func()
// {
//     cout << "2";
// }
// int main(){
//     Base * ptr = new Base();
//     Derived obj;
//     ptr = &obj;
//     ptr->Func();
//     return 0;
// } 
//          2

///////////////////////////////////////////////////////////////////////////

// #include<iostream>
// using namespace std;
// class Base
// {
//     public:
//         virtual void Func() = 0;
// };
// class DerivedA : public Base{
//     public:
//         void Func();
// };
// void DerivedA::Func()
// {
//     cout << "ITF";
// }
// class DerivedB : public Base
// {
//     public:
//         void Func();
// };
// void DerivedB::Func()
// {
//     cout << "DUT";
// }
// int main(){
//     Base * arr[2];
//     DerivedA obj_a;
//     DerivedB obj_b;
//     arr[0] = &obj_a;
//     arr[1] = &obj_b;
//     arr[0]->Func();
//     arr[1]->Func();
//     return 0;
// }
//          ITFDUT
