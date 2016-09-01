#include <iostream>
#include <string>
#include <cstring>
#include <stdio.h>
#include <cmath>

long long root(long long number){
    double descrim = sqrt(1+8*((double)number));
    if (descrim != (long long)descrim)
        return 0;
	long long res = ((long)descrim - 1) / 2;
	if (number == (res + 1)*res / 2)
		return res;
	else
		return 0;
}

int main() {
    // put your code here
    // определение номера треугольного числа
    long long inp_ut;

  	char str[255],*p;
  	p = str;
    if (scanf("%s",str,255))
    {
		char c = *(p++);
		if (c == '+')
			c = *(p++);
		while (c != '\0')
		{
			if ((c < '0' || c > '9') && c != '\n' && c != '+')
			{
				printf("0");
				return 0;
			}

			c = *(p++);
		}

		try 
		{
			char* pEnd;
			inp_ut = std::strtoull(str, &pEnd, 10);
			if (errno == ERANGE || inp_ut > 9223372036854775807LL || inp_ut == 0)
				printf("0");
			else
				printf("%d", root(inp_ut));
		}
		catch (...)
		{
			printf("0");
		}
    }
    else
        printf("0");
    
    return 0;
}
