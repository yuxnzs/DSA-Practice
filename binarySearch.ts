function binarySearch(arr: number[], target: number): number {
  // 兩個指針，分別指向陣列的最小值和最大值
  let min: number = 0;
  let max: number = arr.length - 1;

  // 當 min 小於等於 max 時繼續執行
  // 如果 min 大於 max 代表找不到目標值
  while (min <= max) {
    // 取得中間值
    let middle: number = Math.floor((max + min) / 2);

    // 如果 target 小於目前中間值，將最大值指向中間值的前面一個元素
    if (target < arr[middle]) {
      max = middle - 1;
    }
    // 如果 target 大於目前中間值，將最小值指向中間值的後面一個元素
    else if (target > arr[middle]) {
      min = middle + 1;
    }

    // 如果 target 等於目前中間值，代表找到目標值，回傳中間值的 index
    if (target === arr[middle]) {
      return middle;
    }
  }

  // 沒找到 target，回傳 -1
  return -1;
}

let numbers = [
  9, 12, 15, 18, 19, 20, 22, 25, 26, 26, 33, 37, 38, 41, 47, 47, 50, 55, 57, 60,
  68, 80, 87, 90, 98, 100, 103, 108, 109, 109, 116, 120, 120, 124, 127, 128,
  131, 135, 135, 139, 143, 145, 151, 155, 156, 158, 163, 164, 165, 169, 169,
  173, 174, 176, 177, 178, 181, 182, 182, 183, 184, 189, 192, 195, 200, 201,
  203, 204, 207, 213, 217, 222, 222, 222, 227, 228, 233, 235, 237, 239, 239,
  243, 248, 251, 252, 257, 260, 260, 263, 268, 270, 271, 271, 276, 281, 284,
  285, 295, 297, 298,
];

console.log(binarySearch(numbers, 60)); // 19

// Binary Search 視覺化
// https://www.cs.usfca.edu/~galles/visualization/Search.html
