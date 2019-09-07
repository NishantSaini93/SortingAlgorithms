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
	std::cout << "Enter 4 for Selection Sort" << std::endl;
	std::cout << "Enter 5 for Merge Sort" << std::endl;
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
	case '4':SelectionSort();
		Display();
		break;
	case '5':MergeSort(0,dataTosort.size()-1);
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
*@param right Last element of current array
*Worst complexity: n^2
*Average complexity: n*log(n)
*Best complexity: n*log(n)
*We can use use uniform random piviot
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
*This function perform Selection Sort
*Worst complexity: n^2
*Average complexity: n^2
*Best complexity: n^2
*/
void Sort::SelectionSort() {
	//perfom phases in each phase we sort one element of array
	int currentMinimumIndex{};
	int currentMinimum{};
	//outer loop
	for (int i{ 0 }; i < dataTosort.size(); ++i) {
		int flag{};
		currentMinimum = dataTosort[i];
		//inner loop
		for (int j{ i + 1 }; j < dataTosort.size(); ++j) {
			if (currentMinimum > dataTosort[j]) {
				currentMinimum = dataTosort[j];
				currentMinimumIndex = j;
				flag = 1;
			}
		}
		if (flag) {
			int temp{ dataTosort[i] };
			dataTosort[i] = dataTosort[currentMinimumIndex];
			dataTosort[currentMinimumIndex] = temp;
		}
		
	}
}

/**
*This is responsible for sorting and merging of data
*@param start Starting index of data to sort
*@param middle Middle index of data to sort
*@param end Last index of data to sort
*/
void Sort::Merging(int start, int middle, int end) {
	int firstHalf{middle+1};
	int secondHalf{middle+1};
	std::vector<int> vecFirst;
	std::vector<int> vecSecond;
	for (int i = start; i < firstHalf; ++i) {
		vecFirst.push_back(dataTosort[i]);
	}
	vecFirst.push_back(INT_MAX);
	for (int i = secondHalf; i <=end; ++i) {
		vecSecond.push_back(dataTosort[i]);
	}
	vecSecond.push_back(INT_MAX);
	int index1{0};
	int index2{0};
	for (int k = start; k <= end; ++k) {
		if (vecFirst[index1] < vecSecond[index2]) {
			dataTosort[k] = vecFirst[index1];
			++index1;
		}
		else {
			dataTosort[k] = vecSecond[index2];
			++index2;
		}
	}
}

/**
*Merge Sort
*if condition is there for termination
*We are continously dividing data in smaller sizes
*Merging function is sort and merge the divided data
*@param start Starting index of data
*@param end Last index of data
*Worst complexity: n*log(n)
*Average complexity: n*log(n)
*Best complexity: n*log(n)
*/
void Sort::MergeSort(int start,int end) {
	if (start < end) {
		int middle = floor((start+end)/2);
		MergeSort(start,middle);
		MergeSort(middle+1,end);
		Merging(start,middle,end);
	}
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