#if 0
#include <iostream> 
#include <vector> 
using namespace std; 
// 定义矩阵乘法函数 
vector<vector<long long> > matrix_multiply(vector<vector<long long> > a, vector<vector<long long> > b) 
{ 
    int n = a.size(); 
    vector<vector<long long> > c(n, vector<long long>(n, 0)); 
    for (int i = 0; i < n; i++) 
    { 
        for (int j = 0; j < n; j++) 
        { 
            for (int k = 0; k < n; k++) 
            { 
                c[i][j] += a[i][k] * b[k][j]; 
            } 
        } 
    } return c; 
} 
// 定义矩阵快速幂函数 
vector<vector<long long> > matrix_power(vector<vector<long long> > a, int n) 
{ 
    if (n == 1) 
    { 
        return a; 
    } 
    else if (n % 2 == 0) 
    { 
        vector<vector<long long> > half = matrix_power(a, n/2);
        return matrix_multiply(half, half); 
    } 
    else 
    { 
        vector<vector<long long> > half = matrix_power(a, (n-1)/2); 
        return matrix_multiply(matrix_multiply(half, half), a); 
    } 
} 
// 定义斐波那契数列函数，使用矩阵快速幂算法 
int fibonacci(int n) 
{ 
    if (n == 0) 
    { 
        return 0;
    } 
    else 
    { 
        vector<vector<long long> > base(2,vector<long long>(2,0));
        base[0][0]=1;base[0][1]=1;base[1][0]=1;base[1][1]=0; 
        vector<vector<long long> > result = matrix_power(base, n-1); 
        return result[0][0]; 
    } 
} 
int main() 
{ 
    int n;
    cin >> n; 
    cout  << fibonacci(n) << endl; 
    return 0; 
}
#endif