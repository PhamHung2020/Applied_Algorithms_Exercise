#include<iostream>


int main(){
    int x1, x2, x3, x4, x5, x6, x7, x8, cnt;
    cnt = 0;
    for (x1 = 1; x1 <= 10; ++x1)
    {
        for (x2 = 1; x2 <= 10; ++x2)
        {
            for (x3 = 1; x3 <= 10; ++x3)
            {
                for (x4 = 1; x4 <= 10; ++x4)
                {
                    for (x5 = 1; x5 <= 10; ++x5)
                    {
                        for (x6 = 1; x6 <= 10; ++x6)
                        {
                            for (x7 = 1; x7 <= 10; ++x7)
                            {
                                for (x8 = 1; x8 <= 10; ++x8)
                                {
                                    if (x1 + x2 + x3 + x4 + x5 + x6 + x7 + x8 == 19)
                                    ++cnt;
                                }
                            }
                                
                        }
                    }
                }
            }
        }
    }
    std::cout << cnt;
    return 0;
}

