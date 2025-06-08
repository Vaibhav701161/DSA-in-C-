/*
given will we an array , it's max size and numbers. we have to how many times those numbers appears in the array 
*/

#include <bits/stdio.h>
#include <iostream>

using namespace std;
int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0 ; i <n ;i++){
        cin >> arr[i];
    }

    // precompute using hashing 
    int hash{10001} = {0};
    for(int i =0; i<n ; i++){
        hash[arr[i]]+= 1;
    }

    // take the queries
    int q;
    cin >> q;
    int number;
    for (int i =0; i<n ; i++){
        cin >> number;
        if (number < 0 || number >= 10001) {
            cout << "Number out of range" << endl;
        } else {
            cout << hash[number] << endl;
        }
    }

}

