#include<iostream>

using ElementType = int;	// #define ElementType int

void Sort(ElementType a[], size_t size)	// The outer function
{
	Bubble_sort(a, size);
}

void Bubble_sort(ElementType a[], size_t size)
{
	for (size_t i = 0; i < size; i++) {
		bool noChange = true;	// if in one travel there is no swap then break;
		for (size_t j = size - 1; j > i; j--) {
			if (a[j - 1] > a[j]) {
				std::swap(a[j - 1], a[j]);
				noChange = false;
			}
		}
		if (noChange)
			break;
	}
}

int main(){
	ElementType a[10] = { 5,6,2,3,9,4,10,8,7,1 };
	ElementType b[10] = { 1,2,3,4,5,6,7,8,9,10 };
	Sort(a, 10);
	for (size_t i = 0; i < 10; i++) {
		std::cout << a[i] << " ";
	}
	return 0;
}
