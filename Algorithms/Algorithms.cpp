#include "Algorithms.hh" 

int binary_search(int target, std::vector<int> data, int start, int end) {

    if (start > end)
        return -1;

    int middle = start + (end - start) / 2;

    if (data[middle] == target)
        return middle;

    if (target > data[middle])
        return binary_search(target, data, middle+1, end);
    else 
        return binary_search(target, data, start, middle-1);
}


void binary_search_test() {

    std::vector<int> data {3, 5, 9, 22, 23, 45, 50, 51};

    int res =  binary_search(45, data, 0, data.size()-1);

}

