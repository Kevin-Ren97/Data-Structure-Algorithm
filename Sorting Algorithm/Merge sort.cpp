#include<iostream>
#include<exception>

using ElementType = int;	// #define ElementType int

void Merge(ElementType a[], ElementType tmp[], size_t leftBeg, size_t RightBeg, size_t RightEnd)
{
	int LeftEnd = RightBeg - 1, tmpPos = leftBeg, numElement = RightEnd - leftBeg + 1;
	while (leftBeg <= LeftEnd && RightBeg <= RightEnd) {
		if (a[leftBeg] <= a[RightBeg]) {
			tmp[tmpPos++] = a[leftBeg++];
		}
		else {
			tmp[tmpPos++] = a[RightBeg++];
		}
	}

	//copy the rest of the first/second part
	while (leftBeg <= LeftEnd) tmp[tmpPos++] = a[leftBeg++];
	while (RightBeg <= RightEnd) tmp[tmpPos++] = a[RightBeg++];

	//copy to the a
	for (int i = 0; i < numElement; i++, RightEnd--) {
		a[RightEnd] = tmp[RightEnd];
	}
}
void MSort(ElementType a[], ElementType tmp[], size_t left, size_t right)
{
	
	if (left < right) {
		size_t center = left + (right - left) / 2;
		MSort(a, tmp, left, center);
		MSort(a, tmp, center + 1, right);
		Merge(a, tmp, left, center + 1, right);
	}
}
void Merge_sort(ElementType a[], size_t size)
{
	ElementType* tmp = new ElementType[size];
	if (tmp != nullptr) {   // if new an array failed.
		MSort(a, tmp, 0, size - 1);
		delete[] tmp;
	}
	else
		throw std::runtime_error("No space for tmp array!");
}
void Sort(ElementType a[], size_t size)	// The outer function
{
	Merge_sort(a, size);
}
int main(){
	ElementType a[10] = { 5,6,2,3,9,4,10,8,7,1 };
	try {
		Sort(a, 10);
	}
	catch (const std::runtime_error& error)  //catch the throw error
	{
		std::cout << error.what();
		return -1;
	}
	for (size_t i = 0; i < 10; i++) {
		std::cout << a[i] << " ";
	}
	return 0;
}
