#if 0
#include <iostream>
#include <string>
#include <unordered_set>

std::unordered_set<std::string> s;
std::string v;
int n, c = 0;

int main()
{
    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> v;
        if (!s.count(v))
            c++;
        s.insert(v);
    }
    std::cout << c << std::endl;
    return 0;
}
#endif