#include <iostream>
#include <random>
#include <algorithm>
#include <string>
#include "Utility.h"
#include "Car.h"

std::vector<int> bitonicSequence(std::vector<int> list);

int main() {
    auto integers = randomIntegers();
    std::cout << "Initial: " << integers << "\n";

    std::vector<int> list = bitonicSequence(integers);
    
    std::cout << "Bitonic: " << list << "\n";
}

std::vector<int> bitonicSequence(std::vector<int> list) {
    int halfWay = list.size() / 2;
    std::vector<int> firstHalf(halfWay);
    std::vector<int> secondHalf(list.size() - halfWay);

    std::copy(list.begin(), list.begin() + halfWay, firstHalf.begin());
    std::copy(list.begin() + halfWay, list.end(), secondHalf.begin());

    std::sort(firstHalf.begin(), firstHalf.end());
    std::sort(secondHalf.begin(), secondHalf.end(), std::greater<int>());

    firstHalf.insert(firstHalf.end(), secondHalf.begin(), secondHalf.end());

    return firstHalf;
}
