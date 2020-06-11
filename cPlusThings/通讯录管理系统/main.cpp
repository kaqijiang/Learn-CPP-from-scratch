//
//  main.cpp
//  通讯录管理系统
//
//  Created by 侯伟杰 on 2020/6/11.
//  Copyright © 2020 kaqijiang. All rights reserved.
//

#include <iostream>
//#include <string>

#define MAX 3
using namespace std;

struct person {
    string name;
    int age;
};
struct addressBooks {
    person personList[MAX];
    int m_size;
};

void showMenu(){
    //endl 会调用flush函数，刷新缓冲区，
    cout << "系统开始\n" << endl;
    cout << "1显示人员" << endl;
    cout << "2新增人员\n";
    cout << "3查询人员\n";
    cout << "4删除人员\n";
    cout << "5修改人员\n";
    cout << "6清空人员\n";
    cout << "0退出系统\n";
    cout << "\n请输入数字选择选择\n";
}


/// 是否存在人员
/// @param name 查询人员姓名
/// @param addBooks 地址簿
int isHave(string name,addressBooks *addBooks) {
    for (int i = 0; i < addBooks->m_size; i++) {
        
        if (addBooks->personList[i].name == name) {
            return i;
        }
    }
    return -1;
}

/// 显示所有人
/// @param addBooks 地址簿
void showPerson(addressBooks* addBooks) {
    if (addBooks->m_size == 0) {
        cout << "没有人";
        return;
    }
    for(int i = 0; i < addBooks->m_size; i++) {
        
        cout << "姓名：" << addBooks->personList[i].name << endl;
        cout << "年龄：" << addBooks->personList[i].age << endl;
        
    }
}
/// 新增人
/// @param addBooks 传入地址簿地址
void addPerson(addressBooks *addBooks) {
    if (addBooks->m_size >= MAX) {
        cout << "人数超限制\n";
        return;
    }
    
    cout << "请输入姓名\n";
    string name;
    cin >> name;
    addBooks->personList[addBooks->m_size].name = name;
    cout << "请输入年龄\n";
    int age;
    cin >> age;
    while (true) {
        if (age < 120 && age > 0) {
            addBooks->personList[addBooks->m_size].age = age;
            break;
        }
        else
        {
            cout << "非法数据，请重新输入\n";
        }
    }
    addBooks->m_size++;
    cout << "添加成功\n";
}

/// 查询人员
void searchPerson(addressBooks *addbooks) {
    cout << "请输入要查询的人员姓名\n";
    
    string name;
    cin >> name;
    
    if (name.length() > 0) {
        //查询
        int ishave = isHave(name, addbooks);
        if (ishave != -1) {
            cout << "name:" << addbooks->personList[ishave].name << "\n age:" << addbooks->personList[ishave].age << endl;
        }
        else{
            cout << "查无此人\n";
        }
    }else{
        cout << "非法输入\n";
    }
}

/// 删除人员
/// @param addBooks 地址簿
void delPerson(addressBooks* addBooks) {
    
    cout << "请输入要删除人姓名：\n" << endl;
    string name;
    cin >> name;
    if (name.length() > 0) {
        int ishave = isHave(name ,addBooks);
        if (ishave != -1) {
            for (int i = ishave; i<addBooks->m_size; i++) {//遍历挤出去
                addBooks->personList[i] = addBooks->personList[i + 1];
            }
            addBooks->m_size--;
            cout << "删除成功\n";
        }
        else{
            cout << "查无此人\n";
        }
    }
    else{
        cout << "非法输入\n";
    }
};

/// 修改人员
/// @param addBooks 地址簿
void changePerson(addressBooks* addBooks) {
    cout << "请输入要删除人姓名：\n" << endl;
    string name;
    cin >> name;
    if (name.length() > 0) {
        int ishave = isHave(name ,addBooks);
        if (ishave != -1) {
            cout << "\n请输入修改后的姓名\n";
            string newName;
            cin >> newName;
            cout << "\n请输入修改后的年龄\n";
            int newAge;
            cin >> newAge;
            addBooks->personList[ishave].name = newName;
            addBooks->personList[ishave].age = newAge;
            
            cout << "姓名：" << addBooks->personList[ishave].name << endl;
            cout << "年龄：" << addBooks->personList[ishave].age << endl;
        }else{
            cout << "查无此人\n";
        }
    }
    else
    {
        cout << "非法输入\n";
    }
}

int main(int argc, const char * argv[]) {
    
    int select = 0;
    addressBooks addBooks;
    
    while (true) {//系统运行
        showMenu();
        cin >> select;
        switch (select) {
            case 0:
                //退出
                return 0;
                break;
            case 1:
                //显示人员
                showPerson(&addBooks);
                break;
            case 2:
                //新增
                addPerson(&addBooks);
                break;
            case 3:
                //查询
                searchPerson(&addBooks);
                break;
            case 4:
                //删除
                delPerson(&addBooks);
                break;
            case 5:
                //修改
                changePerson(&addBooks);
                break;
            case 6:
                //清空
                addBooks.m_size = 0;
                cout << "清空成功\n";
                break;
            default:
                cout << "输入有误，程序结束\n";
                return 0;
                break;
        }
    }
    
    return 0;
}
