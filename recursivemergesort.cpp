//  algorithm for recursive merging sorting (templated version)

#include <iostream>


//function for merging two sorted sub-arrays
//this function takes array consisting of two sorted sub-arrays, starting index, last index of first sub-array, and ending index
template<typename T>
void merge(T arr[], int low, int middle, int high)
{
    int i = low;
    int j = middle + 1;
    int k=low;
    
    //memory allocation for auxiliary array
    //(its size must be equal to the size of the array taken as a parameter)
    T* arr2 = new T [high + 1];

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
template<typename T>
void mergeSort(T arr[], int low, int high)
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

    
    mergeSort<int>(array, 0, 9);

    for (int i = 0; i < 10; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    double array2 [12] {12.3, 43.2, 54.2, 78.1, 7.3, 9.0, 23.1, 7.3, 9.1, 8.12, 90.3, 43.2};

    mergeSort<double>(array2, 0, 11);

     for (int i = 0; i < 12; i++)
    {
        std::cout << array2[i] << " ";
    }
    std::cout << std::endl;   

    return 0;
}