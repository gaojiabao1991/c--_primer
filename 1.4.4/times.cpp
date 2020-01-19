#include <iostream>
int main()
{
    int pre = 0, cur = 0;
    if (std::cin >> pre)
    {
        int cnt = 1;
        while (std::cin >> cur)
        {
            if (cur == pre)
            {
                cnt++;
            }
            else
            {
                std::cout << "count of " << pre << " is " << cnt << std::endl;
                pre = cur;
                cnt = 1;
            }
        }
        std::cout << "count of " << pre << " is " << cnt << std::endl;
    }
}