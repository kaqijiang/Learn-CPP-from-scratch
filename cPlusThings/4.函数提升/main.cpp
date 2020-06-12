//
//  main.cpp
//  4.函数提升
//
//  Created by 侯伟杰 on 2020/6/12.
//  Copyright © 2020 kaqijiang. All rights reserved.
//

#include <iostream>

using namespace std;

void func(string name, int age = 10) {
    cout << name << age << endl;
}
void func1(string name) {
    cout << "重载，方法名相同，参数不同" << endl;
}
void func1(string name, int age) {
    cout << "重载，方法名相同，参数不同" << endl;
}
int main(int argc, const char * argv[]) {
    
    func("kaqi");//默认参数
    
    //重载 oc没有重载，swift有
    func1("kaqi");
    func1("kaqi",19);
    
    return 0;
}
