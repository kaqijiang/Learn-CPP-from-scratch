//
//  main.cpp
//  3.引用
//
//  Created by 侯伟杰 on 2020/6/12.
//  Copyright © 2020 kaqijiang. All rights reserved.
//

#include <iostream>
using namespace std;

void func(){
    
    int a = 10;
    int &b = a;//初始化，可以理解为 int* const ref = &a;  指针不能改，常量可以改
    cout << b;
    int c = 101;
    b = c; //这个是赋值 不可更改引用。
    cout << b;
    
    cout << &a << endl;//相当于其别名，地址一样，不会开辟新空间
    cout << &b << endl;
    
    
    // 引用本身需要一个合法的内存空间，因此这行错误/栈区或者堆区 int&b = 10;访问了非法空间，
}
void func1() {
    int a[3] = {1,2,3};
    int (&b)[3] = a;
    
    cout << b[0] << endl;
    cout << b[1] << endl;
}

void func2(){
    int a = 10;
    int *p = &a;
    
    int *& ref = p;
    
    cout << a << &a <<endl;
    cout << *p << p <<endl;
    cout << *ref << ref <<endl;
}
void func3(){
    int a = 2;
    
    const int &b = a;
//    b = 11;常引用后不可修改值。
    cout << b <<endl;
    cout << a <<endl;
}

void func4(){
    float a = 2.32;
    const int &b = a;//增加const后 类型不同不会报错，默认生成一个中间变量 const int temp = a; const int &b = temp;
}

void func5(int &a) {
    a = 10;
}

void func6(int (&a)[3]) {
    cout << a[2] <<endl;
}

int &func7(int a) {
    int b = a+1;
    return b;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    

    //引用初始，初始化后，不可以改变
    func();
    
    //数组引用
    func1();
    
    //对指针引用
    func2();
    
    //const 修饰 类型相同赋值  const修饰后叫做常引用,不可修改形参。
    func3();
    
    //类型不同
    func4();
    
    //引用做参数-地址传递
    //如果参数传递的数据较大时，建议使用引用作为函数的形参，这样会提高函数的时间效率，并节省内存空间。
    int a = 3;
    func5(a);
    cout << a <<endl;
    
    //引用参数数组
    int num[3] = {1,222,444};
    func6(num);
    
    
    //引用作为函数的返回值
    int c = func7(8);
    int &d = func7(9);// c d = 9 重新引用
    
    
    return 0;
}
//使用指针作为函数的形参虽然达到的效果和使用引用一样，但当调用函数时仍需要为形参指针变量在内存中分配空间，而引用则不需要这样，故在C++中推荐使用引用而非指针作为函数的参数
//如果在编程过程中既希望通过让引用作为函数的参数来提高函数的编程效率，又希望保护传递的参数使其在函数中不被改变，则此时应当使用对常量的引用作为函数的参数。
//数组的引用作为函数的参数：C++的数组类型是带有长度信息的，引用传递时如果指明的是数组则必须指定数组的长度
