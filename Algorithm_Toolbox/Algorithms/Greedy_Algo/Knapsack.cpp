//
//  main.cpp
//  Algorithmic Toolbox CPP
//
//  Created by SANDEEP GANGADHARAIAH on 11/04/20.
//  Copyright © 2020 SANDEEP GANGADHARAIAH. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstdlib>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

//Problem Description
//Task. The goal of this code problem is to implement an algorithm for the fractional knapsack problem.
//Input Format. The first line of the input contains the number 𝑛 of items and the capacity 𝑊 of a knapsack.
//The next 𝑛 lines define the values and weights of the items. The 𝑖-th line contains integers 𝑣𝑖 and 𝑤𝑖—the
//value and the weight of 𝑖-th item, respectively.
//Constraints. 1 ≤ 𝑛 ≤ 1000, 0 ≤ 𝑊 ≤ 2 * 10^6; 0 ≤ 𝑣𝑖 ≤ 2 * 10^6, 0 < 𝑤𝑖 ≤ 2 * 10^6 for all 1 ≤ 𝑖 ≤ 𝑛. All the
//numbers are integers.
//Output Format. Output the maximal value of fractions of items that fit into the knapsack. The absolute
//value of the difference between the answer of your program and the optimal value should be at most
//10−3. To ensure this, output your answer with at least four digits after the decimal point (otherwise
//your answer, while being computed correctly, can turn out to be wrong because of rounding issues).
//Sample 1.
//Input:
//3 50
//90 30
//100 50
//120 30
//3 50
//120 30
//90 30
//100 50
//Output:
//180.0000
//To achieve the value 180, we take the first item and the third item into the bag.
//Sample 2.
//Input:
//1 10
//500 30
//Output:
//166.6667
//Here, we just take one third of the only available item.

#define min_max(a,b,c) a<b?a=b:a; a>c?a=c:a;
class ks_item
{
public:
    double value;
    double weight;
    double value_perunit;
    bool operator<(const ks_item r_value)
    {
        if(this->value_perunit < r_value.value_perunit)
            return true;
        else
            return false;
    }
};

template <class arrayType>

//Merge sorted array
arrayType* mergeSortedArray(arrayType* arr_1, arrayType* arr_2, int array1_sz, int array2_sz)
{
    int index=0;
    int arr_1_id=0;
    int arr_2_id=0;
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
arrayType* mergeSort(arrayType* array, int size)
{
    int middle = 0;
    arrayType* array_1 = nullptr;
    arrayType* array_2 = nullptr;
    //if size is 1 return array
    if (size == 1) {
    return array;
    }
    //divide size by 2
    middle = (int)size/2;
    //sort the array A from 0-size/2
    array_1 = mergeSort(array, middle);
    //sort the array B from size/2-size
    array_2 = mergeSort(&array[middle], (size-middle));
    //merge both these arrays A&B
    return mergeSortedArray(array_1, array_2, middle, (size-middle));
}


class KnapSack
{
    ks_item* items;
    double capacity;
    int num_items;
    double value;
    
    double calculate_value()
    {
        //ks.rem_cap = capacity
        double remaining_weight = capacity;
        //if items is non-empty
        
        //sort items array from highest to lowest vpu - already done during set value
        sort_itemListHitoLo();
        //for each item in items
        for (int item = num_items-1; item>=0; item--)
        {
            if (remaining_weight >= items[item].weight)
            {
                remaining_weight -= items[item].weight;
                value += items[item].value;
            }
            else
            {
                value += (remaining_weight/items[item].weight)*items[item].value;
                remaining_weight = 0;
                break;
            }
            //printf("%f\n", value);
        }
        //if ks.rem_cap>=item.weight
        //ks.rem_cap-= item.weight
        //ks.value+=item.value
        //else if ks.rem_cap < item.weight
        //ks.value += (ks.rem_cap/item.weight)*item.value
        return value;
    }
    
    unsigned int calculate_value_dp()
    {
        unsigned int value[(int)capacity][num_items];
        unsigned int val;
        //Initialize all value (0,j) = 0
        for (int i = 0; i < num_items; i++) {
            value[0][i] = 0;
        }
        //Initialize all value (w, 0) = 0
        for (int i = 0; i < (int)capacity; i++) {
            value[i][0] = 0;
        }
        
        for (int i = 1; i < num_items; i++) {
            for (int w = 1; w < capacity; w++) {
                value[w][i] = value[w][i-1];
                if(items[i].weight <= w)
                {
                    val = value[w-(int)items[i].weight][i-1];
                    if (value[w][i] < val) {
                        value[w][i] = val;
                    }
                }
            }
        }
        return value[(int)capacity][num_items];
    }
    
    void sort_itemListHitoLo()
    {
        ks_item* temp_ptr;
        temp_ptr = items;
        items = (ks_item*)mergeSort(items, num_items);
        if (temp_ptr != items)
        {
            free(temp_ptr);
        }
        
    }
public:
    KnapSack(int num, double max)
    {
        min_max(num, 1, 1000);
        min_max(max, 0, 2000000);
        capacity = max;
        num_items = num;
        value = 0;
        for (int i = 0; i<num_items; i++)
        {
            items = (ks_item*)malloc(num_items*sizeof(ks_item));
        }
    }
    
    int get_maxItems()
    {
        return num_items;
    }
    
    double get_capacity()
    {
        return capacity;
    }
    
    double get_value()
    {
        if (value == 0)
        {
            //value = calculate_value();
            value = calculate_value_dp();
        }
        return value;
    }
    
    int set_item(double value, double weight, int item_num)
    {
        min_max(value, 0, 2000000);
        min_max(weight, 0, 2000000);
        items[item_num].value = value;
        items[item_num].weight = weight;
        items[item_num].value_perunit = value/weight;
        //Do boundary check. return 0 if fail
        //check item vpu. if higher than 1st element, push front else push back
        return 1;
    }
    
};

int main_temp1(int argc, const char * argv[]) {
    // insert code here...
    int num_items = 0;
    int knapsack_max = 0;
    double value;
    double weight, result;
    cin >> knapsack_max;
    cin >> num_items;
    KnapSack ks_obj(num_items, knapsack_max);
    int index = 0;
    while (index!=ks_obj.get_maxItems())
    {
        cin >> value;
        cin >> weight;
        ks_obj.set_item(value, weight, index);
        index++;
    }
    result = ks_obj.get_value();
    //printf("%f\n", result);
    cout << std::fixed << std::setprecision(4);
    cout << result<<endl;
    
    return 0;
}


