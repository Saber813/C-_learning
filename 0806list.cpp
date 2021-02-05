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