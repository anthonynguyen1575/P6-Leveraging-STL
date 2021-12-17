#include <iostream>
#include <random>
#include <algorithm>
#include <string>
#include "Utility.h"
#include "Car.h"

std::vector<double> statistics(std::vector<Car> cars);

int main() {
    auto cars = randomCars();
    std::cout << "Cars: " << cars << "\n";

    std::vector<double> values = statistics(cars);

    std::cout << "The average price is: $" << values[0] << "\n";

    std::cout << "The range is: $" << values[1] << "\n";
}

std::vector<double> statistics(std::vector<Car> cars) {
    std::vector<double> values;
    double total;
    double averagePrice;
    double range;
    double min;
    double max;

    for(Car& it : cars) {
        total += it.price();
    }

    averagePrice = total / cars.size();

    min = cars[0].price();
    for(Car& it : cars) {
        if(it.price() < min) {
            min = it.price();
        }
        if(it.price() > max) {
            max = it.price();
        }
    }

    range = max - min;

    values.push_back(averagePrice);
    values.push_back(range);

    return values;
}
