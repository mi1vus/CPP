/*
Задача на программирование: наибольший общий делитель

По данным двум числам 1≤a,b≤2⋅109 найдите их наибольший общий делитель.
*/

#include <cassert>
#include <iostream>

template <class Int>
Int gcd(Int a, Int b) {
  // optimize this function
    if(a == 0)
        return b;
    if(b == 0)
        return a;
    
    if (a >= b)
        return gcd(a % b, b);
    else
        return gcd(b%a, a);
}

int main(void) {
  int a, b;
  std::cin >> a >> b;
  std::cout << gcd(a, b) << std::endl;
  return 0;
}
