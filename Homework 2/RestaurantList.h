//
// Created by Sankalp Pandey on 2/8/23.
//
#ifndef RESTAURANTLIST_H_
#define RESTAURANTLIST_H_
#include <iostream>
#include <string>
#include "RestaurantNode.h"

class RestaurantList{
private:
    RestaurantNode *head;

public:
    // Default and Parameterized Constructors
    RestaurantList();

    // Copy constructor
    RestaurantList(const RestaurantList &r);

    // Destructor
    ~RestaurantList();

    // Adds a meal
    void addMeal(string restaurantName, float restaurantRating, string mealName, string mealType, float price);

    // Finds the meal with the highest price
    RestaurantNode* highestPrice();

    // Changes the price of a given meal
    bool changePrice(const string& name, float price);

    // Print
    void print() const;
};
#endif
