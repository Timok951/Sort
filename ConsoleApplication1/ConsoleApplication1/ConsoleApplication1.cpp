#include <thread>
#include <iostream>
#include <chrono>
#include <functional>

class MergeSort {
public:void Merge(int nums [], int low, int mid, int high) {
		int leftSize = mid - low + 1; 
		int rightSize = high - mid;

		int* right = new int[rightSize];
		int* left = new int[leftSize];

		for (int i = 0; i < leftSize; i++) {
			left[i] = nums[low + i];
		}

		for (int o = 0; o < rightSize; o++) {
			right[o] = nums[mid + 1 + o];
		}
		int i = 0; 
		int o = 0; 
		int k = low;
		while (i < leftSize && o < rightSize) {
			if (left[i] <= right[o]) {
				nums[k] = left[i];
				i++;
			}
			else {
				nums[k] = right[o];
				o++;
			}
			k++;
		}
		while (i < leftSize) {
			nums[k] = left[i];
			i++;
			k++;
		}

		while (o < rightSize) {
			nums[k] = right[o];
			o++;
			k++;
		}

	}

	void Sort(int nums[], int low, int high) {
		if (low < high) {
			int mid = (low + high) / 2;

			Sort(nums, low, mid);
			Sort(nums, mid + 1, high);
			
			Merge(nums, low, mid, high);
		}
	}
};



int main()
{
	int numbers[10];

	std::cout << "Enter 10 integers\n";
	for (int i = 0; i < 10; i++) {
		std::cin >> numbers[i];
	}

	MergeSort mergeSort;

	std::thread sortingThread([&mergeSort, &numbers]() {
		mergeSort.Sort(numbers, 0, 9);
		});

	sortingThread.join();

	for (int i = 0; i < 10; i++) {
		std::cout << numbers[i] << " ";
	}
	std::cout << std::endl;

	return 0;
}

