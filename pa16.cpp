/// @file pa16.cpp
/// @author Sujin Lee
/// @date 5/5/2022
/// @note I pledge my word of honor that I have complied with the
/// CSN Academic Integrity Policy while completing this assignment.
/// @brief client file to create unique lists
/// @note 40hr
/// 2022-05-04: Sujin created
/// 2022-05-05: Sujin modified to template ver

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <limits>
#include <iomanip>
#include <string>
#include <chrono>
#include <iterator>
#include <cstddef>

using namespace std;
using namespace std::chrono;

struct Origin {
    std::vector<int> temp1;  // to keep original
    std::vector<int> temp2;  // to keep original
    std::vector<int> temp3;  // to keep original
    std::vector<int> temp4;  // to keep original
    std::vector<int> temp5;  // to keep original
};
/// -------------------------------------------------------------------------
/// Function Prototypes
/// -------------------------------------------------------------------------
template <class T>
bool linearSearch(std::vector<T> vecList, T item);
template <class T>
bool binarySearch(std::vector<T> vecList, T item);
template <class T>
void bubbleSort(std::vector<T>& vecList);
template <class T>
void selectionSort(std::vector<T>& vecList);
template <class T>
void insertionSort(std::vector<T>& vecList);
template <class T>
std::vector<T> merge(std::vector<T> left, std::vector<T> right);
template <class T>
std::vector<T> mergeSort(std::vector<T> m);
template <class T>
void mergeSortfunc(std::vector<T>& vecList);
template <class T>
void quickSort(std::vector<T>& vecList, int left, int right);
template <class T>
int partition(std::vector<T>& vecList, int left, int right);
template <class T>
double timer1(std::vector<T> vecList, T item, bool func(std::vector<T>, T));
template <class T>
double timer2(std::vector<T>& vecList, void func(std::vector<T>&));
template <class T>
double timer3(std::vector<T>& vecList, int first, int last,
              void func(std::vector<T>&, int, int));
template <class T>
double timer4(typename std::vector<T>::iterator first,
              typename std::vector<T>::iterator last,
              void func(typename std::vector<T>::iterator,
              typename std::vector<T>::iterator));
template <class T>
void reset(std::vector<T>& vecList1, std::vector<T>& vecList2,
           std::vector<T>& vecList3, std::vector<T>& vecList4,
           std::vector<T>& vecList5, Origin box);
