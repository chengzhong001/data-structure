#include <vector>

int sum(std::vector<int> arr, int l){
    if(l == arr.size())
        return 0;
    return arr[l] + sum(arr, l+1);
}

int sum(std::vector<int> arr){
    return sum(arr, 0);
}