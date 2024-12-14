#include <iostream>
#include <cstring>
#include <stack>
#include <cmath>
#include <vector>

std::vector<int> twoSum(std::vector<int> &nums, int target)
{
    int length = nums.size();
    std::vector<int> result;
    for (int i = 0; i < length; i++)
        for (int j = i + 1; j < length; j++)
            if (nums[i] + nums[j] == target)
                return result = {i, j};
    return result;
}

int main()
{
    std::vector<int> nums = {-3,4,3,90};
    int target = 0;
    std::vector<int> answer = twoSum(nums, target);
    std::cout << "answer: " << answer[0] << ", " << answer[1] << std::endl;
    return 0;
}