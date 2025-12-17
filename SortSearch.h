// SortSearch.h
#ifndef SORTSEARCH_H
#define SORTSEARCH_H

#include <iostream>
#include <chrono>
#include <iomanip>
using namespace std;
using namespace std::chrono;

struct ComplexityMetrics
{
    string algorithm;
    string timeComplexity;
    string spaceComplexity;
    double executionTime; // in milliseconds
    int comparisons;
    int swaps;

    void display()
    {
        cout << "\n=== Complexity Analysis: " << algorithm << " ===\n";
        cout << "Time Complexity: " << timeComplexity << "\n";
        cout << "Space Complexity: " << spaceComplexity << "\n";
        cout << "Execution Time: " << fixed << setprecision(4) << executionTime << " ms\n";
        cout << "Comparisons: " << comparisons << "\n";
        if (swaps >= 0)
            cout << "Swaps: " << swaps << "\n";
        cout << "==========================\n";
    }
};

class SortSearchUtils
{
private:
    static int compCount;
    static int swapCount;

    // Helper for Merge Sort
    static void merge(int arr[], int l, int m, int r)
    {
        int n1 = m - l + 1;
        int n2 = r - m;
        int *L = new int[n1];
        int *R = new int[n2];

        for (int i = 0; i < n1; i++)
            L[i] = arr[l + i];
        for (int j = 0; j < n2; j++)
            R[j] = arr[m + 1 + j];

        int i = 0, j = 0, k = l;
        while (i < n1 && j < n2)
        {
            compCount++;
            if (L[i] <= R[j])
            {
                arr[k] = L[i];
                i++;
            }
            else
            {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        while (i < n1)
        {
            arr[k] = L[i];
            i++;
            k++;
        }
        while (j < n2)
        {
            arr[k] = R[j];
            j++;
            k++;
        }
        delete[] L;
        delete[] R;
    }

    // Helper for Quick Sort
    static int partition(int arr[], int low, int high)
    {
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j < high; j++)
        {
            compCount++;
            if (arr[j] < pivot)
            {
                i++;
                swap(arr[i], arr[j]);
                swapCount++;
            }
        }
        swap(arr[i + 1], arr[high]);
        swapCount++;
        return i + 1;
    }

    // Helper for Heap Sort
    static void heapify(int arr[], int n, int i)
    {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        compCount++;
        if (left < n && arr[left] > arr[largest])
            largest = left;

        compCount++;
        if (right < n && arr[right] > arr[largest])
            largest = right;

        if (largest != i)
        {
            swap(arr[i], arr[largest]);
            swapCount++;
            heapify(arr, n, largest);
        }
    }

public:
    // 1. Linear Search
    static ComplexityMetrics linearSearch(int arr[], int n, int x)
    {
        compCount = 0;
        auto start = high_resolution_clock::now();

        for (int i = 0; i < n; i++)
        {
            compCount++;
            if (arr[i] == x)
            {
                auto end = high_resolution_clock::now();
                double time = duration<double, milli>(end - start).count();
                ComplexityMetrics m;
                m.algorithm = "Linear Search";
                m.timeComplexity = "O(n) - Best: O(1), Worst: O(n), Avg: O(n)";
                m.spaceComplexity = "O(1)";
                m.executionTime = time;
                m.comparisons = compCount;
                m.swaps = -1;
                cout << "Element found at index: " << i << "\n";
                return m;
            }
        }

        auto end = high_resolution_clock::now();
        double time = duration<double, milli>(end - start).count();
        ComplexityMetrics m;
        m.algorithm = "Linear Search";
        m.timeComplexity = "O(n) - Best: O(1), Worst: O(n), Avg: O(n)";
        m.spaceComplexity = "O(1)";
        m.executionTime = time;
        m.comparisons = compCount;
        m.swaps = -1;
        cout << "Element not found.\n";
        return m;
    }

    // 2. Binary Search
    static ComplexityMetrics binarySearch(int arr[], int l, int r, int x)
    {
        compCount = 0;
        auto start = high_resolution_clock::now();
        int foundIdx = -1;

        while (l <= r)
        {
            compCount++;
            int mid = l + (r - l) / 2;
            compCount++;
            if (arr[mid] == x)
            {
                foundIdx = mid;
                break;
            }
            compCount++;
            if (arr[mid] < x)
                l = mid + 1;
            else
                r = mid - 1;
        }

        auto end = high_resolution_clock::now();
        double time = duration<double, milli>(end - start).count();
        ComplexityMetrics metrics;
        metrics.algorithm = "Binary Search";
        metrics.timeComplexity = "O(log n) - Best: O(1), Worst: O(log n), Avg: O(log n)";
        metrics.spaceComplexity = "O(1)";
        metrics.executionTime = time;
        metrics.comparisons = compCount;
        metrics.swaps = -1;

        if (foundIdx != -1)
            cout << "Element found at index: " << foundIdx << "\n";
        else
            cout << "Element not found.\n";

        return metrics;
    }

    // 3. Bubble Sort
    static ComplexityMetrics bubbleSort(int arr[], int n)
    {
        compCount = swapCount = 0;
        auto start = high_resolution_clock::now();

        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                compCount++;
                if (arr[j] > arr[j + 1])
                {
                    swap(arr[j], arr[j + 1]);
                    swapCount++;
                }
            }
        }

