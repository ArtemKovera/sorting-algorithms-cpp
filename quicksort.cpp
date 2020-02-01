//implementation of quick sort in C++
#include<iostream>

//partition function reorders array so that all elements
// with values less than the pivot come before the pivot
// This function takes array, first index of array, and last index of array + 1 as its arguments
int partition (int arr[], int low, int high)
{
    int pivot = arr[low]; //pivot
    int i = low;  
    int j = high;

    do
    {
        do {i++;}  while (arr[i] <= pivot);
        do {j--;}  while (arr[j] > pivot);

        if (i<j) std::swap(arr[i], arr[j]);

    } while (i<j);
    
    std::swap(arr[low], arr[j]);

    return j;
}


//function for quick sort recursively calls the partition function
void quickSort (int arr[], int low, int high)
{
   int j; //partitioning position

   if(low<high)
   {
       j=partition(arr, low, high);
       quickSort(arr, low, j);
       quickSort(arr, j+1, high);
   }

}



int main ()
{
    int array [12] {12, 1, 23, 4, 13, 21, 63, 4, 3, 12, 74, 27};

    quickSort(array, 0, 12);

    for (int i = 0; i < 12; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;


    return 0;
}