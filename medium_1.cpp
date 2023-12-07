#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> majorityElement(const vector<int>& nums) {
    vector<int> result;
    int candidate1 = 0, candidate2 = 1;
    int count1 = 0, count2 = 0;

    // First pass: Find potential candidates
    for (int num : nums) {
        if (num == candidate1) {
            count1++;
        } else if (num == candidate2) {
            count2++;
        } else if (count1 == 0) {
            candidate1 = num;
            count1 = 1;
        } else if (count2 == 0) {
            candidate2 = num;
            count2 = 1;
        } else {
            count1--;
            count2--;
        }
    }

    // Second pass: Check if candidates occur more than n/3 times
    count1 = count2 = 0;
    for (int num : nums) {
        if (num == candidate1) {
            count1++;
        } else if (num == candidate2) {
            count2++;
        }
    }

    if (count1 > nums.size() / 3) {
        result.push_back(candidate1);
    }
    if (count2 > nums.size() / 3) {
        result.push_back(candidate2);
    }

    return result;
}

int main() {
    vector<int> nums = {3, 2, 3};
    vector<int> result = majorityElement(nums);

    cout << "Output: [";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    return 0;
}