        auto end = high_resolution_clock::now();
        double time = duration<double, milli>(end - start).count();
        ComplexityMetrics m;
        m.algorithm = "Bubble Sort";
        m.timeComplexity = "O(n²) - Best: O(n), Worst: O(n²), Avg: O(n²)";
        m.spaceComplexity = "O(1)";
        m.executionTime = time;
        m.comparisons = compCount;
        m.swaps = swapCount;
        return m;
    }

    // 4. Selection Sort
    static ComplexityMetrics selectionSort(int arr[], int n)
    {
        compCount = swapCount = 0;
        auto start = high_resolution_clock::now();

        for (int i = 0; i < n - 1; i++)
        {
            int minIdx = i;
            for (int j = i + 1; j < n; j++)
            {
                compCount++;
                if (arr[j] < arr[minIdx])
                    minIdx = j;
            }
            if (minIdx != i)
            {
                swap(arr[i], arr[minIdx]);
                swapCount++;
            }
        }

        auto end = high_resolution_clock::now();
        double time = duration<double, milli>(end - start).count();
        ComplexityMetrics m;
        m.algorithm = "Selection Sort";
        m.timeComplexity = "O(n²) - Best: O(n²), Worst: O(n²), Avg: O(n²)";
        m.spaceComplexity = "O(1)";
        m.executionTime = time;
        m.comparisons = compCount;
        m.swaps = swapCount;
        return m;
    }

    // 5. Insertion Sort
    static ComplexityMetrics insertionSort(int arr[], int n)
    {
        compCount = swapCount = 0;
        auto start = high_resolution_clock::now();

        for (int i = 1; i < n; i++)
        {
            int key = arr[i];
            int j = i - 1;
            compCount++;
            while (j >= 0 && arr[j] > key)
            {
                compCount++;
                arr[j + 1] = arr[j];
                swapCount++;
                j--;
            }
            arr[j + 1] = key;
        }

        auto end = high_resolution_clock::now();
        double time = duration<double, milli>(end - start).count();
        ComplexityMetrics m;
        m.algorithm = "Insertion Sort";
        m.timeComplexity = "O(n²) - Best: O(n), Worst: O(n²), Avg: O(n²)";
        m.spaceComplexity = "O(1)";
        m.executionTime = time;
        m.comparisons = compCount;
        m.swaps = swapCount;
        return m;
    }

    // 6. Merge Sort
    static void mergeSortHelper(int arr[], int l, int r)
    {
        if (l < r)
        {
            int m = l + (r - l) / 2;
            mergeSortHelper(arr, l, m);
            mergeSortHelper(arr, m + 1, r);
            merge(arr, l, m, r);
        }
    }

    static ComplexityMetrics mergeSort(int arr[], int n)
    {
        compCount = swapCount = 0;
        auto start = high_resolution_clock::now();
        mergeSortHelper(arr, 0, n - 1);
        auto end = high_resolution_clock::now();
        double time = duration<double, milli>(end - start).count();
        ComplexityMetrics m;
        m.algorithm = "Merge Sort";
        m.timeComplexity = "O(n log n) - Best: O(n log n), Worst: O(n log n), Avg: O(n log n)";
        m.spaceComplexity = "O(n)";
        m.executionTime = time;
        m.comparisons = compCount;
        m.swaps = swapCount;
        return m;
    }

    // 7. Quick Sort
    static void quickSortHelper(int arr[], int low, int high)
    {
        if (low < high)
        {
            int pi = partition(arr, low, high);
            quickSortHelper(arr, low, pi - 1);
            quickSortHelper(arr, pi + 1, high);
        }
    }

    static ComplexityMetrics quickSort(int arr[], int n)
    {
        compCount = swapCount = 0;
        auto start = high_resolution_clock::now();
        quickSortHelper(arr, 0, n - 1);
        auto end = high_resolution_clock::now();
        double time = duration<double, milli>(end - start).count();
        ComplexityMetrics m;
        m.algorithm = "Quick Sort";
        m.timeComplexity = "O(n log n) - Best: O(n log n), Worst: O(n²), Avg: O(n log n)";
        m.spaceComplexity = "O(log n)";
        m.executionTime = time;
        m.comparisons = compCount;
        m.swaps = swapCount;
        return m;
    }

    // 8. Heap Sort
    static ComplexityMetrics heapSort(int arr[], int n)
    {
        compCount = swapCount = 0;
        auto start = high_resolution_clock::now();

        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(arr, n, i);

        for (int i = n - 1; i > 0; i--)
        {
            swap(arr[0], arr[i]);
            swapCount++;
            heapify(arr, i, 0);
        }

        auto end = high_resolution_clock::now();
        double time = duration<double, milli>(end - start).count();
        ComplexityMetrics m;
        m.algorithm = "Heap Sort";
        m.timeComplexity = "O(n log n) - Best: O(n log n), Worst: O(n log n), Avg: O(n log n)";
        m.spaceComplexity = "O(1)";
        m.executionTime = time;
        m.comparisons = compCount;
        m.swaps = swapCount;
        return m;
    }

    static void printArray(int arr[], int n)
    {
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << "\n";
    }
};

int SortSearchUtils::compCount = 0;
int SortSearchUtils::swapCount = 0;

#endif // SORTSEARCH_H