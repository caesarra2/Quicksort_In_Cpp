#include <iostream>
#include <array>
#include <chrono>

template<std::size_t T>
inline void SwapElement(std::array<int, T>& arr, int a, int b) // Inline fuction to swap an array element with another
{
	int temp = arr.at(a);
	arr.at(a) = arr.at(b);
	arr.at(b) = temp;
}


template<std::size_t T>
inline void ListArray(std::array<int, T> arr) // Inline function to list array elements
{
	for (int i : arr)
	{
		std::cout << i << " ";
	}
}


template<std::size_t T>
int Partition(std::array<int, T>& arr, int start, int end)
{
	int pIndex = start;
	int pVal = arr.at(end);

	for (int i = start; i < end; i++)
	{
		if (arr.at(i) < pVal)
		{
			SwapElement(arr, i, pIndex);
			pIndex++;
		}
	}
	
	SwapElement(arr, pIndex, end);

	return pIndex;
}


template<std::size_t T>
void QuickSort(std::array<int, T>& arr, int start, int end)
{
	if (start >= end)
		return;

	int pIndex = Partition(arr, start, end); // Pivot index

	QuickSort(arr, start, pIndex - 1);
	QuickSort(arr, pIndex + 1, end);
}






int main()
{
	std::array<int, 7> arr{ 9, 1, 6, 23, 4, 8, 91, }; // Array that needs to be sorted.

	std::cout << "Array values before sorting: ";
	ListArray(arr);

	auto start = std::chrono::steady_clock::now();

	QuickSort(arr, 0, arr.size() - 1);

	auto end = std::chrono::steady_clock::now();

	std::cout << "\n\nArray values after sorting: ";
	ListArray(arr);

	std::cout << "\nThe sorting took " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << " microseconds." << std::endl;

	return 0;
}
