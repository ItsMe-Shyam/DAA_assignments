#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int count = 0;
    for (int i = low; i < high; i+=2) {
        if (arr[i] >= arr[high]) count++;
    }

    swap(arr[high], arr[low + count]);
    int pivot = (low + count)*2;

    int left = low, right = high;

    while (left < pivot && right > pivot) {
        while (left < pivot && arr[left] >= arr[pivot]) left+=2;
        while (right > pivot && arr[right] <= arr[pivot]) right-=2;
        if (left < pivot && right > pivot) {
            swap(arr[left], arr[right]);
        }
    }
    return pivot;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low >= high) return;
    int pivot = partition(arr, low, high);
    quickSort(arr, low, pivot - 2);
    quickSort(arr, pivot + 2, high);
}

int main() {
    vector<int> arr = {1,2,3,4,5,6,7};

    vector<int> even_arr;
    vector<int> even_ind;
    for(int i = 0; i<arr.size(); i++) {
        if(!(i&1)) {
            even_ind.push_back(i);
            even_arr.push_back(arr[i]);
        }
    }

    cout << "Original Array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    quickSort(arr, 0, arr.size() - 1);

    cout << "Sorted Array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}
