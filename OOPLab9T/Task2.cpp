#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

// STL3Alg7
void addZeroBeforeDuplicate(std::vector<int>& v) {
    auto it = std::find_first_of(v.begin(), v.begin() + v.size() / 2, v.begin() + v.size() / 2, v.end());
    if (it != v.end()) {
        v.insert(it, 0);
    }
}

// STL3Alg25
void replaceNegativePositive(std::vector<int>& v) {
    std::replace_if(v.begin(), v.begin() + v.size() / 2, [](int num) { return num < 0; }, -1);
    std::replace_if(v.begin() + v.size() / 2, v.end(), [](int num) { return num > 0; }, 1);
}

// STL3Alg38
void printSortedLastThreeElements(std::vector<int>& v) {
    std::partial_sort(v.begin(), v.end(), v.end(), std::greater<int>());
    std::copy(v.end() - 3, v.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
}

// STL3Alg50
void printDescendingOrder(std::vector<int>& v) {
    std::sort(v.begin(), v.end(), std::greater<int>());
    do {
        std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
        std::cout << std::endl;
    } while (std::prev_permutation(v.begin(), v.end(), std::greater<int>()));
}

// STL3Alg55
int sumOfHalfElements(std::vector<int>& v) {
    int sum1 = std::accumulate(v.begin(), v.begin() + v.size() / 2, 0);
    int sum2 = std::accumulate(v.begin() + v.size() / 2, v.end(), 0);
    return sum1 + sum2;
}

void task2() {
    // STL3Alg7
    std::vector<int> v1 = { 1, 2, 3, 4, 3, 5, 6, 7 };
    addZeroBeforeDuplicate(v1);
    for (int num : v1) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // STL3Alg25
    std::vector<int> v2 = { 2, -3, 5, -1, -2, 4 };
    replaceNegativePositive(v2);
    for (int num : v2) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // STL3Alg38
    std::vector<int> v3 = { 3, 2, 4, 6, 9, 1 };
    printSortedLastThreeElements(v3);

    // STL3Alg50
    std::vector<int> v4 = { 3, 1, 4, 2 };
    printDescendingOrder(v4);

    // STL3Alg55
    std::vector<int> v5 = { 1, 2, 3, 4 };
    int sum = sumOfHalfElements(v5);
    std::cout << "Sum: " << sum << std::endl;


}