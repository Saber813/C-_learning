# C++ notes

## 前言

* 互动练习: 提问 回答 改正
* 用C++ 的思考方式来思考
* **4**个项目: **书籍网站地址** **项目**
  http://cpphelp.com/exploring/
* 合作:
  * 独立完成练习
  * 一个人负责编码 / 另一个人负责检查 

### C++标准

#### C++ 探秘_ch: (2008)

ISO/IEC 14882:2003(E) 这是一个对1998版本的修订版 新增一份该标准的**附录**(Technical Report1)内含 **正则表达式,数学函数内容**. 

**非高级特性并不会影响到本书, 其他特性可能会影响到所有的C++程序员**

#### C++ 探秘_en: (2020)

ISO/IEC 14882:2020(E) **C++20** **2020年2月 final draft 2020年5月 ISO认证**

## C++基础

### 0. 通用

0. 目前vscode采用14版本C++

1. `assert(表达式)` 可以很快检验条件是否为真, 如果为假程序终止,并且给出一条消息指出该断言出的位置

   声明在<cassert>库中.

   c的意思是该C++库继承了C标准库的头文件

   不需要用std:: 开头

2. interator: 

   所有的特殊迭代器都声明在<interator>之中, 如果使用的是普通迭代器: 如data.begin()则不需要

### 2. 阅读C++代码

1. **注释**

   "**符号之内无空格**": 当C++编译器看到连续的字符的时候, 总会试图构建有可能最长的符号. 即使这样做明显会产生无意义的结果.

2. **头文件**

   头文件通常是包含一系列声明和定义的文件

3. 主程序

   * C++ 标准确**定int 为 main 函数的返回**

   * **一个完整的函数必须包含main函数的定义**

   > std::numeric_limits 可以查询内置算数类型的属性 
   >
   > 你可以确定一个类型需要多少位 十进制数字 它的最大值和最小值
   >
   > 使用方法: std::numeric_limits<bool>:: min()

4. 语句

   **C++会把任意非零值当作true**

5. 输出

   输出操作符 >> , 在<ostream> 头文件中 , 这个头文件声明了名字 std::out

6. 输入

   control + **z**

### 4. 字符串

* **\t 的作用是跳格**，即跳到下一个“制表位置”（也有说是TAB位置），在我们所用的系统中一个“制表区”占8列。“下一制表位置”从第9列开始。

  ```
  main()
  {
      printf("abc\tde");
      printf("\n");
      printf("123456789");
      getch();
  }
  运行结果：
  如果不加\t
  输出：
  abcde
  123456789  
  加了后\t，输出：
  abc     de
  123456789
  你会发现，d与数字9对齐，说明它已经移到了第9列了！
  ```

* **C++ 会把相邻的两个字符串 合成一个字符串**

* **初始化空字符串**

  ```c++
  std::string empty;//定义没有初值的变量必须删除括号
  std::cout << "|"<<empty<<'|';
  输出: || //删除括号
  输出: |1| //填上()
  ```

* **不要使用未初始化变量**

### 5. 简单输入

#### **输出读入** :  

* 标准输入是一串字符流, 字符来自缓冲区, **因此该程序始终保持在流的当前位置(无论你用了多少cin)**,下一个读操作始终从这个位置开始.
* 开始的空白字符会被跳过
* **读取字符,检查是否有效,无效则流不会移动**

### 8. 格式化输出

```CC
#include<iomanip> 

std::setw(N) // 设定输出字段的最小宽度
//使用时将其调用语句放在输出语句之中, 成为I/O manipulator
std::setfill('0')//填充元素
std::left / std::right //左右对齐
```

* **setw : 非粘滞 默认为零**
* **setfill: 粘滞 更改则输出字段一直使用该字符**

#### 成员函数控制输出

**输入流,输出流 成员函数分别在<istream><ostream>中声明**

```c++
#include<iostream>
#include<ostream>
using namespace std;
int main()
{
    cout.fill('*');
    cout.width(6);
    cout<<42<<"\n";
    cout<<"fill is "<<cout.fill()<<'\n'
    <<"width is " <<cout.width()<<"\n";

}
> 
****42
fill is *  //粘滞
width is 0 //width 非粘滞 所以输出零
```

**使用manipulator 简单且明晰**

**使用成员函数:** 设定填充字符或者对齐**等粘滞属性的时候**,除了设置可以查询 **如上**

### 9. 数组和向量

#### vector

