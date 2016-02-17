/*
Задача на программирование: наибольшая последовательнократная подпоследовательность

Дано целое число 1≤n≤103 и массив A[1…n] натуральных чисел, не превосходящих 2⋅109. Выведите максимальное 1≤k≤n, для которого найдётся подпоследовательность 1≤i1<i2<…<ik≤n длины k, в которой каждый элемент делится на предыдущий (формально: для  всех 1≤j<k, A[ij]|A[ij+1]).
*/

#include <algorithm>
#include <cstddef>
#include <iostream>
#include <vector>
/*
int get_length_of_longest_divisible_subsequence(const std::vector<int> &numbers) {
  // TODO optimize this function
  int result = 0;
  for (size_t i = 0; i < numbers.size(); i++) {
    int first_number = numbers[i];

    std::vector<int> left_numbers;
    std::remove_copy_if(numbers.begin() + i + 1, numbers.end(), std::back_inserter(left_numbers), [first_number] (int number) { return number % first_number != 0; });
    auto current_result = 1 + get_length_of_longest_divisible_subsequence(left_numbers);
    if (current_result > result) {
      result = current_result;
    }
  }
  return result;
}
*/

int get_length_of_longest_divisible_subsequence(const std::vector<int> &numbers) {
  // TODO optimize this function
  int result = 0;

  std::vector<int>* D = new std::vector<int>();

  for (int i = 0; i < numbers.size(); ++i){
	(*D).push_back(1);
	for (int j = 0; j < i; ++j){
		if (numbers[j] <= numbers[i] && numbers[i]%numbers[j]==0 && (*D)[j] + 1 > (*D)[i])
				(*D)[i] = (*D)[j] + 1;
	}
  }

  for (int i = 0; i < D->size(); ++i)
	  if (result < (*D)[i])
		  result = (*D)[i];

  return result;
}

int main(void) {
  size_t number_count;
  std::cin >> number_count;
    int number = 0;
  std::vector<int> numbers(number_count);
  for (int i = 0; i < number_count; ++i) {
    std::cin >> number;
      numbers[i] = number;
  }

  std::cout << get_length_of_longest_divisible_subsequence(numbers) << std::endl;

  system("pause");
}