/// -----------------------------------------------------------------------
/// Main entry-point for this application
///
/// @returns Exit-code for the process - 0 for success, else an error code.
/// -----------------------------------------------------------------------
int main() {
    const int MAX = std::numeric_limits<int>::max();
    std::vector<int> array1(10000);
    std::vector<int> array2(20000);
    std::vector<int> array3(40000);
    std::vector<int> array4(80000);
    std::vector<int> array5(160000);
    Origin box;

//    std::random_device rd;  //Will be used to obtain a seed for the random number engine
//    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
//    std::uniform_int_distribution<> distrib(std::numeric_limits<int>::min(),
//                                            std::numeric_limits<int>::max());

    // modern way to generate random number???
    std::generate(array1.begin(), array1.end(), rand);
    std::generate(array2.begin(), array2.end(), rand);
    std::generate(array3.begin(), array3.end(), rand);
    std::generate(array4.begin(), array4.end(), rand);
    std::generate(array5.begin(), array5.end(), rand);
    // process & output phase------------------------------------------------
    box.temp1 = array1;
    box.temp2 = array2;
    box.temp3 = array3;
    box.temp4 = array4;
    box.temp5 = array5;
    // header----------------------------------------------------------------
    cout << fixed << showpoint << setprecision(5);
    cout << std::string(14, ' ')
         << right << setw(13)<< array1.size() << setw(13)
         << array2.size() << setw(13)<< array3.size() << setw(13)
         << array4.size() << setw(13)<< array5.size() << endl;
    cout << std::string(79, '-') << endl;;
    // body------------------------------------------------------------------
    cout << left << setw(14) << "Linear Search" << right << setw(13)
         << timer1(array1, MAX, &linearSearch) << std::flush << right
         << setw(13) << timer1(array2, MAX, linearSearch) << std::flush
         << setw(13) << timer1(array3, MAX, linearSearch) << std::flush
         << setw(13) << timer1(array4, MAX, linearSearch) << std::flush
         << setw(13) << timer1(array5, MAX, linearSearch) << std::flush
         << endl;

    bubbleSort(array1);
    bubbleSort(array2);
    bubbleSort(array3);
    bubbleSort(array4);
    bubbleSort(array5);

    cout << left << setw(14) << "Binary Search" << right << setw(13)
         << timer1(array1, MAX, binarySearch) << std::flush << right
         << setw(13) << timer1(array2, MAX, binarySearch) << std::flush
         << setw(13) << timer1(array3, MAX, binarySearch) << std::flush
         << setw(13) << timer1(array4, MAX, binarySearch) << std::flush
         << setw(13) << timer1(array5, MAX, binarySearch) << std::flush
         << endl;
    // -----------------------------------------------------------------------
    reset(array1, array2, array3, array4, array5, box);
    cout << left << setw(14) << "Bubble Sort" << right << setw(13)
         << timer2(array1, bubbleSort) << std::flush << right
         << setw(13) << timer2(array2, bubbleSort) << std::flush
         << setw(13) << timer2(array3, bubbleSort) << std::flush
         << setw(13) << timer2(array4, bubbleSort) << std::flush
         << setw(13) << timer2(array5, bubbleSort) << std::flush << endl;

    reset(array1, array2, array3, array4, array5, box);
    cout << left << setw(14) << "Selection Sort" << right << setw(13)
         << timer2(array1, selectionSort) << std::flush << right
         << setw(13) << timer2(array2, selectionSort) << std::flush
         << setw(13) << timer2(array3, selectionSort) << std::flush
         << setw(13) << timer2(array4, selectionSort) << std::flush
         << setw(13) << timer2(array5, selectionSort) << std::flush << endl;

    reset(array1, array2, array3, array4, array5, box);
    cout << left << setw(14) << "Insertion Sort" << right << setw(13)
         << timer2(array1, insertionSort) << std::flush << right
         << setw(13) << timer2(array2, insertionSort) << std::flush
         << setw(13) << timer2(array3, insertionSort) << std::flush
         << setw(13) << timer2(array4, insertionSort) << std::flush
         << setw(13) << timer2(array5, insertionSort) << std::flush << endl;
    // ----------------------------------------------------------------------
    reset(array1, array2, array3, array4, array5, box);
    cout << left << setw(14) << "Merge Sort" << right << setw(13)
         << timer2(array1, mergeSortfunc) << std::flush << right
         << setw(13) << timer2(array2, mergeSortfunc) << std::flush
         << setw(13) << timer2(array3, mergeSortfunc) << std::flush
         << setw(13) << timer2(array4, mergeSortfunc) << std::flush
         << setw(13) << timer2(array5, mergeSortfunc) << std::flush
         << endl;

    reset(array1, array2, array3, array4, array5, box);
    cout << left << setw(14) << "Quick Sort" << right << setw(13)
         << timer3(array1, 0, array1.size()-1, quickSort) << std::flush << right
         << setw(13) << timer3(array2, 0, array2.size()-1, quickSort) << std::flush
         << setw(13) << timer3(array3, 0, array3.size()-1, quickSort) << std::flush
         << setw(13) << timer3(array4, 0, array4.size()-1, quickSort) << std::flush
         << setw(13) << timer3(array5, 0, array5.size()-1, quickSort) << std::flush
         << endl;

    reset(array1, array2, array3, array4, array5, box);
    cout << left << setw(14) << "std::sort" << right << setw(13)
         << timer4<int>(array1.begin(), array1.end(), std::sort) << std::flush << right
         << setw(13) << timer4<int>(array2.begin(), array2.end(), std::sort) << std::flush
         << setw(13) << timer4<int>(array3.begin(), array3.end(), std::sort) << std::flush
         << setw(13) << timer4<int>(array4.begin(), array4.end(), std::sort) << std::flush
         << setw(13) << timer4<int>(array5.begin(), array5.end(), std::sort) << std::flush
         << endl;

    cout << "\nTimes reported in seconds." << endl;


    return 0;
}
/// -------------------------------------------------------------------------
/// Function Implementations
/// -------------------------------------------------------------------------
template <class T>
bool linearSearch(std::vector<T> vecList, T item) {
    bool flag = false;

    auto it = vecList.begin();
    while (!flag && it < vecList.end()) {
        if (*it == item) {
            flag = true;
        }
        it++;
    }
    return flag ? true : false;
}
/// -------------------------------------------------------------------------
template <class T>
bool binarySearch(std::vector<T> vecList, T item) {
    size_t len = vecList.size();
    size_t first = 0;
    size_t last = len -1;
    size_t mid = 0;
    bool flag = false;

    while (first <= last && !flag) {
        mid = (first + last) / 2;
        if (vecList.at(mid) == item) {
            flag = true;
        } else if (vecList.at(mid) > item) {
            last = mid - 1;
        } else {
            first = mid + 1;
        }
    }
    return flag ? true : false;
}
/// -------------------------------------------------------------------------
template <class T>
void bubbleSort(std::vector<T>& vecList) {
    size_t size = vecList.size();

    for (size_t i = 1; i < size; i++) {
        for (size_t j = 0; j < size - i; j++) {
            if (vecList.at(j) > vecList.at(j+1)) {
                std::swap(vecList.at(j), vecList.at(j+1));
            }
        }
    }
}
/// -------------------------------------------------------------------------
template <class T>
void selectionSort(std::vector<T>& vecList) {
    size_t i;
    size_t mini;
    size_t j;
    size_t len = vecList.size();
    T temp;
    for (i = 0; i < len - 1; i++) {
        mini = i;
        for (j = i + 1; j < len; j++) {
            if (vecList[j] < vecList[mini])
                mini = j;
        }
        temp = vecList[mini];
        vecList[mini] = vecList[i];
        vecList[i] = temp;
    }
}
/// -------------------------------------------------------------------------
template <class T>
void insertionSort(std::vector<T>& vecList) {
    size_t i;
    size_t j;
    size_t len = vecList.size();
    T temp;
    for (i = 1; i < len; i++)
        if (vecList[i] < vecList[i - 1]) {
            temp = vecList[i];
            j = i;
            do {
                vecList[j] = vecList[j - 1];
                j--;
            } while (j > 0 && vecList[j - 1] > temp);
            vecList[j] = temp;
        }
}
/// -------------------------------------------------------------------------
// ref: https://www.youtube.com/watch?v=RZK6KVpaT3I
// ref: https://www.geeksforgeeks.org/merge-sort/?ref=leftbar-rightbar
// ref: https://www.bogotobogo.com/Algorithms/mergesort.php
// ref: https://www.programiz.com/dsa/merge-sort
template <class T>
std::vector<T> merge(std::vector<T> left, std::vector<T> right) {
    vector<int> result;
    while (static_cast<int>(left.size()) > 0 || static_cast<int>(right.size()) > 0) {
        if (static_cast<int>(left.size()) > 0 && static_cast<int>(right.size()) > 0) {
            if (static_cast<int>(left.front()) <= static_cast<int>(right.front())) {
                result.push_back(static_cast<int>(left.front()));
                left.erase(left.begin());
            } else {
                result.push_back(static_cast<int>(right.front()));
                right.erase(right.begin());
            }
        } else if (static_cast<int>(left.size()) > 0) {
            for (int i = 0; i < static_cast<int>(left.size()); i++) {
                result.push_back(left[i]);
            }
            break;
        } else if (static_cast<int>(right.size()) > 0) {
            for (int i = 0; i < static_cast<int>(right.size()); i++) {
                result.push_back(right[i]);
            }
            break;
        }
   }
   return result;
}
/// -------------------------------------------------------------------------
template <class T>
std::vector<T> mergeSort(std::vector<T> vecList) {
    if (vecList.size() <= 1) {
        return vecList;
    }
    vector<int> left;
    vector<int> right;
    vector<int> result;
    int middle = (static_cast<int>(vecList.size()) + 1) / 2;

    for (int i = 0; i < middle; i++) {
        left.push_back(vecList[i]);
    }

    for (int i = middle; i < static_cast<int>(vecList.size()); i++) {
        right.push_back(vecList[i]);
    }

    left = mergeSort(left);
    right = mergeSort(right);
    result = merge(left, right);

    return result;
}
/// -------------------------------------------------------------------------
template <class T>
void mergeSortfunc(std::vector<T>& vecList) {
    vecList = mergeSort(vecList);
}
/// -------------------------------------------------------------------------
// ref: https://en.wikipedia.org/wiki/Quicksort
// ref: https://www.bogotobogo.com/Algorithms/quicksort.php
template <class T>
void quickSort(std::vector<T>& vecList, int left, int right) {
    if (left >= right) {
        return;
    }
    int pivot = partition(vecList, left, right);
    quickSort(vecList, left, pivot - 1);
    quickSort(vecList, pivot + 1, right);
}
/// -------------------------------------------------------------------------
template <class T>
int partition(std::vector<T>& vecList, int left, int right) {
    T pivot = vecList[right];
    int i = left - 1;
    int j = right;
    for(;;) {
        while(vecList[--j] > pivot);
        while(vecList[++i] < pivot);
        if(i >= j) {
            break;
        }
        std::exchange(vecList[i], vecList[j]);
    }
    std::exchange(vecList[right], vecList[i]);
    return i;
}
/// -------------------------------------------------------------------------
// <Pass a function as a parameter>
// ref: https://www.geeksforgeeks.org/passing-a-function-as-a-parameter-in-cpp/
// ref: https://stackoverflow.com/questions/9410/how-do-you-pass-a-function-as-a-parameter-in-c
template <class T>
double timer1(std::vector<T> vecList, T item, bool func(std::vector<T>, T))  {
    auto start = high_resolution_clock::now();
    func(vecList, item);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    return duration.count() / 1000000.0;
}
/// -------------------------------------------------------------------------
template <class T>
double timer2(std::vector<T>& vecList, void func(std::vector<T>&))  {
    auto start = high_resolution_clock::now();
    func(vecList);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    return duration.count() / 1000000.0;
}
/// -------------------------------------------------------------------------
template <class T>
double timer3(std::vector<T>& vecList, int first, int last,
              void func(std::vector<T>&, int, int))  {
    auto start = high_resolution_clock::now();
    func(vecList, first, last);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    return duration.count() / 1000000.0;
}
/// -------------------------------------------------------------------------
template <class T>
double timer4(typename std::vector<T>::iterator first,
              typename std::vector<T>::iterator last,
              void func(typename std::vector<T>::iterator,
              typename std::vector<T>::iterator))  {
    auto start = high_resolution_clock::now();
    func(first, last);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    return duration.count() / 1000000.0;
}
/// -------------------------------------------------------------------------
template <class T>
void reset(std::vector<T>& vecList1, std::vector<T>& vecList2,
           std::vector<T>& vecList3, std::vector<T>& vecList4,
           std::vector<T>& vecList5, Origin box) {
     vecList1 = box.temp1;
     vecList2 = box.temp2;
     vecList3 = box.temp3;
     vecList4 = box.temp4;
     vecList5 = box.temp5;
}
