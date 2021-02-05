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