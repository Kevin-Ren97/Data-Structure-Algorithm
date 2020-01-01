#include<iostream>
#include<algorithm>

using ElementType = int;	// #define ElementType int

void Selection_sort(ElementType a[], size_t size)
{
	for (size_t i = 0; i < size; i++) {
		size_t min_index = i;
		for (size_t j = i + 1; j < size; j++) {
			if (a[min_index] > a[j]) {
				min_index = j;
			}
		}
		std::swap(a[min_index], a[i]);
	}
}

void Sort(ElementType a[], size_t size)	// The outer function
{
	Selection_sort(a, size);
}

int main(){
	ElementType a[10] = { 5,6,2,3,9,4,10,8,7,1 };	//just an example
	Sort(a, 10);
	for (size_t i = 0; i < 10; i++) {
		std::cout << a[i] << " ";
	}
	return 0;
}
