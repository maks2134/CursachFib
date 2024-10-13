#ifndef UNTITLED1_FOOD_H
#define UNTITLED1_FOOD_H

class Food {
public:
    Food(double caloriesPer100g, double weight);
    double calculateCalories();

protected:
    double caloriesPer100g;
    double weight;
};



#endif //UNTITLED1_FOOD_H
