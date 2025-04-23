#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int l, int mid, int r) {
    int left = l;
    int right = mid + 1;
    vector<int> temp;

    while (left <= mid && right <= r) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left++]);
        } else {
            temp.push_back(arr[right++]);
        }
    }

    while (left <= mid) temp.push_back(arr[left++]);
    while (right <= r) temp.push_back(arr[right++]);

    for (int i = l; i <= r; i++) {
        arr[i] = temp[i - l];
    }
}

void mergeSort(vector<int>& arr, int l, int r) {
    if (l >= r) return;

    int mid = (l + r) / 2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);
    merge(arr, l, mid, r);
}

int main() {
    vector<int> arr = {10, 5, 8, 2, 7, 3, 6};

    cout << "Original Array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    mergeSort(arr, 0, arr.size() - 1);

    cout << "Sorted Array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}
