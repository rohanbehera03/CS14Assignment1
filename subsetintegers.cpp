/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   subsetintegers.cpp
 * Author: rohanbehera
 *
 * Created on October 14, 2020, 8:54 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

/*
 * 
 */
void productSubset(int array[], int length, int s) {
    cout << "Subset integers with a product of " << s << endl;
    for (int i = 0; i < length; i++) {
        for (int j = i+1; j < length; j++) {
            if (array[i]*array[j] == s) {
                cout << "Subset: " << array[i] << ", " << array[j] << endl;
            }
        }
    }
}

int main(int argc, char** argv) {
    int arr[] = {7, 10, 13, 16, 19, 22, 25, 28, 31};
    int numcountArray = 9;
    int productNum = 112;
    productSubset(arr, numcountArray, productNum);
    return 0;
}

