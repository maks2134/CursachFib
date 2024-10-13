#ifndef UNTITLED1_PROTEINFOOD_H
#define UNTITLED1_PROTEINFOOD_H
#include "food.h"

class ProteinFood : public Food {
public:
    ProteinFood(double caloriesPer100g, double weight, double proteinsPer100g);
    double calculateProteins();

private:
    double proteinsPer100g;
};


#endif //UNTITLED1_PROTEINFOOD_H
