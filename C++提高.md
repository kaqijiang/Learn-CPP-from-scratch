### 内存分区模型

> **计算机内存**
>
> - 栈 <u>系统管理</u>内存
>
> - 堆  程序员通过new malloc分配 delete释放内存
>
> - 全局区/静态区，<u>编译及分配内存</u>（bss: 不占实际的磁盘空间，运行时分配内存）。
>
>   - bss: 存放==全局未初始化变量==，静态变量。
>
>   - 初始值为零和没有赋初始值的变量在BSS段，因为都是零，所以不需要占空间，程序加载后再赋值。
>   - data:存放==已初始化的全局变量==，已初始化的静态变量，"hello wrold"，10，数组名称等。程序在运行的期间不能够被改变
>
> - 代码区-静态区，<u>编译及分配内存</u>。存放系统代码，只读区域，共享。
>
> ![image-20200612113648066](https://tva1.sinaimg.cn/large/007S8ZIlly1gfpcpwfxecj314e0fk49i.jpg)
>
> `C++`中在程序运行前分为
>
> - 全局区`（bss+data）`常量区和代码区`（text）`
>
> - 运行后
>
>   - **栈区：**
>
>     ​		由编译器自动分配释放, 存放函数的参数值,局部变量等
>
>     ​		注意事项：不要返回局部变量的地址，栈区开辟的数据由编译器自动释放
>
>   - 堆区：
>
>     ​		由程序员分配释放,若程序员不释放,程序结束时由操作系统回收
>
>     ​		在C++中主要利用new在堆区开辟内存
>
>   - **new** :利用new创建的数据，会返回该数据对应的类型的指针
>
>     ​		`int* arr = new int[10];`
>
>     ​		`int* a = new int(10);`
>
>   ![image-20200612073703283](https://tva1.sinaimg.cn/large/007S8ZIlly1gfp5shnji3j31li0j4agv.jpg)

### 引用

> `数据类型 &别名 = 原名   不加&是赋值`  //给变量起别名
>
> * 引用必须初始化，在初始化后，不可以改变
>
> * 引用参数传递就是地址传递，调用函数的时候不用&
>
> * 不能返回局部变量的引用，栈上地址会释放，造成野指针
>
> * 如果函数做左值，那么必须返回引用
>
> * 引用只能绑定在对象上，而不能与字面值或某个表达式的计算结果绑定在一起
>
> * 类型必须一致，==常量引用const例外==
>
>
> **引用的本质**
>
> 引用的本质在c++内部实现是一个指针常量
>
> ```c++
> //发现是引用，转换为 int* const ref = &a;
> void func(int& ref){
> 	ref = 100; // ref是引用，转换为*ref = 100 指针不可变，常量可变
> }
> int main(){
> 	int a = 10;
> 
>   //自动转换为 int* const ref = &a; 指针常量是指针指向不可改，也说明为什么引用不可更改
> 	int& ref = a; //a是栈上开辟的空间。
>   
> 	ref = 20; //内部发现ref是引用，自动帮我们转换为: *ref = 20;
> 	func(a);
> 	return 0;
> }
> ```
>
> **数组引用**
>
> ```c++
> int a[3] = {1,2,3};
>     int (&b)[3] = a;
>     
>     cout << b[0];
>     cout << b[1];
> ```
>
> **指针的引用**
>
> ```c++
> 	  int a = 10;
>     int *p = &a;    
>     int *& ref = p;
>     
>     cout << a << &a <<endl;
>     cout << *p << p <<endl;
>     cout << *ref << ref <<endl;
> ```
>
> **常量引用** ==const==
>
> `因为引用相当于一个指针常量，指针不可变，但是常量可以发生改变，所以为了防止常量改变const来修饰`
>
> 初始化常量引用时允许用任意表达式作为初始值
>
> ```c++
> //引用使用的场景，通常用来修饰形参
> void showValue(const int& v) {
> 	//v += 10;
> }
> 
> //int& ref = 10;  引用本身需要一个合法的内存空间，因此这行错误/栈区或者堆区
> //加入const就可以了，编译器优化代码，int temp = 10; const int& ref = temp;
> const int& ref = 10;
> ```
>
> **类型相同**
>
> ```c++
> int i = 42;  
> const int &r1 = i;       //正确：允许将const int & 绑定到一个普通int对象上  
> const int &r2 = 42;      //正确  
> const int &r3 = r1 * 2;  //正确  
> int &r4 = r1 * 2;        //错误   引用本身需要一个合法的内存空间，因此这行错误/这个是在常量区
> ```
>
> **类型不同的引用**
>
> ```c++
> double dval = 3.14;  
> const int &ri = dval;    //正确   
> //类型不对应，编译器自动生成一个int临时对象
> //等价于  
> const int temp = dval;  
> const int &ri = temp;  //ri跟dval不是同一个地址了。
>   
> int i = 42;  
> int &r1 = i;  
> const int &r2 = i;  
> r1 = 0;                  //正确  
> r2 = 0;                  //错误  
> ```
>
> **作为函数的返回值**
>
> ```c++
> 语法：类型 &函数名（形参列表）{ 函数体 }
> int &func7(int a) {
>     int b = a+1;
>     return b;
> }
> //引用作为函数的返回值
>     int c = func7(8);
>     int &d = func7(9);// c d = 9 重新引用
> ```
>
> 1.在引用的使用中，单纯给某个变量去别名是毫无意义的，**引用的目的主要用于在函数参数的传递中，解决大块数据或对象的传递效率和空间不如意的问题**
>
> 2.用引用传递函数的参数，能**保证参数在传递的过程中不产生副本**，从而提高传递效率，同时**通过const的使用，还可以保证参数在传递过程中的安全性**
>
> 3.引用本身是目标变量或对象的别名，对引用的操作本质上就是对目标变量或对象的操作。因此**能使用引用时尽量使用引用而非指针**

### 函数提高

> **默认参数**
>
> 语法：` 返回值类型  函数名 （参数= 默认值）{}`
>
> ```c++
> //1. 如果某个位置参数有默认值，那么从这个位置往后，都要有默认值
> //2. 如果函数声明有默认值，实现不能有默认参数
> int func2(int a = 10, int b = 10);
> int func2(int a, int b) {
> 	return a + b;
> }
> ```
>
> **函数占位参数**
>
> **语法：** `返回值类型 函数名 (数据类型){}`
>
> ```c++
> //函数占位参数 ，占位参数也可以有默认参数
> void func(int a, int) {
> 	cout << "this is func" << endl;
> }
> ```
>
> **函数重载**
>
> **条件：**
>
> * 同一个作用域下
> * 函数名称相同
> * 函数参数**类型不同**  或者 **个数不同** 或者 **顺序不同**
> * **注意:**  函数的返回值不可以作为函数重载的条件
>
> ```c++
> void func(int a)
> void func(double a)
> ```
>
> **注意事项**
>
> - 引用作为重载条件
>
>   ```c++
>   void func(int &a)
>   void func(const int &a)
>   int a = 10;
>   func(a);
>   func(10);//有const
>   ```
>
> - 碰到默认参数产生歧义，需要避免