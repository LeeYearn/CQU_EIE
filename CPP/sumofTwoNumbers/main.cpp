#include <iostream>
#include <cstring>
#include <stack>
#include <cmath>
#include <vector>
#include <unordered_map>

std::vector<int> twoSumEnum(std::vector<int> &nums, int target)
{
    int length = nums.size();
    for (int i = 0; i < length; i++)
        for (int j = i + 1; j < length; j++)
            if (nums[i] + nums[j] == target)
                return {i, j};
    return {};
}

std::vector<int> twoSumHash(std::vector<int> &nums, int target)
{
    int length = nums.size();
    std::unordered_map<int, int> hashtable;
    for (int i = 0; i < length; ++i)
    {
        auto it = hashtable.find(target - nums[i]);
        if (it != hashtable.end())
            return {it->second, i};
        hashtable[nums[i]] = i;
    }
    return {};
}

int main()
{
    std::vector<int> nums = {-3, 4, 3, 90};
    int target = 0;
    // std::vector<int> answer = twoSumEnum(nums, target);
    std::vector<int> answer = twoSumHash(nums, target);
    std::cout << "answer: " << answer[0] << ", " << answer[1] << std::endl;
    return 0;
}