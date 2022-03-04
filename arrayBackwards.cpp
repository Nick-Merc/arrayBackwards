/* 
 * Author: Nicholas Mercadante
 * Assignment Title: Array Backwards
 * Assignment Description:
 *     Program asks user for array size and then has
 *     you input that many values to be stored in an
 *     array. Program then prints array forwards, then
 *     backwards, and then returns the sum, min, max,
 *     and duplicate element count.
 * Due Date: 3/3/2022
 * Date Created: 3/2/2022
 * Date Last Modified: 3/3/2022
 */

/*
 * Data Abstraction:
 *     Int numElements is declared to hold total number of elements.
 *     Int currElement is declared to hold element in each loop
 *     iteration. Int dupElements is initialized to zero to hold
 *     number of duplicates. Ints numSum, numMax, and numMin are
 *     initialized to zero to hold output values. Bool usedNumber
 *     is declared to discern whether a duplicate has been found
 *     or not. Int array userNums is declared to hold user numbers.
 * Input:
 *     Program takes input for array size. Program then takes integers
 *     to fill up each array slot.
 * Process:
 *     Program calculates sum, max, min, and then duplicate elements.
 * Output:
 *     Program outputs array forwards and backwards, and then the sum,
 *     min, max, and duplicate element count.
 * Assumptions:
 *     Assumes user enters integers
 *     Assumes user enters correct number of integers
 */
#include <iostream>

using namespace std;

int main() {
    /* Data Abstraction */
    int numElements;
    int currElement;
    int dupElements = 0;
    int numSum = 0;
    int numMax = 0;
    int numMin = 0;
    bool usedNumber;

    /* Input */
    cout << "Input the number of elements to store in the array: ";
    cin >> numElements;
    cout << numElements << endl;

    cout << "Input 10 integers:" << endl;
    int userNums[numElements];
    for (int i = 0; i < numElements; ++i) {
        cout << "integer - " << i << " : ";
        cin >> userNums[i];
        cout << userNums[i] << endl;
    }

    /* Process */
    //Get sum
    for (int i = 0; i < numElements; ++i) {
        numSum += userNums[i];
    }

    //Get max
    numMax = userNums[0];
    for (int i = 0; i < numElements; ++i) {
        if (userNums[i] > numMax) {
            numMax = userNums[i];
        }
    }

    //Get min
    numMin = userNums[0];
    for (int i = 0; i < numElements; ++i) {
        if (userNums[i] < numMin) {
            numMin = userNums[i];
        }
    }

    //Not finished
    //Get duplicates
    int usedList[numElements];

    for (int i = 0; i < numElements; ++i) { //For each element...
        currElement = userNums[i];
        for (int q = 0; q < numElements; ++q) { //Compare with each element
            if (currElement == userNums[q]) {
                usedNumber = false;
                if (!(i == 0)) {
                    for (int v = 0; v < i; ++v) { //Checks for used number
                        if (currElement == usedList[v]) {
                            usedNumber = true;
                        }
                    }
                }
                if (!(usedNumber)) {
                    dupElements += 1;
                }
            }
        }
        usedList[i] = currElement;
    }
    dupElements -= numElements;

    /* Output */
    cout << "The values stored into the array are :" << endl;
    for (int i = 0; i < numElements; ++i) {
        cout << userNums[i] << " ";
    }
    cout << endl << endl;

    cout << "The values stored into the array in reverse are :" << endl;
    for (int i = (numElements - 1); i >= 0; --i) {
        cout << userNums[i] << " ";
    }
    cout << endl << endl;

    cout << "The sum of all elements of the array is " << numSum << endl;
    cout << "The total number of duplicate elements in the array is "
    << dupElements << endl;
    cout << "The maximum and minimum element in the array are "
    << numMax << " , " << numMin << endl;

    return 0;
}
