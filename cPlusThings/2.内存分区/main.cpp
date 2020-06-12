//
//  main.cpp
//  2.内存分区
//
//  Created by 侯伟杰 on 2020/6/12.
//  Copyright © 2020 kaqijiang. All rights reserved.
//

#include <iostream>
using namespace std;
int a = 0;//全局变量 已初始化
string b; //全局变量 未初始化

static int static_a;// 全局静态变量
const int const_a = 0;// 全局变量被const修饰->全局常量

int* test() {
    int a = 1;
    cout << a;
    return &a;//函数过后a就释放 栈上
}

int *test1(){
    static int a = 10; //static 修饰后变成静态变量，存在全局区->data数据段中
    return &a;
}
const int * test2(){
    const int a = 20;
    return &a;
}
int* test3() {
    
    int *p = new int(10);
    delete p;
    return p;
}

int *test4(){
    int *arr = new int[10];
    
    for (int i = 0; i < 10; i++) {
        arr[i]=i;
    }
    delete [] arr;
    return arr;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    
    //栈数据
    int *p = test(); //返回局部变量地址，野指针，编译器会保留一次，第二次输出就野指针了。
    cout << *p << endl;
    cout << *p << endl;
    
    //data区地址
    int *p1 = test1(); //还保留在内存中
    cout << *p1 << endl;
    cout << *p1 << endl;
    
    const int *p2 = test2();//const 修饰的局部变量在，作用域后释放。
    cout <<*p2 << endl;
    cout <<*p2 << endl;
    
    //堆数据
    int *p3 = test3();
    
    delete p3;//再去释放报错。函数中已经释放了。
    
    
    delete p3;

    //堆数据
    int *p4 = test4();

    delete[] p4; //再去释放报错。函数中已经释放了。
        
    return 0;

}
