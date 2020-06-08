#include <iostream>
#include <vector>
#include <cstdlib>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
/*
Task. The goal in this code problem is to check whether an input sequence contains a majority element.
Input Format. The first line contains an integer 𝑛, the next one contains a sequence of 𝑛 non-negative
integers 𝑎0, 𝑎1, . . . , 𝑎𝑛−1.
Constraints. 1 ≤ 𝑛 ≤ 10^5; 0 ≤ 𝑎𝑖 ≤ 10^9 for all 0 ≤ 𝑖 < 𝑛.
Output Format. Output 1 if the sequence contains an element that appears strictly more than 𝑛/2 times,
and 0 otherwise.
Sample 1.
Input:
5
2 3 9 2 2
Output:
1
2 is the majority element.
Sample 2.
Input:
4
1 2 3 4
Output:
0
There is no majority element in this sequence.
*/
#define min_max(a,b,c) a<b?a=b:a; a>c?a=c:a;

template <class arrayType>
//Merge sorted array
arrayType* mergeSortedArray(arrayType* arr_1, arrayType* arr_2, unsigned long array1_sz, unsigned long array2_sz)
{
    unsigned long index=0;
    unsigned long arr_1_id=0;
    unsigned long arr_2_id=0;
    arrayType* mergeArray = nullptr;
    mergeArray = (arrayType*)malloc(sizeof(arrayType)*(array1_sz+array2_sz));
    //compare each element of the array
    //printf("\n");
    while((arr_1_id < array1_sz) && (arr_2_id < array2_sz))
    {
        //1st push the smallest to result array then the largest
        if(arr_1[arr_1_id] < arr_2[arr_2_id])
        {
            mergeArray[index] = arr_1[arr_1_id];
            //printf("%d ", mergeArray[index]);
            index++;
            arr_1_id++;
        }
        else
        {
            mergeArray[index] = arr_2[arr_2_id];
            //printf("%d ", mergeArray[index]);
            index++;
            arr_2_id++;
        }
    }
    while(arr_1_id != array1_sz)
    {
        mergeArray[index] = arr_1[arr_1_id];
        //printf("%d ", mergeArray[index]);
        index++;
        arr_1_id++;
    }
    while (arr_2_id != array2_sz)
    {
        mergeArray[index] = arr_2[arr_2_id];
        //printf("%d ", mergeArray[index]);
        arr_2_id++;
        index++;
    }
    return mergeArray;
}

template <class arrayType>
//Merge sort array
arrayType* mergeSort(arrayType* array, unsigned long size)
{
    unsigned long middle = 0;
    arrayType* array_1 = nullptr;
    arrayType* array_2 = nullptr;
    //if size is 1 return array
    if (size == 1) {
    return array;
    }
    //divide size by 2
    middle = (unsigned long)size/2;
    //sort the array A from 0-size/2
    array_1 = mergeSort(array, middle);
    //sort the array B from size/2-size
    array_2 = mergeSort(&array[middle], (size-middle));
    //merge both these arrays A&B
    return mergeSortedArray(array_1, array_2, middle, (size-middle));
}

int check_majority(unsigned long* array, unsigned long n)
{
    unsigned long majority = 1;
    for(unsigned long index = 1; index < n; index++)
      {
        //check for same elements
          if (array[index] == array[index-1])
          {
              majority++;
          }
          else
          {
              if(majority > n/2)
              {
                  return 1;
              }
              majority = 1;
          }
      }
    if(majority > n/2)
        return 1;
    else
        return 0;
}

int main_temp(int argc, const char * argv[])
{
    unsigned long n = 0;
    int result=0;
  //Read size of array
  cin >> n;
  unsigned long *array;
  unsigned long index = 0;
    array = (unsigned long*)malloc(sizeof(unsigned long)*n);
  //Read Array elements
  while(index != n)
    {
      cin >> array[index];
      index++;
    }
    
    array = (unsigned long*)mergeSort(array, n);
    
    result = check_majority(array, n);

    cout << result << endl;
  //
  return 0;
}
