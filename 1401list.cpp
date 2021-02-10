#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <iomanip>
#include <algorithm>
using namespace std;

int main()
{
    // version 1 console IO
    // map<string,int> couts;
    // string word;
    // while(cin>>word)
    //     ++couts[word];
    // version 2 file IO
    string data_path("D:\\Projects\\C++_learning\\explore14.txt");
    ifstream in(data_path);
    if (not in)
        perror("D:\\Projects\\C++_learning\\explore14.txt");
    else
    {
        ofstream out("D:\\Projects\\C++_learning\\statistic_test.txt");
        if (not out)
            perror("D:\\Projects\\C++_learning\\statistic_test.txt");
        else
        {
            map<string, int> counts;
            string word;
            while (in >> word)
            {
                string okay("ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                            "abcdefghijklmnopqrstuvwxyz0123456789-_");
                string copy;
                for (string::iterator iter(word.begin()); iter != word.end(); ++iter)
                {
                    if (okay.find(*iter) != string::npos)
                        copy.push_back(*iter);
                }
                if (not copy.empty())
                        ++counts[copy];
               
                //cout<< word <<"\t"<<counts[word] <<'\n';
            }
            // 遍历一下 然后输出 使用iterator
            //sort(counts);
            string::size_type maxsize(0);
            for (map<string, int>::iterator iter(counts.begin()); iter != counts.end(); ++iter)
            {
                if (iter->first.size() > maxsize)
                {
                    maxsize = iter->first.size();
                }
            }

            for (map<string, int>::iterator iter(counts.begin()); iter != counts.end(); ++iter)
            {

                out << setw(maxsize) << left << iter->first
                    << setw(10) << right << iter->second << '\n';
            }
            map<string, int>::iterator iter(counts.find("the"));
            if (iter != counts.end())
                cout << iter->second;
            in.close();
            out.close();
            if (not out)
                perror("D:\\Projects\\C++_learning\\statistic_test.txt");
        }
    }
}