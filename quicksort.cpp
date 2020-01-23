// templated implementation of quick sort in C++
#include<iostream>

//partition function reorders array so that all elements
// with values less than the pivot come before the pivot
// This function takes as its arguments array, first index of array, and last index of array + 1

template<typename T>
int partition (T arr[], int low, int high)
{
    T pivot = arr[low]; //pivot
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
template<typename T>
void quickSort (T arr[], int low, int high)
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


    double arrayD [11] {1.1, 2.1, 12.8, 23.4, 3.1, 4.5, 5.6, 12.3, 8.3, 7.32, 4.99};

    quickSort(arrayD, 0, 11);

    for (int i = 0; i < 11; i++)
    {
        std::cout << arrayD[i] << " ";
    }
    std::cout << std::endl;    


    return 0;
}