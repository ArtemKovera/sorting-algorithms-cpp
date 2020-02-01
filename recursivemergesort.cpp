// implementation of algorithm for recursive merging sorting in C++

#include <iostream>


//function for merging two sorted sub-arrays
//this function takes array consisting of two sorted sub-arrays, starting index, last index of first sub-array, and ending index
void merge(int arr[], int low, int middle, int high)
{
    int i = low;
    int j = middle + 1;
    int k=low;
    
    //memory allocation for auxiliary array
    //(its size must be equal to the size of the array taken as a parameter)
    int* arr2 = new int [high + 1];

    while( i<=middle && j<=high )
    {
        if(arr[i] < arr[j])
        {
            arr2[k]=arr[i];
            k++;
            i++;
        }
        else
        {
            arr2[k]=arr[j];
            k++;
            j++;
        } 
    }

    for(; i<=middle; i++, k++)
    {
        arr2[k]=arr[i];
    }
    

    for(; j<=high; j++, k++)
    {
        arr2[k]=arr[j];
    }
    
    // copying elements from auxiliary array to the first array
    for(i=low; i<=high; i++)
    {
        arr[i]=arr2[i];
    }
    
    //final memory dealocation for auxilary array
    delete [] arr2;   
}

//recursive function for merge sort
void mergeSort(int arr[], int low, int high)
{
    int middle;

    if(low < high)
    {
        middle = (low + high)/2;
        mergeSort(arr, low, middle);
        mergeSort(arr, middle+1, high);
        merge(arr, low, middle, high); 
    }
}


int main ()
{
    int array [10] {12, 23, 14, 67, 15, 82, 77, 92, 54, 88};

    
    mergeSort(array, 0, 9);

    for (int i = 0; i < 10; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;


    return 0;
}