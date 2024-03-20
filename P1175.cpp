#if 0
#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;
struct student{
    int sex;
    long long intime;
    bool operator<(const student&that){
        return intime<that.intime;
    }
    bool operator>(const student&that){
        return intime>that.intime;
    }
    bool operator==(const student&that){
        return intime==that.intime;
    }
};

int main() 
{
    int n;
    int m;
    scanf("%d",&n);
    vector<long long>eachtime(n);
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&eachtime[i]);
        if(i>0) 
        {
            eachtime[i] += eachtime[i - 1];
        }
    }
    scanf("%d",&m);
    vector<student>sm;
    vector<student>sw;
    for(int i=0;i<m;i++)
    {
        int tmp;
        scanf("%d",&tmp);
        if(tmp==1){
            student t;
            t.sex=tmp;
            scanf("%lld",&t.intime);
            sm.push_back(t);
        }
        else{
            student t;
            t.sex=tmp;
            scanf("%lld",&t.intime);
            sw.push_back(t);
        }
    }
    sort(sm.begin(),sm.end());
    sort(sw.begin(),sw.end());
    long long resm=0,resw=0;
    int indexm=0,indexw=0;
    for(int i=0;i<n;i++){
        if(i!=0&&i!=n-1){
            while(indexm<sm.size()&&indexw<sw.size()&&sm[indexm].intime<=eachtime[i-1]&&sw[indexw].intime<=eachtime[i-1]){
                resm +=(eachtime[i-1] - sm[indexm++].intime);
                resw +=(eachtime[i-1] - sw[indexw++].intime);
            }
        }
        else if(i==n-1&&n!=1){
            while(indexm<sm.size()){
                resm +=eachtime[n-2]-sm[indexm++].intime;
            }
            while(indexw<sw.size()){
                resw +=eachtime[n-2]-sw[indexw++].intime;
            }
        }
        else if(i==0){
            while(indexm<sm.size()&&indexw<sw.size()&&sm[indexm].intime==0&&sw[indexw].intime==0){
                indexm++;
                indexw++;
            }
        }
    }
    double r1=(double)resm/sm.size();
    double r2=(double)resw/sw.size();
    if(sw.size()!=0&&sm.size()!=0) {
        cout << fixed << setprecision(2) << r1 << " " << r2;
    }
    else if(sw.size()==0&&sm.size()==0){
        cout << fixed << setprecision(2) << 0 << " " << 0;
    }
    else if(sw.size()!=0&&sm.size()==0){
        cout << fixed << setprecision(2) << 0 << " " << r2;
    }
    else if(sw.size()==0&&sm.size()!=0){
        cout << fixed << setprecision(2) << r1 << " " << 0;
    }
    return 0;
}
#endif