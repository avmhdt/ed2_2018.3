#include "headers/libraries.h"

int main()
{
    int *i;
    int j[2] = {55, 60};
    i = &j[0];

    cout << "j[1] = " << *i << endl;
    cout << "i = " << i << endl;

    int *k = i+1;

    cout << "j[2] = " << *i << endl;
    cout << "i = " << i << endl;
    cout << "K-i = " << k-i << endl;
    cout << " k = " << k << endl;
    cout << "k < i? " << bool(k > i) << endl;

    int vec[] = {6,5,1, -37, 9, 6, 7, 1, 4, 3, 159, 354, 456, 123123, 3,2,4};

    for(int i = 0; i < sizeof(vec)/sizeof(int); i++) {
        cout << vec[i] << " ";
    }; cout << endl;

    ///
    //quickSort(vec, &vec[sizeof(vec)/sizeof(int)-1]);
    countingSort(vec, sizeof(vec)/sizeof(int));
    ///

    for(int i = 0; i < sizeof(vec)/sizeof(int); i++) {
        cout << vec[i] << " ";
    }; cout << endl;

    /*
    int v2[] = {6,5,7,2,4,3};
    int *vPtr = new int[6];
    for(int i = 0; i < 6; i++) {
        cin >> *(vPtr+i);
    }

    cout << "*****************" << endl;
    int *vecAux = new int(*vPtr);
    for(int i = 0; i < 6; i++) {
        cout << vPtr[i] << " ";
    }
    */

    int s = 6;
    int *arr = new int[s]();

    printVec(arr, 6);

    return 0;
}
