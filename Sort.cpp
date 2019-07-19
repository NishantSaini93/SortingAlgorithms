#include "Sort.h"


void Sort::EnterAndChoose() {
	std::cout << "Enter the size of array to be sorted:" << std::endl;
	int size{ 0 };
	std::cin >> size;
	int i{ 0 };
	int z{ 0 };
	std::cout << "Input array:" << std::endl;
	while (i < size) {
		std::cin >> z;
		dataTosort.push_back(z);
		i++;
	}
	char number{};
	std::cout << "Enter the number to choose Sorting Algorithm:" << std::endl;
	std::cout << "Enter 1 for Insertion Sort." << std::endl;
	std::cout << "Enter 2 for Bubble Sort." << std::endl;
	std::cout << "Enter 3 for Quick Sort." << std::endl;
	std::cin >> number;
	switch (number) {
	case '1':InsertionSort();
		Display();
		break;
	case '2':BubbleSort();
		Display();
		break;
	case '3':QuickSort(0,dataTosort.size()-1);
		Display();
		break;
	default:
		std::cout << "Enter correct choice." << std::endl;
	}
}

/**
*This function perform Insertion Sort
*Best case complexity:O(n)
*Average case:O(n^2)
*/
void Sort::InsertionSort() {
	//In insertion Sort we compare item(key) with items at left
	//Since there is no item to the left of 1st item so we skipped 0 index
	for (int i{ 1 }; i < dataTosort.size(); i++) {
		//key item
		int key{ dataTosort[i] };
		//Getting left item
		int j{ i - 1 };
		//Checking index and comparing items
		while (j >= 0 && dataTosort[j]>key) {
			dataTosort[j + 1] = dataTosort[j];
			j--;
		}
		//Inserting item in proper position
		dataTosort[j + 1] = key;
	}
}
/**
*This function perform BubbleSort
*Best case complexity:O(n)
*Average case:O(n^2)
*/
void Sort::BubbleSort() {
	//In this we perform n pases
	for (int i{ 0 }; i < dataTosort.size(); i++) {
		//Flag to just check if there is swap in whole phase or not
		bool flagSwap{ false };
		//it checks all adjacent pairs
		for (int j{ 0 }; j < dataTosort.size()-1; j++) {
			if (dataTosort[j] > dataTosort[j + 1]) {
				int temp{ dataTosort[j] };
				dataTosort[j]=dataTosort[j + 1];
				dataTosort[j + 1] = temp;
				flagSwap = true;
			}
		}
		//If there is no swap in whole phase ..it means it is already sorted
		//this make algorithm efficient
		if (flagSwap == false) {
			break;
		}
	}
}
/**
*This function perform QuickSort Using first element as piviot
*@param left First element of current array
*@param right LAst element of current array
*/
void Sort::QuickSort(int left,int right) {
	//Base case when array size is one
	if (right - left <= 0) {
		return;
	}
	int piviot{ dataTosort[left] };
	int i{ left + 1 };
	//i represent current position where piviot need to be 
	//j is for comparing
	for (int j{ left + 1 }; j <= right; ++j) {
		//i only increement when there is something lesser then piviot in right of it
		if (dataTosort[j] < piviot) {
			int temp{ dataTosort[i] };
			dataTosort[i] = dataTosort[j];
			dataTosort[j] = temp;
			++i;
		}
	}
	int temp{ dataTosort[left] };
	dataTosort[left] = dataTosort[i - 1];
	dataTosort[i - 1] = temp;
	QuickSort(left, i - 2);
	QuickSort( i, right);
}

/**
*Function to display array
*/
void Sort::Display() {
	std::cout << "Sorted Array" << std::endl;
	std::vector<int>::iterator it;
	for (it = dataTosort.begin(); it != dataTosort.end(); it++) {
		std::cout << *it << " ";
	}
}