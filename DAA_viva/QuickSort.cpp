#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int count = 0;
    for (int i = low; i < high; i++) {
        if (arr[i] <= arr[high]) count++;
    }

    swap(arr[high], arr[low + count]);
    int pivot = low + count;
    int left = low, right = high;

    while (left < pivot && right > pivot) {
        while (left < pivot && arr[left] <= arr[pivot]) left++;
        while (right > pivot && arr[right] > arr[pivot]) right--;
        if (left < pivot && right > pivot) {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }

    return pivot;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low >= high) return;
    int pivot = partition(arr, low, high);
    quickSort(arr, low, pivot - 1);
    quickSort(arr, pivot + 1, high);
}

int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};

    cout << "Original Array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    quickSort(arr, 0, arr.size() - 1);

    cout << "Sorted Array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}
