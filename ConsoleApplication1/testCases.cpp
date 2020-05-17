#include <iostream>
#include <stdio.h>
#include "sortAlgorithm.h"
#include "dpAlgorithm.h"
#include "TestCases.h"

using namespace std;

void TestCases::runSort() {
	int array[] = { 61, 17, 29, 22, 34, 60, 72, 21, 50, 1, 62 };
	int length = (int) sizeof(array) / sizeof(*array);
	/*********sort functions**********/
	//bubbleSort(array, length);
	//quickSort(array, length);
	//shellSort(array, length);
	/*int *temp = new int[length];
	mergeSort(array, 0, length-1,temp);
	delete[] temp;*/
	selectionSort(array, length);

	// output sorted array
	for (int i = 0; i < length; i++)
		cout << array[i] << ' '; cout << endl;

	float arrayf[] = { 17.5, 19.1, 0.6, 1.9, 10.5, 12.4, 3.8, 19.7,
		1.5, 25.4, 28.6, 4.4, 23.8, 5.4 };
	length = (int) sizeof(arrayf) / sizeof(*arrayf);
	/*********sort functions**********/
	//bubbleSort(arrayf, length);
	//quickSort(arrayf, length);
	//shellSort(arrayf, length);
	/*float *tempf = new float[length];
	mergeSort(arrayf, 0, length - 1, tempf);
	delete[] tempf;*/
	selectionSort(arrayf, length);

	for (int i = 0; i < length; i++)
		cout << arrayf[i] << ' '; cout << endl;

	/********** Binary Search Test ************/
	int result = binarySearch(array, 0, length - 1, 29);
	cout << "Binary Search Result: " << result << endl;
}

void TestCases::runDP() {
	int a[50], n, k, d;
	scanf_s("%d", &n);
	for (int i=0; i < n; i++) {
		scanf_s("%d", a + i);
	}
	scanf_s("%d%d", &k, &d);
	//long long result = recursiveResult(a,n,k,d);
	long long result = dpAlgorithm2(a, n, k, d);
	printf("%lld\n", result);
}