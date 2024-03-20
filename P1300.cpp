#if 0
#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;
const int N = 4e7 + 1;
#define LL long long
LL n, k, m;
vector <LL> a;
void read_input_data_array() 
{
    cin >> n >> k >> m;
    a.resize(n);
    for (int i = 0; i < m; i++) 
    {
        cin >> a[i];
    }
    unsigned int z = a[m-1];
    for (int i = m; i < n; i++) 
    {
        z ^= z << 13;
        z ^= z >> 17;
        z ^= z << 5;
        a[i] = z & 0x7fffffff;
    }
}
int partition(vector<LL>& nums, int l, int r) 
{
        int pivot = nums[r];
        int i = l - 1;
        for (int j = l; j <= r - 1; ++j) {
            if (nums[j] <= pivot) {
                i = i + 1;
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[i + 1], nums[r]);
        return i + 1;
}
// 基于随机的划分
int randomized_partition(vector<LL>& nums, int l, int r) {
    int i = rand() % (r - l + 1) + l;
    swap(nums[r], nums[i]);
    return partition(nums, l, r);
}
void randomized_selected(vector<LL>& arr, int l, int r, int k) {
    if (l >= r) {
        return;
    }
    int pos = randomized_partition(arr, l, r);
    int num = pos - l + 1;
    if (k == num) {
        return;
    } else if (k < num) {
        randomized_selected(arr, l, pos - 1, k);
    } else {
        randomized_selected(arr, pos + 1, r, k - num);
    }
}

int main()
{
    srand(time(0));
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    read_input_data_array();
    srand(time(NULL));
    randomized_selected(a,0,(LL)a.size()-1,k);
    cout << a[k-1];
}
#endif