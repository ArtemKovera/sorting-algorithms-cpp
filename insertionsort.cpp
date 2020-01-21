//algorithm for insertion sort

#include<iostream>

template<typename T>
// templated function for insertion sort (takes array and the size of the array as its arguments)
void insertionSort (T arr [], const int SIZE)
{
  
    T temp;
    int i, j;
    
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

    insertionSort<int>(array, SIZE);
    
    std::cout << "sorted int array: ";
    for (int i = 0; i < SIZE; i++)
    {
        std::cout << array[i] << " ";
    }

    std::cout << std::endl;
    std::cout << "////////////////" << "\n";
   
    const int SIZE_2 = 15;

    
    double array_2 [SIZE_2] {2.1, 2.34, 3.1, 6.0, 4.1, 34, 4.4, 8.1, 56.2, 5.12, 7.89, 7.93, 45.2, 57.6, 8.3};

    insertionSort<double>(array_2, SIZE_2);
    
    std::cout << "sorted double array: ";
    for (int i = 0; i < SIZE_2; i++)
    {
        std::cout  << array_2[i] << " ";
    }

    std::cout << std::endl;

    return 0;


}