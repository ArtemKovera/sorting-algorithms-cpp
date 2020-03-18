//selection sort algorithm with C++
#include<iostream>


//this function takes array to sort and the size of this array as the parameters
void selectionSort(int array[], const int SIZE)
{
    int i = 0;
    int minValue;
    bool flag;
    int temp, temp2;
    
    //this loop iterates over entire array
    while (i<=SIZE)
    {   
        flag = false;
        minValue = array[i];

        //this nested loop checks if there is any value in the part of the array
        //which is less than the value in the position array[i]
        for (int j = i; j < SIZE; j++)
        {
            if(minValue > array[j])
            {
                minValue = array[j];
                temp = j;
                flag = true;
            }
        }
        
        //swaping the values inside the array
        if(flag)
        { 
            temp2 = array[i];
            array[i] =  array[temp];
            array[temp] = temp2;
        }
        
        i++;
    }
}

int main ()
{
    int const SIZE = 14;
    int arr[SIZE] = {99, 12, 32, 42, 4, 56, 2, 90, 67, 49, 5, 13, 88, 1};

    selectionSort(arr, SIZE);


    for(int e: arr)
    {
        std::cout << e << std::endl;
    }
    
    return 0;
}