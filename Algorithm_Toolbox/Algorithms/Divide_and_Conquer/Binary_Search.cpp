#include <iostream>
#include <vector>
#include <cstdlib>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
/*
Task. The goal in this code problem is to implement the binary search algorithm.
Input Format. The first line of the input contains an integer 𝑛 and a sequence 𝑎0 < 𝑎1 < . . . < 𝑎𝑛−1
of 𝑛 pairwise distinct positive integers in increasing order. The next line contains an integer 𝑘 and 𝑘
positive integers 𝑏0, 𝑏1, . . . , 𝑏𝑘−1.
Constraints. 1 ≤ 𝑘 ≤ 105; 1 ≤ 𝑛 ≤ 3 · 104; 1 ≤ 𝑎𝑖 ≤ 109 for all 0 ≤ 𝑖 < 𝑛; 1 ≤ 𝑏𝑗 ≤ 109 for all 0 ≤ 𝑗 < 𝑘;
Output Format. For all 𝑖 from 0 to 𝑘 − 1, output an index 0 ≤ 𝑗 ≤ 𝑛 − 1 such that 𝑎𝑗 = 𝑏𝑖 or −1 if there
is no such index.
Sample 1.
Input:
5 1 5 8 12 13
5 8 1 23 1 11
Output:
2 0 -1 0 -1
In this sample, we are given an increasing sequence 𝑎0 = 1, 𝑎1 = 5, 𝑎2 = 8, 𝑎3 = 12, 𝑎4 = 13 of length
five and five keys to search: 8, 1, 23, 1, 11. We see that 𝑎2 = 8 and 𝑎0 = 1, but the keys 23 and 11 do
not appear in the sequence 𝑎. For this reason, we output a sequence 2, 0,−1, 0,−1.
 */
#define min_max(a,b,c) a<b?a=b:a; a>c?a=c:a;

int binary_search(int* array, int arr_sz, int value)
{
  if((arr_sz == 1) && (value == array[0]))
    return 0;
  else //element not found
    return -1;
    
   int med_index = arr_sz/2;
  
  if(value == array[med_index-1])
     return med_index-1;
  else if(value > array[med_index-1])
    binary_search(&array[med_index+1], arr_sz-med_index-1, value);
  else
    binary_search(array, arr_sz-med_index, value);
}

int main_temp(int argc, const char * argv[])
{
  int n = 0;
  int search_sz = 0;
  //Read size of array
  cin >> n;
  int array[n];
  int index = 0;
  
  //Read Array elements
  while(index != n)
    {
      cin >> array[index];
      index++;
    }

  //Read size of search elements and the actual elements
  cin >> search_sz;
  int search_elems[search_sz];
  int search_result[search_sz];
  index =0;
  while(index != search_sz)
    {
      cin >> search_elems[index];
      index++;
    }

  //For each element in search_elem
  for(index = 0; index < search_sz; index++)
    {
       //Perform binary search in array
      search_result[index] = binary_search(array, n, search_elems[index]);
      cout << search_result[index];
    }

  //
  return 0;
}
