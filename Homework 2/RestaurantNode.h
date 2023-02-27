//
// Created by Sankalp Pandey on 2/7/23.
//
#ifndef RESTAURANTNODE_H
#define RESTAURANTNODE_H
#include <iostream>
#include <string>
using namespace std;

class RestaurantNode {
private:
    string restaurantName;
    float restaurantRating;
    string mealName;
    string mealType;
    float mealPrice;
    RestaurantNode *next;

public:
    // Default and Parameterized Constructors
    RestaurantNode();
    RestaurantNode(string restaurantName, float restaurantRating, string mealName, string mealType, float mealPrice);

    // Copy constructor
    RestaurantNode(const RestaurantNode &r);

    // Destructor
    ~RestaurantNode();

    // Getters
    string getRestaurantName() const;
    float getRestaurantRating() const;
    string getMealName() const;
    string getMealType() const;
    float getMealPrice() const;
    RestaurantNode* getNext() const;

    // Setters
    void setRestaurantName(string name);
    void setRestaurantRating(float rating);
    void setMealName(string name);
    void setMealType(string type);
    void setMealPrice(float price);
    void setNext(RestaurantNode *n);

    // Print
    void print() const;
};
#endif
