#include<iostream>
using namespace std;
void heapify(int arr[], int i, int size)
{
	int left, right, largest, temp;
	left = 2 * i;
	right = (2 * i + 1);
	if ((left <= size) && arr[left]>arr[i])           //���l���I���S��������I�j
		largest = left;                               
	else
		largest = i;                                  //�Y�L�A���`�I���̤j
	if ((right <= size) && (arr[right]>arr[largest])) //�P�W
		largest = right;
	if (largest != i)                               //�p�G�l���I������I�j���ܴN���洫
	{
		temp = arr[i];
		arr[i] = arr[largest];
		arr[largest] = temp;
		heapify(arr, largest, size);
	}
}
void max_heap(int arr[], int size)
{
	for (int i = size / 2; i >= 1; i--)                            
		heapify(arr, i, size);
}
void heapsort(int arr[], int size)
{
	int temp;
	max_heap(arr, size);
	cout << "The max-heap numbers:";
	for (int i = 1; i <= size; i++){
		cout << arr[i] << " ";
	}
	for (int i = size; i >= 2; i--) 
	{
		temp = arr[i];                             //��̤j�ȧ�X�� �ѤU�hheapify
		arr[i] = arr[1];
		arr[1] = temp;
		heapify(arr, 1, i - 1);
	}
}
int main()
{
	int size;
	int arr[1000];
	cout << "Please enter the size of array:";
	cin >> size;
	cout << "Please input a sequence of unsorted numbers:";
	for (int i = 1; i <= size; i++){
		cin >> arr[i];
	}
	heapsort(arr, size);
	cout << endl << "Sorted numbers:";
	for (int i = size; i >= 1; i--){
		cout << arr[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}