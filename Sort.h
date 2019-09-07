#ifndef _Sort_INCLUDED
#define _Sort_INCLUDED
#include<iostream>
#include<vector>
#include<string>

/**
*This class implement famous sorting algorihtms
*/
class Sort {
private:
	/**
	*Countainer to store data
	*/
	std::vector<int> dataTosort;
public:
	/**
	*Function to input array and choose algorithm for sorting
	*/
	void EnterAndChoose();
	/**
	*Function to perform Insertion Sort
	*/
	void InsertionSort();
	void BubbleSort();
	void QuickSort(int left,int right);
	void MergeSort(int start,int emd);
	void Merging(int start, int middle, int end);
	void SelectionSort();
	void Display();
};
#endif

