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
//#define DEBUG_LOG
struct ks_item
{
    int weight;
};

class KnapSack
{
    ks_item* items;
    int capacity;
    int num_items;
    //int value[10001][301];
    int **value;
    //vector<vector<int> > value(10, vector<int>(10));
    //int
    
    int calculate_value_dp()
    {
        //int value[10001][301];
        int val;
        //Initialize all value (0,j) = 0
        for (int w = 0; w <= capacity; w++)
        {
            //Initialize all value (w, 0) = 0
            value[0][w] = 0;
        }
        
        for (int i = 0; i <= num_items; i++)
        {
            value[i][0] = 0;
        }
        
        
        for (int i = 1; i <= num_items; i++)
        {
            for (int w = 1; w <= capacity; w++)
            {
                value[i][w] = value[i-1][w];
#ifdef DEBUG_LOG
                cout << items[i-1].weight << "-";
#endif
                if(items[i-1].weight <= w)
                {
                    val = value[i-1][w - items[i-1].weight] + items[i-1].weight;
                    if (value[i][w] < val) {
                        value[i][w] = val;
                    }
                }
#ifdef DEBUG_LOG
                cout << value[i][w] << " ";
#endif
            }
#ifdef DEBUG_LOG
            cout << endl;
#endif
        }
        return value[num_items][capacity];
    }
    
public:
    KnapSack(int num, int max)
    {
        min_max(num, 1, 300);
        min_max(max, 1, 10000);
        capacity = max;
        num_items = num;
        value = (int**)malloc((num_items+1)*sizeof(int*));
        for (int i = 0; i <= num_items; i++) {
            value[i] = (int*)malloc((capacity+1)*sizeof(int));
        }
        //*value = (int*)malloc((capacity+1)*sizeof(int));
        for (int i = 0; i<num_items; i++)
        {
            items = (ks_item*)malloc(num_items*sizeof(ks_item));
        }
    }
    
    int get_maxItems()
    {
        return num_items;
    }
    
    int get_capacity()
    {
        return capacity;
    }
    
    int get_value()
    {
        int value;
        //if (value == 0)
        {
            //value = calculate_value();
            value = calculate_value_dp();
        }
        return value;
    }
    
    int set_item(int weight, int item_num)
    {
        min_max(weight, 0, 100000);
        items[item_num].weight = weight;
        return 1;
    }
    
};

int main_non_rep_kp() {
    // insert code here...
    int n = 0;
    int W = 0;
    int weight, result;
    cin >> W;
    cin >> n;
    KnapSack ks_obj(n, W);
    int index = 0;

    while (index!=ks_obj.get_maxItems())
    {
        cin >> weight;
        ks_obj.set_item(weight, index);
        index++;
    }
    result = ks_obj.get_value();
 
    cout << result <<endl;
return 0;
}


