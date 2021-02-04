// 把标准输入按照字母表顺序进行排序
// 逐行读取文本, 进行排序,并把结果打印到标准输出
// 如果命令行输入了一个文件名 则从文件读入 否则从标准输入读入 
// 所有的 输入保存在内存中
#include<algorithm>
#include<fstream>
#include<iostream>
#include<iterator>
#include<ostream>
#include<string>
#include<vector>

void read(std::istream& in, std::vector<std::string>& text)
{
    std::string line;
    while (std::getline(in,line))
        text.push_back(line);
}
 int main(int argc, char* argv[])
 {
     // 第一部分 把所有出入读入text 如果命令行输入一个文件名, 则读取那个文件
     // 否则读取标准输入, 
    std::vector<std::string> text;//把行文版保存在这里
    if (argc < 2)
        read(std::cin,text);
    else
    {
        std:: ifstream in(argv[1]);
        if(not in)
        {
            std::perror(argv[1]);
            return EXIT_FAILURE;
        }
        read(in,text);
    }
    // 第二部分 对text进行排序
    std::sort(text.begin(),text.end());
    // 第三部分 打印排序好的text
    std::copy(text.begin(),text.end(),std::ostream_iterator<std::string>(std::cout,"\n"));


 }
 