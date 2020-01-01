#include<iostream>

using ElementType = int;	// #define ElementType int

void Sort(ElementType a[], size_t size)	// The outer function
{
	Insertion_sort(a, size);
}

void Insertion_sort(ElementType a[], size_t size)
{
	for (size_t i = 1; i < size; i++) {
		ElementType tmp = a[i];
		size_t j;
		for (j = i; j > 0 && a[j - 1] > tmp; j--) {
			a[j] = a[j - 1];
		}
		a[j] = tmp;
	}
}

int main(){
	ElementType a[10] = { 5,6,2,3,9,4,10,8,7,1 };
	Sort(a, 10);
	for (size_t i = 0; i < 10; i++) {
		std::cout << a[i] << " ";
	}
	return 0;
}
