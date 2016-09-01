#include <iostream>
#include <string>
#include <cstring>
#include <stdio.h>
#include <cstdlib>
#include <cmath>
#include <vector>

#define MAXLEN 64

/*
int is_float(char *s) {
	int n;
	double d;
	scanf_s(s, "%lf%n", &d, &n);

	return (n == strlen(s)) ? 1 : 0;
}

int is_int(char *s) {
	int n;
	int i;
	sscanf_s(s, "%d%n", &i, &n);

	return (i > 0 && n == strlen(s)) ? 1 : 0;
}

int is_valid(char *s) {
	int flag = 1;

	do {
		if (*s != ' ' && *s != '\n' && *s != '+' && *s != '-' && *s != 'E' && *s != 'e' && *s != '.' && !isdigit(*s)) {
			flag = 0;
			break;
		}

		*s++;
	} while (*s);

	return flag;
}
*/

void get_subline(const char *line)
{
	long pos = 0, actual_numbers = 0;
	char cur_character = line[pos], pre_character = '\0';
	bool is_point = false, is_expon = false, is_space = false;
	for (size_t curr = 0; curr < strlen(line); ++curr)
	{
		cur_character = line[curr];
		if (cur_character == ' ' || cur_character == '\n')
		{
			if (cur_character == ' ' && is_space)
			{
				printf("[error]\n");
				return;
			}
			else
			{
				if (cur_character == ' ')
					is_space = true;
				pos = 0;
				is_point = false;
				is_expon = false;
				if (curr)
					++actual_numbers;
			}
		}
		else
		{
			if (is_space)
			{
				is_space = false;
				pos = 0;
			}

			if (isdigit(cur_character) ||
				((cur_character == '+' || cur_character == '-') && (pos == 0 || (tolower(pre_character) == 'e'))) ||
				(cur_character == '.' && !is_point) ||
				(isdigit(pre_character) && tolower(cur_character) == 'e' && !is_expon)) 
			{
				if (cur_character == '.')
					is_point = true;
				if (tolower(cur_character) == 'e')
					is_expon = true;
				pre_character = cur_character;
			}
			else
			{
				printf("[error]\n");
				return;
			}
		}
	}

	double numbers;
	std::vector<double> vec;
	char * ptrEnd;
	numbers = strtod(line, &ptrEnd);
	if (errno == ERANGE || numbers < 2 || numbers != (double)((int)numbers) || actual_numbers < (int)numbers)
	{
		printf("[error]\n");
		return;
	}

	long long max_length = 1;
	long long max_line_pos = 0;
	long long curr_length = 1;
	long long curr_line_pos = 0;
	double old_num;
	old_num = strtod(ptrEnd, &ptrEnd);
	for (int i = 1; i < (int)numbers; ++i)
	{
		double curr_num;
		curr_num = strtod(ptrEnd, &ptrEnd);
		if (old_num <= curr_num)
		{
			++curr_length;
		}
		else
		{
			if (max_length < curr_length)
			{
				max_length = curr_length;
				max_line_pos = curr_line_pos;
			}

			curr_line_pos = i;
			curr_length = 1;
		}
		old_num = curr_num;
	}

	if (max_length < curr_length)
	{
		max_length = curr_length;
		max_line_pos = curr_line_pos;
	}

	if (max_length > 1)
		printf("%lld %lld\n", max_length, max_line_pos + 1);
	else
		printf("0\n");
	
	//printf("act_num:%d  -----  %d\n", actual_numbers, (int)numbers);
}

int main() {
	double numbers;

	std::string str;
	std::getline(std::cin, str);
	get_subline(str.c_str());
/*
	char t[][MAXLEN] = {
		"10 1 2 3", "[error]",
		"10\n1 2 3 1 2 3 1 1 1 1", "4 7",
		"10   1 2 3 1 2 3 1 1 1 1", "[error]",
		"10 1 2   3 1 2 3 1 1 1 1", "[error]",
		"10 1 2 3 1 2 3 1 1 1 1", "4 7",
		"+10 1 2 3 1 2 3 1 1 1 1", "4 7",
		"10 1 2 3 4 3 3 1 2 3 4", "4 1",
		"10 1.5 2 3 4.7 3 3 1 2 3 4", "4 1",
		"3 1 2 3 1 2 3 1 1 1 1", "3 1",
		"3 10 20 30 40 50", "3 1",
		"5 5 4 3 2 1", "0",
		"4 3 2 1 2", "2 3",
		"4 3e1 2e1 1e1 -2.700000e+00", "0",
		"6 -1 -2 -1 -2 -1 -2", "2 2",
		"4 0.5 1.789 -0.555 +0.555", "2 1",
		"3 4 1 2", "2 2",
		"3 1 0 2", "2 2",
		"7 1 2 1 2 1 2 3", "3 5",
		"4 1 2 1 2", "2 1",
		"3 1 2 3", "3 1",
		"", "[error]",
		"1 1", "[error]",
		"10.1 1 2 3 1 2 3 1 1 1 1", "[error]",
		"-3 1 2 3", "[error]",
		"3- 1 2 3", "[error]",
		"10", "[error]",
		"3 10 20 30 40 50  zxczxc", "[error]",
		"3 1 2 -2.70e0000e+00", "[error]",
		"3 1 2 -2.70E0000E+00", "[error]",
		"3 1 2 -2.70e0000E+00", "[error]",
		"3 1 2 -2.70+0000E+2", "[error]",
		"3 1 2 -2.70-0000E-2", "[error]",
	};

	for (int i = 0; i < sizeof(t) / MAXLEN; i += 2) {
		printf("%-7s :  %s\n", t[i + 1], t[i]);
		get_subline(t[i]);
	}
*/
	//scanf_s("%lf", &numbers);

	return 0;
}
