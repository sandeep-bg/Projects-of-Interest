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
////Maximum Pairwise Product
//long int Max_Pairwise_Product(const std::vector <long int>& num);
//
////Maximum Pairwise Product
//long int Max_Pairwise_Product_Fast(const std::vector <long int>& num);
//
//int main_temp(int argc, const char * argv[]) {
//    // insert code here...
//    while (true) {
//        unsigned long size;
//        long int result1 = 0;
//        long int result2 = 0;
//        //Read Size
//        //std::cin >> size;
//        //Increasing this number -> 2x100000 increases the execution time
//        size = rand() % 100 + 2;
//        std::vector <long int> numbers(size);
//
//        //std::cout << size;
//        //numbers = new long int(sizeof(long int)*size);
//        unsigned long i=0;
//        while (i<size) {
//            //store input numbers
//            //std::cin >> numbers[i];
//            numbers.push_back(rand()%200000 + 2);
//            //std::cout << numbers[i] << " ";
//            i++;
//        }
//
//        result1 = Max_Pairwise_Product(numbers);
//        result2 = Max_Pairwise_Product_Fast(numbers);
//
//        if (result1 != result2) {
//            cout << "Wrong Answer!";
//            break;
//        }
//        else
//        {
//            cout << "OK";
//        }
//        std::cout << std::endl;
//    }
//
//    return 0;
//}
//
////Maximum Pairwise Product
//long int Max_Pairwise_Product(const std::vector <long int>& num)
//{
//    long int result=0;
//    unsigned long size = num.size();
//    for (int i=0; i<size; i++) { //For each element in the array
//        for (int j=(i+1)%size; j!=i; j=j%size) {//multiply with every other element cycliccally
//             if(result < (num[i]*num[j]))
//                 result = num[i]*num[j];
//            //std::cout << result << " ";
//            j++;
//        }
//    }
//    std::cout << result << " ";
//    return result;
//}
//
////Maximum Pairwise Product Fast Algo
//long int Max_Pairwise_Product_Fast(const std::vector <long int>& num)
//{
//    int index1 = 0;
//    int index2 = 0;
//    unsigned long size = num.size();
//    if (size == 2) {
//        index1 = 0;
//        index2 =1;
//        std::cout << (num[index1]*num[index2]);
//        return (num[index1]*num[index2]);
//    }
//
//    for (int i=1; i<size; i++) { //For each element in the arraycycliccally
//             if(num[index1] < num[i])
//                 index1 = i;
//    }
//
//    for (int i=1; i<size; i++) { //For each element in the arraycycliccally
//             if((num[index2] < num[i]) && (i != index1))
//                 index2 = i;
//    }
//    std::cout << (num[index1]*num[index2]) << endl;
//    return (num[index1]*num[index2]);
//}
