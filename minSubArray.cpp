#include <iostream>
#include <vector>
#include <climits>

int minSubArray(const std::vector<int>& arr, int sum) {
    int start = 0;
    int end = 0;
    int total = 0;
    int minLength = arr.size() + 1; // 確保第一次判斷 (minLength > currentLength) 時能夠進入

    // start 會遞增，所以沒超出範圍就繼續迴圈
    while (start < arr.size()) {
        // 如果 total 值還沒大於等於（小於）給定值 sum，且 end 沒到最後一格，end 指針就繼續往前
        if (total < sum && end < arr.size()) { 
            total += arr[end]; // total 加上 arr[end] 所在值，直到 total 大於等於給定值 sum
            end++;
        } else if (total >= sum) { // 如果 total 大於等於目標值 sum
            // 算出目前長度（如 2 - 0，但這時其實 total 值為 index 0 + 1 的總和，因為前面判斷是先加完後移動 end 指針，表示 currentLength 長度正確）
            int currentLength = end - start; 

            // 如果目前 minLength 比迭代後實際 currentLength 還要大，表示還可以縮小
            if (minLength > currentLength) { 
                minLength = currentLength;
            }
            total -= arr[start]; // total 減去 arr[start] 目前值
            start++; // start 指針往後移動繼續檢查有無其他長度組合
        } else if (end >= arr.size()) { // 如果 end 指針指向數組之外的位置，跳出迴圈（如果少了 =，下次迭代再 end++ 會超出範圍）
            break;
        }
    }

    if (minLength == INT_MAX) { // 如果 minLength 跟原本一樣，表示都沒找到
        return 0;
    }

    return minLength;
}

int main() {
    std::vector<int> arr = {8, 1, 6, 15, 3, 16, 5, 7, 14, 30, 12};
    std::cout << minSubArray(arr, 1100) << std::endl; // 12

    return 0;
}