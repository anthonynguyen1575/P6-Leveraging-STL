#include <iostream>
#include <random>
#include <algorithm>
#include <string>
#include "Utility.h"
#include "Car.h"

bool anyPrime(const std::vector<int>& values);

int main() {
    auto integers = randomIntegers();
    std::cout << "Integers: " << integers << "\n";
    std::cout << "Are there any primes? " << (anyPrime(integers) ? "yes" : "no") << "\n";
}

bool isPrime(int number){
    bool prime = true;

    for (int i = 2; i <= number / 2; ++i) {
        if (number % i == 0) {
            prime = false;
            break;
        }
    }
    return prime;
}

bool anyPrime(const std::vector<int>& values) {
    auto result = false;

    for(int number : values) {
        if(isPrime(number)) {
            result = true;
        }
    }

    return result;
}
