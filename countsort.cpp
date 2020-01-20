// counting sorting algorithm

#include <iostream>

//using namespace std;

// function for counting sort (takes array to sort and size of this array as arguments)
void countSort (int arr [], int size)
{

int maxValue = arr[0];
int temp;
int *p = nullptr;
int count = 0;

// determining max value in array to sort
for (int i = 1; i < size; i++)
{
    if (arr[i] > maxValue) maxValue = arr[i];
}
    
// determining size for auxiliary array 
int sizeAuxiliaryArray = maxValue + 1;
    
// auxiliary array initialization
p = new int [sizeAuxiliaryArray];

// filing auxiliary array with zeros
for (int i = 0; i < sizeAuxiliaryArray; i++ ) 
{
    p[i] = 0;
}


// filling appropriate elements in auxiliary array with appropriate values
// and simultaneous filing first array with zeros
for(int i = 0; i < size; i++)
{
    temp = arr[i];
    p[temp]++;
    arr[i] = 0; 
}


// filing first array with sorted sequence  
for (int i = 0; i < sizeAuxiliaryArray; i++ )
{
    
    while(p[i])
    {
       arr[count] = i;
       count++;
       p[i]--;
    }
}

// final memory diallocation for auxiliary array
delete [] p;

}




int main ()
{   
    
    int array [] {3, 2, 4, 10, 8, 9, 12, 4, 11};

    
    countSort(array, 9);
     
    for (int i = 0; i < 9; i++)
    {
        std::cout << array[i] << " ";
    }

    std::cout << std::endl;
    
   
    return 0;
}