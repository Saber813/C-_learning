
#include<algorithm>
#include<iostream>
#include<iterator>
#include<locale>
#include<string>
using namespace std;

bool is_palindrome(string line);
bool non_letter(char ch);
bool samechar(char a, char b);
char lowercase(char ch);

int main(){
    locale::global(locale(""));
    cin.imbue(locale(""));
    cout.imbue(locale(""));


    string line;
    while(getline(cin,line)){
        if(is_palindrome(line))
            cout<<line<<"\n";
    }
}

bool is_palindrome(string line){
    string::iterator end(remove_if(line.begin(),line.end(),non_letter));
    string rev(line.begin(),end);
    reverse(rev.begin(),rev.end());
    return not rev.empty() and equal(line.begin(),end,rev.begin(),samechar);
}
bool non_letter(char ch){
    return not isalpha(ch,locale(""));
}
bool same_char(char a, char b){
    return lowercase(a) == lowercase(b);
}
char lowercase(char ch){
    return tolower(ch,locale());
}