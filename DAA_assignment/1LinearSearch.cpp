#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

int linearSearch(int data[], int length, int target, int &comparisonCount) {
    for (int i = 0; i < length; i++) {
        comparisonCount++;
        if (data[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    ofstream csvFile("search_comparisons.csv");
    csvFile << "Data Size,Best Case,Worst Case,Average Case\n"; 

    srand(time(0)); 

    for (int size = 5; size <= 100; size += 5) {

        int array[size];
        for (int i = 0; i < size; i++) {
            array[i] = rand() % size + 1; 
        }

        int testKeys[size];
        for (int j = 0; j < size; j++) {
            testKeys[j] = rand() % size + 1;
        }

        int bestCase = INT_MAX;
        int worstCase = INT_MIN;
        int totalComparisons = 0;

        for (int k = 0; k < size; k++) {
            int comparisons = 0;
            linearSearch(array, size, testKeys[k], comparisons);

            bestCase = min(bestCase, comparisons);
            worstCase = max(worstCase, comparisons);
            totalComparisons += comparisons;
        }

        int averageCase = totalComparisons / size;
        
        cout << "Data Size: " << size << endl;
        cout << "Best Case Comparisons: " << bestCase << endl;
        cout << "Worst Case Comparisons: " << worstCase << endl;
        cout << "Average Case Comparisons: " << averageCase << endl;
        cout << "--------------------------" << endl;

        csvFile << size << "," << bestCase << "," << worstCase << "," << averageCase << "\n";
    }

    csvFile.close(); 
    cout << "Results have been exported to 'search_comparisons.csv'." << endl;

    return 0;
}
