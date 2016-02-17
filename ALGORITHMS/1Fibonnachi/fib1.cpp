/*
Дано целое число 1≤n≤40, необходимо вычислить n-е число Фибоначчи (напомним, что F0=0, F1=1 и Fn=Fn−1+Fn−2 при n≥2).
*/


#include <iostream>

using namespace std;

long fib(int n){
    if (n < 2)
        return n;
    
    long n1 = 0;
    long n2 = 1;
    
    for (int i = 1; i < n; ++i){
        int tmp = n1;
        n1 = n2;
        n2 = tmp + n2;
    }
    return n2;
}

int main() {
    
    int n = 0;
    cin >> n;
    cout << fib(n);
    
  return 0;
}
