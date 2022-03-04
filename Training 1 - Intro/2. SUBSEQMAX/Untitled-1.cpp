#include <iostream>

int f(int n){
    int s = 0;
    int a = 1;
    int i = 0;
    while(s <= n){
        s = s + a;
        a = 2 * a;
        i++;
    }
    return i;
}

int main()
{
    int n;
    std::cin >> n;
    std::cout << f(n);
    return 0;
}