## [通讯录系统代码](./cPlusThings/通讯录管理系统)		 [知识详情](./基础)

### 数据类型

> - `整型 浮点型 sizeof关键字 转义字符 字符串型 字符型 布尔型 输入/输出 cin cout`

### 运算符

> - `算术 赋值 比较 逻辑`

### 程序流程结构

> - `if 三目 switch while  do...while for break continue`

### 数组

> - 一维数组，二维数组。冒泡排序
> - `二维数组行数：sizeof(arr) / sizeof(arr[0])`
> - `二维数组列数：sizeof(arr[0]) /sizeof(arr[0][0])`

### 函数

> ```c++
> 返回值类型 函数名 （参数列表）
> {
>  函数体语句
>  return表达式
> }
> ```
>
> - 值传递 地址传递

### 指针

> 作用:直接访问内存。
>
> ```c++
> //指针定义语法： 数据类型 * 变量名 ;
> int * p;
> int a = 10; //定义整型变量a
> //指针变量赋值
> p = &a; //指针指向变量a的地址
> *p //解引用
> ```
>
> 指针变量和普通变量的区别
>
> * 普通变量存放的是数据,指针变量存放的是地址
> * 指针变量可以通过" * "操作符，操作指针变量指向的内存空间，这个过程称为解引用
>
> > -  & 符号 获取变量的地址
> > -  指针可以记录地址
> > -  对指针变量解引用，可以操作指针指向的内存
>
> **空指针**：
>
> > 指针变量指向内存中编号为0的空间 NULL 指向的内存是不可以访问的
> >
> > 初始化指针变量，但是0-255是系统的，我们不可以访问。
>
> 
>
> **野指针**：指针变量指向非法的内存空间
>
> **const修饰**：const右侧紧跟着的是指针就是常量指针，是常量就是指针常量
>
> > - 修饰指针   --- 常量指针 常量不能改，地址可以改。
> > - 修饰常量   --- 指针常量 指针不能改，常量可以改。
> > - 既修饰指针，又修饰常量 都不能改
> >
> > ```c++
> > //const修饰的是指针，指针指向可以改，指针指向的值不可以更改
> > 	const int * p1 = &a; 
> > 	p1 = &b; //正确
> > 	//*p1 = 100;  报错
> > 	
> > 	//const修饰的是常量，指针指向不可以改，指针指向的值可以更改
> > 	int * const p2 = &a;
> > 	//p2 = &b; //错误
> > 	*p2 = 100; //正确
> > 
> >     //const既修饰指针又修饰常量
> > 	const int * const p3 = &a;
> > 	//p3 = &b; //错误
> > 	//*p3 = 100; //错误
> > ```
>
> **指针和数组**: 
>
> ```c++
> int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
> int * p = arr;  //指向数组的指针
> // p 指针即地址
> //*p 是首地址，也是第一个元素。 p++可以遍历
> 	for (int i = 0; i < 10; i++)
> 	{
> 		cout << *p << endl;
> 		p++;
> 	}
> ```
>
> **指针和函数**：利用指针作函数参数，可以修改实参的值 ==参数为指针，传参增加&.==

### 结构体

> 定义：`struct 结构体名 { 结构体成员列表 }；`
>
> 结构体创建变量三种方式：
>
> * struct 结构体名 变量名
> * struct 结构体名 变量名 = { 成员1值 ， 成员2值...}
> * 定义结构体时顺便创建变量
>
> **结构体数组**
>
> ` struct  结构体名 数组名[元素个数] = {  {} , {} , ... {} }`
>
>  **结构体指针**
>
> ```c++
> struct student stu = { "张三",18,100, };
> 	
> struct student * p = &stu;//取地址符
> 
> p->score = 80; //指针通过 -> 操作符可以访问成员
> ```
>
> **结构体嵌套结构体**
>
> ```c++
> //教师结构体定义 包含学生的 结构体变量
> struct teacher
> {
> 	int id; //编号
> 	string name;  //姓名
> 	int age;   //年龄
> 	struct student stu; //子结构体 学生
> };
> ```
>
> **结构体做函数参数** `值传递student stu，地址传递student *stu`
>
> **const修饰结构体参数** 修饰指针，常量指针，地址可以改，值不可以修改。	
>
> - `void printStudent(const student *stu) //加const防止函数体中的误操作`

