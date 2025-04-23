#include<bits/stdc++.h>
using namespace std;

void insertionSort(int *arr, int size){
    int comparision = 0;
    int key;
    int j;
    for (int i = 1; i < size; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && key < arr[j])
        {
            comparision++;
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    cout<< "Total Comparisons : " << comparision << endl;

    for(int i = 0; i<size; i++) {
        cout<<arr[i]<<" ";
    }cout<<endl;
}

int main() {

    int *arr = new int[5];

    for(int i = 0; i<5; i++) {
        arr[i] = 5-i;
    }
    insertionSort(arr, 5);
}