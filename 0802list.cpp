#include<iostream>
#include<iomanip>

using namespace std;
int main()
{
    int i(1);
    int b(12);
    std::cout<< setfill('0') <<std::setw(6)<<i<<"\n"
    << setfill('0') << std::setw(6)<<b;

}