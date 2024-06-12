#include <iostream>
#include <vector>

void bubbleSort(std::vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (nums[j] > nums[j + 1]) { // sort in ascending order
                // Swap nums[j] and nums[j + 1]
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
    }
}

std::pair<int, int> maxProduct(const std::vector<int>& numbers) {
    // Check if the array has fewer than two elements
    if (numbers.size() < 2) {
        std::cout << "Error: Array must contain at least two elements" << std::endl;
        return  {-1,-1}; 
    } 

    std::vector<int> sortedNumbers = numbers;  // Create a copy of the input array
    bubbleSort(sortedNumbers);  // Sort the array

    // Calculate the product of the two largest numbers (last two elements)
    int product1 = sortedNumbers[sortedNumbers.size() - 1] * sortedNumbers[sortedNumbers.size() - 2];

    // Calculate the product of the two smallest numbers (first two elements)
    int product2 = sortedNumbers[0] * sortedNumbers[1];

    // Return the maximum of the two products
    return {product1, product2}; 
}

int main() {
     // Initialize a vector of integers
    std::vector<int> nums = {1, 20, 3, 4, 5, -10, -20, 100, 2, 20};

    auto result = maxProduct(nums);

    if (result.first != -1 && result.second != -1) {
        std::cout << "The maximum product of two integers in the array is: " << result.first << std::endl;
        std::cout << "The minimum product of two integers in the array is: " << result.second << std::endl;
    }

    return 0; 
}