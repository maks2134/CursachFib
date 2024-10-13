#include "food.h"

Food::Food(double caloriesPer100g, double weight)
        : caloriesPer100g(caloriesPer100g), weight(weight) {}

double Food::calculateCalories() {
    return (caloriesPer100g / 100.0) * weight;
}
