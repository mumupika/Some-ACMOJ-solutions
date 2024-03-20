#if 0
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    vector<string> a;
    vector<string> b;
    map<string,string> c;
    map <string, string> :: iterator c1_iter;
    int count;
    string temp;
    cin >> count;
    for(int i=0;i<count;i++)
    {
        cin >> temp;
        a.push_back(temp);
        temp="";
    }
    for(int i=0;i<count;i++)
    {
        cin >> temp;
        b.push_back(temp);
        temp="";
    }
    c.insert(pair<string,string>(a[0],b[0]));

    for(int i=1;i<count;i++)
    {
        if(!c.count(a[i]))
        {
            c.insert(pair<string,string>(a[i],b[i]));
            
        }
        else if(c.count(a[i]))
        {
            temp=c.at(a[i]);
            if(temp==b[i])
                continue;
            else
            {
                cout << "No";
                return 0;
            }
        }
    }
    cout << "Yes";
    return 0;
}
#endif