/*
Задача на программирование повышенной сложности: огромное число Фибоначчи по модулю



Даны целые числа 1≤n≤1018 и 2≤m≤105, необходимо найти остаток от деления n-го числа Фибоначчи на m.
*/


#include <iostream>

long long digits(long long num, long long period)
{
	long long i = 0;
	while (num != 0)
	{
		num /= period;
		i++;
	}
	return i-1;
}

int main() {
// put your code here
	//вычисление числа Фиббоначи по модулю с использованием последовательности Пизано
	const long long dept = 50;
	long long matrix[dept];

    long long num = 0;
	long long divider = 0;
    std::cin >> num; 
	std::cin >> divider;

    long long i = 2;
    long long fib_1_mod = 1,fib_2_mod = 0,fib_mod = 0;
	long long div_squere = divider*divider;

	matrix[0] = 0;
	matrix[1] = 1;
	for (long long j = 2; j < dept; j++)
	{
		fib_mod = (fib_1_mod + fib_2_mod)%divider;
		fib_2_mod = fib_1_mod;
		fib_1_mod = fib_mod; 
		matrix[j] = fib_mod;
	}

	fib_1_mod = 1;fib_2_mod = 0;fib_mod = (fib_1_mod + fib_2_mod)%divider;
	if (num == 1 || num == 0)
		fib_mod = num;
	else
	{
		while (i <= div_squere)
		{
			fib_mod = (fib_1_mod + fib_2_mod)%divider;
			fib_2_mod = fib_1_mod;
			fib_1_mod = fib_mod; 
			if (fib_mod == matrix[0])
			{
				long long fib_st = fib_mod, fib1_st = fib_1_mod, fib2_st = fib_2_mod;
				long long j = 0;
				for (j = 0; j < dept; j++)
				{
					if (matrix[j] != fib_mod )
						break;
					fib_mod = (fib_1_mod + fib_2_mod)%divider;
					fib_2_mod = fib_1_mod;
					fib_1_mod = fib_mod;
				}
				if (j == dept)
					break;
				else
					fib_1_mod = fib1_st;fib_2_mod = fib2_st;fib_mod = fib_st;
			}
			i++;
		}
		long long period = i;

		long long multiplier = digits(num,10) - digits(period,10);
		while(multiplier > 0)
		{
			div_squere = 1;
			for (long long j = 0; j<multiplier;j++)
				div_squere = div_squere*10;

			div_squere = period*div_squere;
			while(num >= div_squere)
				num -= div_squere;
			multiplier--;
		}

		while(num >= period)
			num -= period;

		i=2;
		fib_1_mod = 1;fib_2_mod = 0;fib_mod = 0;

		if (num == 1 || num == 0)
			fib_mod = num;
		else 
			while (i <= num)
			{
				fib_mod = (fib_1_mod + fib_2_mod)%divider;
				fib_2_mod = fib_1_mod;
				fib_1_mod = fib_mod; 
				i++;
			}
	}
    
  std::cout << fib_mod; 
  return 0;
}
