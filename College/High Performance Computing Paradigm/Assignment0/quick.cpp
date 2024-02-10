#include <bits/stdc++.h>
using namespace std;

int partition(int arr[],int low,int high)
{

int pivot=arr[high];
int i=(low-1);

for(int j=low;j<=high;j++)
{
	if(arr[j]<pivot)
	{	i++; swap(arr[i],arr[j]); }
}
swap(arr[i+1],arr[high]);
return (i+1);
}
			
void quickSort(int arr[],int low,int high)
{
if(low<high)
{
	int pi=partition(arr,low,high);
	quickSort(arr,low,pi-1);
	quickSort(arr,pi+1,high);
}
}

void printArray(int A[], int size)
{
    for (auto i = 0; i < size; i++)
        cout << A[i] << " ";
    cout<<endl;
}		

int main() {
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    auto arr_size = sizeof(arr) / sizeof(arr[0]);

    cout << "Given array is "<<endl;
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    cout << "Sorted array is "<<endl;
    printArray(arr, arr_size);
    return 0;
}