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

using std::cout;
using std::cin;
using std::endl;

//Problem Description
//Task. The goal in this problem is to find the minimum number of coins needed to change the input value
//(an integer) into coins with denominations 1, 5, and 10.
//Input Format. The input consists of a single integer 𝑚.
//Constraints. 1 ≤ 𝑚 ≤ 103.
//Output Format. Output the minimum number of coins with denominations 1, 5, 10 that changes 𝑚.
//Sample 1.
//Input:
//2
//Output:
//2
//2 = 1 + 1.
//Sample 2.
//Input:
//28 - 28/10 = 2-> 8/5 =1 -> 3/1 = 3
//Output:
//6
//28 = 10 + 10 + 5 + 1 + 1 + 1.
int coin_box[3] = {10,5,1};
int DP_coin_box[3] = {1,3,4};
int min_num_coins[1000];
int moneyChange(int amount)
{
    int change = amount; //5
    int num_change = 0;
    for (int i = 0; i<3; i++) {
        if(coin_box[i] <= change)
        {
            num_change+= change/coin_box[i];
            change = change%coin_box[i];
        }
    }
    return num_change;
}

int DPmoneyChange(int money)
{
    int num_coins = 0;
    min_num_coins[0] = 0;
    for(int m = 1; m <= money; m++)
    {
        min_num_coins[m] = 10001;
        for (int i = 0; i < 3; i++)
        {
            if (m >= DP_coin_box[i])
            {
                num_coins = min_num_coins[m - DP_coin_box[i]] + 1;
                if (num_coins < min_num_coins[m])
                {
                    min_num_coins[m] = num_coins;
                }
            }
        }
    }
    return min_num_coins[money];
}

int main_DP(int argc, const char * argv[]) {
    // insert code here...
    int amount=0;
    int num_change=0;
    cin >> amount;
    num_change = DPmoneyChange(amount);
    printf("%d\n", num_change);

    return 0;
}