```C++
#include <algorithm>
#include <iostream>
#include <istream>
#include <ostream>
#include <vector>

int main()
{
  std::vector<int> data;     // initialized to be empty
  int x(0);

  // Read integers one at a time.
  while (std::cin >> x)
    // Store each integer in the vector.
    data.push_back(x);

  // Sort the vector.
  std::sort(data.begin(), data.end());

  // Print the vector, one number per line.
  
  // 注意vector的迭代过程
  //可以用data.begin()==data.end() 来比较是否为空
  for (std::vector<int>::size_type i(0); i != data.size(); i = i + 1)
    std::cout << data.at(i) << '\n';
}
// data.push_back | data.begin() | data.end() | std::vector<int>::size_type i(0)
// data.size() | data.at() | data.back() | data.front() | data.empty()
```

* **vector 仅在末尾添加或者删除元素的时候才是性能最好的**
* **data[N] 与 data.at(N) 的区别在于 at提供了额外的安全控制**
* **同string一样 vector 是库类型,并且初值为空**
* `std::vector<int> full_of_zero(10)` 
* data.begin() | data.end()-> 超出末端的下一个位置 

####  泛型算法 | 迭代器 <iterator>

**泛型算法**: **函数实现了通用算法,并且其操作具有一般性**

​				 **几乎所有的泛型算法都使用迭代器 (std::max & std::min 除外 他们分别返回两个值中的最大最小值)**

**迭代器**: 读迭代器 & 写迭代器

* 读迭代器: 指向序列中的一个位置,必须制定一个位置 从该位置算法开始写输出 

  > 必须包含开始位置,**和超出末端的下一个位置**

* 写迭代器 

  **所有的写迭代器只允许递增**

**重写一下for循环体**

```c++
//迭代器方法重写
  for(std::vector<int>::iterator i(data.begin());i!=data.end();i++)
  {
      std::cout<<*i<<'\n';
  }
```

**重新使用迭代器进行读写操作**

```C++
#include <algorithm>
#include <iostream>
#include <istream>
#include <iterator>
#include <ostream>
#include <vector>

int main()
{
  std::vector<int> data;

  // Read integers one at a time.
  std::copy(std::istream_iterator<int>(std::cin),
            std::istream_iterator<int>(),
            std::back_inserter(data));

  // Sort the vector.
  std::sort(data.begin(), data.end());

  // Print the vector, one number per line.
  std::copy(data.begin(), data.end(),
            std::ostream_iterator<int>(std::cout, "\n"));
}
// 另一种输入流的写法
{
    data.insert(data.end(),
                std::istream_iterator<int>(std::cin),
                std::istream_iterator<int>())
}
```

**istream_iterator:** 

​	**istream_iterator<int> (std::cin)**

​	创建一个读迭代器以读取输入流, **每次从迭代器取值的时候, istream_iterator对象会使用>>操作符 从流中取值**,必须在尖括号中声明类型. 

​	**istream_iterator<int>( )**

​	返回超出末端的下一个迭代器, **当输入流迭代器等于这个特殊的超出末端的下一个位置的迭代器时候**,程序到达流的末端,没有可以再度取得输入了

**back_inserter:**

​	back_inserter以**vector为(或者任何包含push_back的对象)**参数,包装在一个写迭代器中. 只要给迭代器赋值,后插迭代器就会调用push_back函数将该值添加到对象中,

​	**使用back_inserter 可以保证程序不会溢出缓存**

**std::ostream_iterator**

​	std::ostream_iterator是前者对等物, 以一个输出流为参数, 并将其包装在写迭代器中,.只要给迭代器赋值,就会调用<<将值写入. 该函数可以传递一个可选的参数, 将该字符串添加到每个值后面

**insert**

​	**insert成员函数将迭代器制定范围的值复制到向量中,这些值被插入到第一个参数(data.end) 之前**

### 10. 自增和自减

```c++
/** @file list1004.cpp */
/** Listing 10-4. Rewriting the for Loop */
#include <algorithm>
#include <iostream>
#include <istream>
#include <iterator>
#include <ostream>
#include <vector>

int main()
{
  std::vector<int> data;
  int x;
  while (std::cin >> x)
    data.push_back(x);

  // start != end 表明vector 一开始不为空
  // start != --end 表明两个没有重叠
  for (std::vector<int>::iterator start(data.begin()), end(data.end());
       start != end and start != --end;
       ++start)
  {
    int tmp = *start;
    *start = *end;
    *end = tmp;
  }

  std::copy(data.begin(), data.end(), std::ostream_iterator<int>(std::cout, "\n"));
}

```

