#include <iostream>
#include <vector>

void printArray(std::vector<int> arr)
{
    int length = (int)arr.size();
    std::cout << length << ' ';
    for (int i = 0; i < length; ++i)
    {
        std::cout << arr[i] << ' ';
    }
    std::cout << '\n';
}

int main()
{
    int n;
    std::vector<int> first, second, third;
    std::cin >> n;

    int temp;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> temp;
        if (temp > 0)
            second.push_back(temp);
        else if (temp == 0)
            third.push_back(temp);
        else
        {
            if (first.empty())
                first.push_back(temp);
            else
            {
                third.push_back(temp);
            }
        }
    }

    if (second.empty())
    {
        int count = 0;
        bool isZeroLost = false;
        while (count < 2)
        {
            int a = third.back();
            if (a < 0)
            {
                ++count;
                second.push_back(a);
            }
            else
                isZeroLost = true;
            third.pop_back();
        }

        if (isZeroLost)
            third.push_back(0);
    }

    printArray(first);
    printArray(second);
    printArray(third);

    return 0;
}