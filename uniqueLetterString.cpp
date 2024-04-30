#include <iostream>
#include <string>
#include <unordered_map>
#include <climits>

int uniqueLetterString(const std::string& str) {
    int start = 0;
    int end = 0;
    std::unordered_map<char, int> counter;
    int maxLength = INT_MIN; // 初始化為一個非常小的值，以確保任何有效的長度都會比它大

    while (end < str.length()) {
        // 有找到重複鍵（如果當前字符已經存在於 counter 中），沒有回傳 .end()（!= .end()）表示有找到重複鍵
        if (counter.find(str[end]) != counter.end()) { 
            counter[str[start]]--; // 將 start 指向的記數移除，並往後移動
            start++; // start 往後移動
        } else { // 沒找到重複鍵，繼續
            counter[str[end]] = 1; // 將 end 指向的字元設為 1
            end++; // end 往後移動
            
            // 若現在長度比目前最長還長，就更新
            if (end - start > maxLength) {
                maxLength = end - start;
            }
        }
    }

    // 如果都沒有找到，還維持原本初始的值
    if (maxLength == INT_MIN) {
        return -1;
    }

    return maxLength;
}

int main() {
    std::cout << uniqueLetterString("thisishowwedoit") << std::endl;  // 6

    return 0;
}