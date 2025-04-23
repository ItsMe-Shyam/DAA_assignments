#include <bits/stdc++.h>
using namespace std;

int getMax(const vector<int>& arr) {
    return *max_element(arr.begin(), arr.end());
}

void countingSort(vector<int>& arr, int exp) {
    int n = arr.size();
    vector<int> output(n);
    int count[10] = {0};

    // Store count of occurrences in count[]
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Change count[i] so that it contains the actual position
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // Copy the output array to arr[]
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

// Radix Sort function
void radixSort(vector<int>& arr) {

    int maxi = getMax(arr);
    for(int exp = 1; maxi/exp > 0; exp *= 10) {
        countingSort(arr, exp);
    }
    
}

int main() {
    vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};

    cout << "Original Array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    radixSort(arr);

    cout << "Sorted Array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}
