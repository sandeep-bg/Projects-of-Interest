////
////  main.cpp
////  Algorithmic Toolbox CPP
////
////  Created by SANDEEP GANGADHARAIAH on 11/04/20.
////  Copyright © 2020 SANDEEP GANGADHARAIAH. All rights reserved.
////
//
//#include <iostream>
//#include <vector>
//#include <cstdlib>
//
//using std::cout;
//using std::cin;
//using std::endl;
//
////Problem Description
////Task. The goal in this problem is to find the minimum number of coins needed to change the input value
////(an integer) into coins with denominations 1, 5, and 10.
////Input Format. The input consists of a single integer 𝑚.
////Constraints. 1 ≤ 𝑚 ≤ 103.
////Output Format. Output the minimum number of coins with denominations 1, 5, 10 that changes 𝑚.
////Sample 1.
////Input:
////2
////Output:
////2
////2 = 1 + 1.
////Sample 2.
////Input:
////28 - 28/10 = 2-> 8/5 =1 -> 3/1 = 3
////Output:
////6
////28 = 10 + 10 + 5 + 1 + 1 + 1.
//int coin_box[3] = {10,5,1};
//int moneyChange(int amount)
//{
//    int change = amount; //5
//    int num_change = 0;
//    for (int i = 0; i<3; i++) {
//        if(coin_box[i] <= change)
//        {
//            num_change+= change/coin_box[i];
//            change = change%coin_box[i];
//        }
//    }
//    return num_change;
//}
//
//int main(int argc, const char * argv[]) {
//    // insert code here...
//    int amount=0;
//    int num_change=0;
//    cin >> amount;
//    num_change = moneyChange(amount);
//    printf("%d\n", num_change);
//
//    return 0;
//}
//
//
