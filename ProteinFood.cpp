#include "ProteinFood.h"

ProteinFood::ProteinFood(double caloriesPer100g, double weight, double proteinsPer100g)
        : Food(caloriesPer100g, weight), proteinsPer100g(proteinsPer100g) {}

double ProteinFood::calculateProteins() {
    return (proteinsPer100g / 100.0) * weight; // Общие белки
}