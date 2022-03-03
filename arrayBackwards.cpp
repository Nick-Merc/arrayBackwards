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

    /* Input */
    cout << "Input the number of elements to store in the array: ";
    cin >> numElements;
    cout << endl;

    cout << "Input 10 integers:" << endl;
    int userNums[numElements];
    for (int i = 0; i < numElements; ++i) {
        cout << "integer - " << i << " : ";
        cin >> userNums[i];
        cout << endl;
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

    //Get duplicates
    for (int i = 0; i < numElements; ++i) {
        currElement = userNums[i];
        for (int q = 0; q < numElements; ++q) {
            if (currElement == userNums[q]) {
                dupElements += 1;
            }
        }
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
