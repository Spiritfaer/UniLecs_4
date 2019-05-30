#include <stdio.h>
#include <stdint.h>

/*

It is given a sorted in ascending, but cyclically shifted array.
It is necessary to display the index of the given element X (if there is such an element) in the array.
Example: [9, 10, 11, 1, 2, 3, 4, 5, 6, 7, 8]; X = 8
Conclusion: 10

Дан отсортированный по возрастанию, но циклически сдвинутый массив.
Нужно вывести индекс заданного элемента X (если такой элемент есть) в массиве.
Пример: [9, 10, 11, 1, 2, 3, 4, 5, 6, 7, 8]; X = 8
Вывод: 10

*/

int64_t find_num(int32_t *arr, uint32_t size, int32_t num)
{
	int32_t *start, *end, *mid;

	if (!arr || size < 2)
		return (0);
	start = arr;
	mid = arr + (size / 2 - 1);
	end = (arr + size - 1);
	while (end - start > 1)
	{
		if(*start ==  num || *end == num)
			break;
		if (*start < *mid)
			start = mid;
		else
			end = mid;
		mid = start + ((end - start) / 2);
	}
	if (*start ==  num)
		return (start - arr);
	else if (*end == num)
		return  (end - arr);
	else
		return (-1);
}

int main(void)
{
	int32_t arr_1[] = {9, 10, 11, 1, 2, 3, 4, 5, 6, 7, 8};
	int32_t num = 8;
	uint32_t size = sizeof(arr_1) / sizeof(int32_t);
	int64_t index = find_num(arr_1, size, num);
	(index < 0) ? printf("The number didn't found\n") : printf("arr_1[%lli] = %i\n", index, arr_1[index]);
	return (0);
}
