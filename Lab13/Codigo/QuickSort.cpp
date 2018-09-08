#include "QuickSort.h"
#include <vector>
#include <iostream>
using namespace std;

QuickSort::QuickSort(){
        index=0;
}

void QuickSort::quickSort(vector<int> q,int left,int right){
        int i = left, j = right;
        int tmp;
        int pivot = q.at((left + right) / 2);
        while (i <= j) {
                while (q.at(i) < pivot)i++;
                        while (q.at(j) > pivot)j--;
                        if (i <= j) {
                                tmp = q.at(i);
                                q.at(i) = q.at(j);
                                q.at(j) = tmp;
                                i++;
                                j--;
                        }
        }
        if (left < j)quickSort(q, left, j);
        if (i < right)quickSort(q, i, right);
}


