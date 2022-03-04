#include<iostream>

int f(int n){
if(n <= 1) return 1;
if(n%2 == 0) return 2*f(n-1) + f(n-2);
else return f(n-1) - 2*f(n-2);
}
int main(){
printf("%d",f(5));
}