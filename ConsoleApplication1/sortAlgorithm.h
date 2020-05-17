#pragma once

/**********************************/
/*** Sort Algorithm Declaration ***/
/**********************************/
template<typename T> void bubbleSort(T array[], int length);
template<typename T> void quickSort(T array[], int length);
template<typename T> void shellSort(T array[], int length);
template<typename T> void mergeSort(T array[], int start, int end, T temp[]);
template<typename T> void selectionSort(T array[], int length);
template<typename T> int binarySearch(T array[], int start, int end, T key);

/*************************************/
/*** Sort Algorithm Implementation ***/
/*************************************/

/************* Bubble Sort ***********/
template<typename T>
void bubbleSort(T array[], int length) {
	T temp;

	if (array == nullptr || length <= 0)
		return;
	for (int i = 0; i < length - 1; i++)
		for (int j = 0; j < length - 1 - i; j++)
			if (array[j] > array[j + 1]) {
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
}

/************* Quick Sort ***********/
template<typename T>
void quickSort(T array[], int length){
	int i = 0;
	int j = length - 1;
	T temp = array[i];

	if (array == nullptr || length <= 0)
		return;
	while (i < j) {
		while (array[j] >= temp && i < j) 
			j--;
		array[i] = array[j];
		while (array[i] <= temp && i < j) 
			i++;
		array[j] = array[i];
	}
	array[i] = temp;
	quickSort(array, i);
	quickSort(array + i + 1, length - 1 - i);
}

/************* Shell Sort ***********/
template<typename T>
void shellSort(T array[], int length) {
	//Marcin Ciura's gap sequence
	int gap = length / 2;
	while (gap >= 1) {
		for (int i = gap; i < length; i++) {
			int j = i;
			T temp = array[i];
			while (j >= gap && temp < array[j - gap]) {
				array[j] = array[j - gap];
				j -= gap;
			}
			array[j] = temp;
		}
		gap /= 2;
	}
}

/************* Merge Sort ***********/
template <typename T>
void merge(T array[], int start, int middle, int end, T temp[]) {
	int left_index = start;
	int right_index = middle+1;
	int temp_index = start;

	while (left_index <= middle && right_index <= end) {
		if (array[left_index] < array[right_index])
			temp[temp_index++] = array[left_index++];
		else
			temp[temp_index++] = array[right_index++];
	}
	while (left_index <= middle)
		temp[temp_index++] = array[left_index++];
	while (right_index <= end)
		temp[temp_index++] = array[right_index++];

	for (int i = start; i <= end; i++) {
		array[i] = temp[i];
	}
}

template <typename T>
void mergeSort(T array[], int start, int end, T temp[]) {
    if (start >= end || array == nullptr)
		return;
	int middle = ((end + start) >> 1);
	mergeSort(array, start, middle, temp);
	mergeSort(array, middle+1, end, temp);
	merge(array, start, middle, end, temp);
}

/************* Selection Sort *************/
template<typename T> 
void selectionSort(T array[], int length) {
	int minIndex;
	T temp;

	if (array == nullptr || length <= 0)
		return;
	for (int i = 0; i < length-1; i++) {
		minIndex = i;
		for (int j = i + 1; j < length; j++)
			if (array[j] < array[minIndex]) minIndex = j;
		if (minIndex != i) {
			temp = array[minIndex];
			array[minIndex] = array[i];
			array[i] = temp;
		}
	}
}

/************* Binary Search *************/
template<typename T> 
int binarySearch(T array[], int start, int end, T key) {
	int left, right, mid;
	left = start;
	right = end;
	while (left <= right) {
		mid = (left + right) >> 1;
		if (key == array[mid]) return mid;
		else if (key < array[mid]) right = mid - 1;
		else if (key > array[mid]) left = mid + 1;
	}
	return -1;
}
