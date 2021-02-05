//平均值

#include<iostream>
#include<ostream>

int main()
{
    int sum(0);
    int N(0);
    int x;
    while(std::cin >> x)
    {
        sum=sum+x;
        N+=1;
    }
    if(N==0){
        std::cout<<"there is no number"<<'\n';
    }
    else{
        std::cout<<"averge is "<<sum/N<<'\n';
    }
    
    return 0;
}