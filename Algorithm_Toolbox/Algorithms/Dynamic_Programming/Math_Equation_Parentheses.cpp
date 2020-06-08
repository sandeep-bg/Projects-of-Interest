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
#include <algorithm>
#include <string>
#include <stdlib.h>
#include <cstring>

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

//#define min_max(a,b,c) a<b?a=b:a; a>c?a=c:a;
//#define DEBUG_LOG

long int **min;
long int **max;
char* math_equation;

void MinAndMax(int i, int j)
{
    long int min_val = 1000000000;
    long int max_val = -1000000000;
    long int a=0,b=0,c=0,d=0;
    char op;
    if(i==j)
        return;
    for (int k = i; k <= j-1; k++)
    {
        op = (char)math_equation[2*k+1];
        //toascii(op);
        switch (op)
        {
            case '+':
                a = max[i][k] + max[k+1][j];
                b = max[i][k] + min[k+1][j];
                c = min[i][k] + max[k+1][j];
                d = min[i][k] + min[k+1][j];
                break;
                
                case '-':
                a = max[i][k] - max[k+1][j];
                b = max[i][k] - min[k+1][j];
                c = min[i][k] - max[k+1][j];
                d = min[i][k] - min[k+1][j];
                break;
                
                case 'x':
                a = max[i][k] * max[k+1][j];
                b = max[i][k] * min[k+1][j];
                c = min[i][k] * max[k+1][j];
                d = min[i][k] * min[k+1][j];
                break;
                
                case '*':
                a = max[i][k] * max[k+1][j];
                b = max[i][k] * min[k+1][j];
                c = min[i][k] * max[k+1][j];
                d = min[i][k] * min[k+1][j];
                break;
                
            default:
                break; //5−8+7×4−8+9
        }
        min_val = std::min({min_val, a, b, c, d});
        max_val = std::max({max_val, a, b, c, d});
    }
    min[i][j] = min_val;
    max[i][j] = max_val;
}
long int Parentheses(void)
{
//    mbstate_t mbs;
//    mbrlen(NULL, 0, &mbs);
    int s_l = (int)strlen(math_equation);
    //int s_l = sizeof(math_equation);
    int n = s_l/2;
    if(s_l%2)
        n++;
    min = (long int**)malloc(n*sizeof(long int*));
    for (int i = 0; i < n; i++) {
    min[i] = (long int*)malloc(n*sizeof(long int));
    }
    
    max = (long int**)malloc(n*sizeof(long int*));
    for (int i = 0; i < n; i++) {
    max[i] = (long int*)malloc(n*sizeof(long int));
    }
    
    for (int i=0; i<n; i++) {
    
        min[i][i] = max[i][i] = (long int)strtol(&math_equation[2*i], NULL, 10);

        //cout << max[i][i];
    }
    int j = 0;
    for (int s = 0; s < n; s++) {
        for (int i=0; i < n-s; i++) {
            j = i + s;
            MinAndMax(i,j);
        }
    }
#ifdef DEBUG_LOG
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << min[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << max[i][j] << " ";
        }
        cout << endl;
    }
#endif
    return max[0][n-1];
}

int main_math_parenthese() {
    // insert code here...
    
    long int max_value = 0;
    math_equation = (char*)malloc(29*sizeof(char));
    cin >> math_equation;
    //cout << math_equation;
    max_value = Parentheses();
    cout << max_value;
 
    cout <<endl;
return 0;
}







