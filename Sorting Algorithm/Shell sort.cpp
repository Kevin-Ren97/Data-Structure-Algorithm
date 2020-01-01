#include<iostream>
#include<algorithm>

using ElementType = int;	// #define ElementType int

void Shell_sort(ElementType a[], size_t size)
{
	for (int Increment = size / 2; Increment > 0; Increment /= 2) {		//Increment - index intervals
		for (int i = Increment; i < size; i++) {
			ElementType tmp = a[i];
			size_t j;
			for (j = i; j >= Increment; j -= Increment) {		// similar to the Insertion sort
				if (tmp < a[j - Increment])
					a[j] = a[j - Increment];
				else
					break;
			}
			a[j] = tmp;
		}
	}
}

void Sort(ElementType a[], size_t size)	// The outer function
{
	Shell_sort(a, size);
}

int main(){
	ElementType a[10] = { 5,6,2,3,9,4,10,8,7,1 };
	Sort(a, 10);
	for (size_t i = 0; i < 10; i++) {
		std::cout << a[i] << " ";
	}
	return 0;
}
