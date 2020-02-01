//algorithm for insertion sort implemented in c++

#include<iostream>


// function for insertion sort (takes array and the size of the array as its arguments)
void insertionSort (int arr [], const int SIZE)
{
    int temp, i, j;
    
    //the for loop iterates over entire array to sort
    for (i = 1; i < SIZE; i++)
    {    
        j = i - 1;
        temp = arr[i];

        //inside the while loop, elements are shifted to the right
        while(j > -1 && arr[j] > temp)
        {  
            arr[j + 1] = arr[j]; 
            j--;
        }

        //element is inserted at the correct position    
        arr[j+1] = temp;
    }

     
}


int main ()
{
    const int SIZE = 10;
    
    int array [SIZE] {12, 10, 11, 13, 14, 16, 21, 4, 2, 11};

    insertionSort(array, SIZE);
    
    std::cout << "sorted array: ";
    for (int i = 0; i < SIZE; i++)
    {
        std::cout << array[i] << " ";
    }

    std::cout << std::endl;
    

    return 0;


}