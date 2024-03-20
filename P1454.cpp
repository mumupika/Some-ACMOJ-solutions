#if 0
#include <iostream>
#include<iomanip>
using namespace std;

double expectation(double a, int k) 
{
    double ans = 1;
    while (k)
    {
        if (k % 2)
        {
            ans *= a;
        }
        a *= a;
        k /= 2;
    }
    return ans;
}
int main() 
{
    int n;
    double p;
    cin >> n >> p;
    double exp = expectation(p, 2 * n + 1);
    double ans = (p - exp) / (1 + p);
    ans += 2 * n;
    ans /= (1 + p);
    cout << setprecision(15) << ans << endl;
    return 0;
}
#endif