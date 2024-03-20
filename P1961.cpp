#if 0
#include<iostream>
#include<cstring>
#define ll long long
using namespace std;
ll quickPow(int n,int t)
{
    if(t==0) return 1;
    if(t==1) return n;
    
    if(t%2==0)
        return quickPow(n,t/2)*quickPow(n,t/2);
    else
        return n*quickPow(n,t/2)*quickPow(n,t/2);
}
bool check_date(string &s)
{
    string year,month,day;
    for(int i=0;i<8;i++)
        if(s[i]-48<0 || s[i]-48>9)
            return false;
    for(int i=0;i<4;i++)
        year+=s[i];
    for(int i=4;i<6;i++)
        month+=s[i];
    for(int i=6;i<8;i++)
        day+=s[i];
    int Year=stoi(year),Month=stoi(month),Day=stoi(day);
    bool flag;//闰年判断
    if(Year<1582||Month>12||Month<0||Day<0||Day>31) return false;
    else if(Year==1582)
    {
        if(Month<10) return false;
    }
    else
    {
        if(Year%100==0)
        {
            if(Year%400==0)
                flag=true;
            else
                flag=false;
        }
        else
            if(Year%4==0)
                flag=true;
            else
                flag=false;
    }

    switch(Month)
    {
        case 1:if(Day<=31) return true; else return false;break;
        case 2:if(flag) if(Day<30) return true; else return false; else if(Day<29) return true; else return false; break;
        case 3:if(Day<=31) return true; else return false;break;
        case 4:if(Day<31) return true; else return false;break;
        case 5:if(Day<=31) return true; else return false;break;
        case 6:if(Day<31) return true; else return false;break;
        case 7:if(Day<=31) return true; else return false;break;
        case 8:if(Day<=31) return true; else return false;break;
        case 9:if(Day<31) return true; else return false;break;
        case 10:if(Day<=31) return true; else return false;break;
        case 11:if(Day<31) return true; else return false;break;
        case 12:if(Day<=31) return true; else return false;break;
        default: return false;
    }
}
bool check_parity(char &c,string &s)
{
    int p;
    switch(c)
    {
        case '0':p=0;break;
        case '1':p=1;break;
        case '2':p=2;break;
        case '3':p=3;break;
        case '4':p=4;break;
        case '5':p=5;break;
        case '6':p=6;break;
        case '7':p=7;break;
        case '8':p=8;break;
        case '9':p=9;break;
        case 'X':p=10;break;
        default:return false;
    }
    ll sum=0;
    for(int i=16;i>=0;i--)
        sum+=(s[i]-48)*(quickPow(2,17-i)%11);
    sum=(sum+p)%11;
    if(sum==1) return true;
    else return false;
}
string check(string &s)
{
    string temp;
    char c;
    for(int i=6;i<=13;i++)
        temp+=s[i];
    c=s[17];
    if(check_date(temp) && check_parity(c,s))
        return "True\n";
    else
        return "False\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int num;
    cin >> num;
    string s;
    string res[num];
    for(int i=0;i<num;i++)
        res[i]="";
    for(int i=0;i<num;i++)
    {
        s="";
        cin >> s;
        if(s.size()<18 || s.size()>18)
        {
            res[i]="False\n";
            continue;
        }
        res[i]=check(s);
    }
    for(int i=0;i<num;i++)
        cout << res[i];
    return 0;
}
#endif