### 11. 条件和逻辑(比较)

* `std::boolalpha`操作子通知将bool值解析为单词(之前true 为1 false 为0)

  > **反向操作子为noboolalpha**

* **所有的字符串都是true 即使是空的字符串**

* **使用and or not 来避免失败**

* 比较字符串时很困难,**因为编译器使用字符串在内存中的位置,而不是字符串内容进行比较**, 字符串在内存中的位置是编译器内部工作细节,和实践无关.

  **要想比较字符串,首先把字符串(至少一个)变成string 类型的**

### 12. 复合语句

```C++
/** @file list1202.cpp */
/** Listing 12-2. Local Variable Definitions */
#include <algorithm>
#include <cassert>
#include <iostream>
#include <iterator>
#include <ostream>
#include <string>
#include <vector>

int main()
{
    //标准输入读入
    std::vector<int> data;
    data.insert(data.begin(), std::istream_iterator<int>(std::cin),
                std::istream_iterator<int>());
    //遍历整个data
    for (std::vector<int>::iterator iter(data.begin()); iter != data.end(); ++iter)
    {
        
        int value(*iter);

        //lower_bound 二分查找法, 找到begin()和iter 之间的value值 指向这个值第一次出现的位置
        std::vector<int>::iterator here(std::lower_bound(data.begin(), iter, value));
        
        //如果 这个值不是第一次出现, 将其插入第一次出现的位置(之前) 1 2 3 4 4 5 6
        if (iter != here)
        {
            //erase 删除向量中的一个元素, data大小减一 , 返回指向被删除元素后面的元素的迭代器
            data.erase(iter);
            //insert 在指定位置前 插入value
            iter = data.insert(here, value);
        }
    }

    //将向量中的每一个元素与前一个元素相比较,检查循环是否真的被排序
    for (std::vector<int>::iterator iter(data.begin()), prev(data.end());
         iter != data.end();
         ++iter)
    {
        if (prev != data.end())
            assert(not(*iter < *prev));
        prev = iter;
    }

    //将排序好的向量全部打印到一行
    std::cout << '{';
    std::string separator(" ");
    for (std::vector<int>::iterator iter(data.begin()); iter != data.end(); ++iter)
    {
        std::cout << separator << *iter;
        separator = ", ";
    }
    std::cout << " }\n";
}
```

### 13. 文件I/O简介

**<iostream>中规定了 cout **

**<cstdio>中声明了perror 函数**

**<istream> 与 <ostream> 分别规定了 >> 和 << 操作符**

#### 读文件

```c++
/** @file list1301.cpp */
/** Listing 13-1. Copying Integers from a File to Standard Output */
#include <cstdio>
#include <fstream>
#include <iostream>
#include <istream>
#include <ostream>

int main()
{
  std::ifstream in("list1301.txt");
  if (not in)
    std::perror("list1301.txt");
  else
  {
    int x(0);
    while (in >> x)
      std::cout << x << '\n'; 
    in.close();
  }
}

```

#### 写文件

对于读文件来说 main 结束 ,in 就会关闭

但是对于写文件来说,

​	 **一些输出错误会等到文件被关闭的时候才出现,---关闭一个文件时 操作系统清除所有内部缓存,并作所有其他所需的清理工作.**

所以, 不调用close 输出流对象可能收不到错误题式

```c++
** @file list1303.cpp */
/** Listing 13-3. Copying Integers, with Minimal Error-checking */
#include <cstdio>
#include <fstream>
#include <istream>
#include <ostream>

int main()
{
  std::ifstream in("list1302.in");
  if (not in)
    std::perror("list1302.in");
  else
  {
    std::ofstream out("list1302.out");
    if (not out)
      std::perror("list1302.out");
    else
    {
      int x(0);
      while (in >> x)
        out << x << '\n';
      out.close();
      if (not out)
        std::perror("list1302.out");
    }
  }
}

```

### 14. 数据结构 映射

### 15. 类型 同义词

### 16. 字符

### 17. 字符 分类

### 18. 大小写转换

### 19. 编写函数

### 20. 函数实参

### 21. 使用算法

### 22. 重载函数名

### 23. 大数和小数

### 24. 极大数和极小数

### 25. 文档

## 自定义类型(面向对象重点)

## 泛型 编程

## 实时 编程

