## 通讯录管理

### main

> `int main(int argc, const char * argv[]) `
>
> `main`函数是入口，程序冲`main`函数开始执行

### 头文件引入

> 引入头文件`#include <string>`
>
> 程序中有使用到字符串string的地方，所以需要引入一个头文件，才能使用，不然报错。xcode不用引入。

### 宏定义

> 定义了一个宏，用来做常量，来设置通讯录的容量
>
> `#define MAX 3`

### 结构体

> 结构体声明，及定义的基本语法。
>
> ```c++
> struct person {
> 	string name;
>   int age;
> };
> //结构体创建变量
> person per1;//方式一，只创建。
> per1.name = "xxx";
> per1.age = 19;
> 
> person per2 {"xxx",19};//方式二，创建后赋值。
> 
> struct person {//方式三，声明的时候创建。
> 	string name;
>   int age;
> }per3;
> per3.name = "xxx";
> per3.age = 19;
> ```
>
> 定一个一个`person`结构体和一个`addressBooks`的结构体，其中`addressBooks`中还使用了结构体嵌套，嵌套了一个`person`类型的数组。

### 结构体数组

> c++结构体数组在定义的时候需要在`[]`中设定一个初始的值，否则报错，然而c不需要。

### 函数调用

> - 无参无返回值 `showMenu()`
>
> - 有参无返回值 `showPerson(&addBooks);`等
>
> - 有参有返回值`int isHave(string name,addressBooks *addBooks)`
>
>   传入姓名和通讯录的地址，然后返回一个`int`类型数据
>
>   需要声明一个`int`类型变量来接收它。

### 地址传递

> `main`函数程序运行，在系统运行后，选择1-6的时候，都是进行了地址传递。
>
> 例如：`showPerson(&addBooks);`
>
> - 使用取地址符修饰结构体变量，就拿到了结构体变量的地址.
> - 因为我们要对通讯录操作，操作完后希望影响原始的通讯录，所以进行了地址传递.
> - 地址传递过去后，形参需要使用一个指针来接收。`addressBooks*`
>
> 例如：`void showPerson(addressBooks* addBooks) { xxxx }`
>
> 访问指针中的数据需要使用`->`来访问,成员属性直接用`.`即可。
>
> `addBooks->personList[i].name`

### 总结

> - 首先定义一个人的结构体。
> - 再定一个通讯录，里边包含许多人。
> - 使用程序运行，让程序进入一个循环中`  while (true)`
> - ` switch (select)`根据输入去判断要如何操作。
> - 显示人员就要遍历通讯录
> - 新增判断有没有超限制，没有就增加，增加完后，要**修改通讯录大小**。
> - 查询 先判断有没有，有就显示。
> - 删除 先判断有没有，有就删除。 同时要把通讯录中的`person`数组中数据剔除。要**修改通讯录大小**。
> - 修改 先判断有没有，有就拿到当前角标进行修改。
> - 清空 直接修改通讯录大小为0

