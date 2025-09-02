// Find if there are two numbers in a sorted array that sum to a target

#include <iostream>

bool numSumExists(const std::vector<int>& arr, const int& target) {
    // Handle edge cases
    if (arr.size() < 2) {
        return false;
    }
    // Array is sorted
    // two pointers at each extreme while they dont cross each other
    int left = 0;
    int right = arr.size() - 1;

    while (left < right) {
        // get sum and compare with target
        int sum = arr[left] + arr[right];
        // if sum greater decrement right, else if lesser inc left, else return true
        if (sum > target) {
            right--;
        } else if (sum < target) {
            left++;
        } else {
            return true;
        }
    }
    return false;
}

int main() {
    // std::vector<int> arr = {1,2,3,6,7,9};
    std::vector<int> arr = {};
    int target = 1;
    std::cout << numSumExists(arr, target);
}
