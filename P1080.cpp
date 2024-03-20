#if 0
#include<iostream>
#include<algorithm>
#include<stack>//stack STL function.
#include<cstring>//important: for stoi:string convert to int; to_string:int convert to string.
using namespace std;
int main()
{
    stack<string> str;
    string c,tmp="";
    cin >> c;
    for(auto i:c)//auto: using iterator to refer c[i++];
    {
        if (i != '.' && i != '+' && i != '-' && i != '*' && i != '/' || i == '@')
        {
            tmp+=i;
        }
        else if(i=='.')
        {
            str.push(tmp);
            tmp="";
        }
        else
        {
            int x=stoi(str.top());
            str.pop();
            int y=stoi(str.top());
            str.pop();
            if(i=='+')
                str.push(to_string(x+y));
            else if(i=='-')
                str.push(to_string(y-x));
            else if(i=='*')
                str.push(to_string(x*y));
            else if(i=='/')
                str.push(to_string(y/x));
        }
    }
    cout << stoi(str.top()) << endl;
    return 0;
}
/**
 * Tips:
 * 1.转换函数：将字符串转换成数字的函数：stoi。stoi可以将任意字符串转换成各个进制的数字。限定范围在int之内。
 * 原型：int stoi( const std::string& str, std::size_t* pos = nullptr, int base = 10 );
 * str:将要进行转换的字符。
 * pos:可以为一个空指针，此时没有进行使用。即为返回时包含首个未转换字符的索引。
 * base:转换的进制。
 * 1.1 tips:与stoi类似的是atoi函数。atoi函数为：
 * int atoi(const std::char& str, std::size_t* pos=nullptr, int base=10);
 * 即转换的为char*类型的字符数组。
 * 2.to_string函数：
 * 
*/
#endif