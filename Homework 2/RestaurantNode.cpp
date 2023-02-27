//
// Created by Sankalp Pandey on 2/7/23.
//
#include <iostream>
#include "string.h"
#include "RestaurantNode.h"
#include <iomanip>
using namespace std;

// Default Constructor
RestaurantNode::RestaurantNode()
{
    restaurantName = " ";
    restaurantRating = 0;
    mealName = " ";
    mealType = " ";
    mealPrice = 0;
}

// Parameterized Constructor
RestaurantNode::RestaurantNode(string restaurantName, float restaurantRating, string mealName, string mealType, float mealPrice)
{
    this->restaurantName = restaurantName;
    this->restaurantRating = restaurantRating;
    this->mealName = mealName;
    this->mealType = mealType;
    this->mealPrice = mealPrice;
}

// Copy constructor
RestaurantNode::RestaurantNode(const RestaurantNode &r)
{
    restaurantName = r.restaurantName;
    restaurantRating = r.restaurantRating;
    mealName = r.mealName;
    mealType = r.mealType;
    mealPrice = r.mealPrice;
    next = NULL;
}

// Destructor
RestaurantNode::~RestaurantNode()
{
}

// Getters
string RestaurantNode::getRestaurantName() const
{
    return restaurantName;
}

float RestaurantNode::getRestaurantRating() const
{
    return restaurantRating;
}

string RestaurantNode::getMealName() const
{
    return mealName;
}

string RestaurantNode::getMealType() const {
    return mealType;
}

float RestaurantNode::getMealPrice() const
{
    return mealPrice;
}

RestaurantNode* RestaurantNode::getNext() const
{
    return next;
}

// Setters
void RestaurantNode::setRestaurantName(string rName)
{
    restaurantName = rName;

}

void RestaurantNode::setRestaurantRating(float rating)
{
    restaurantRating = rating;

}

void RestaurantNode::setMealName(string mName)
{
    mealName = mName;
}

void RestaurantNode::setMealType(string type)
{
    mealType = type;

}

void RestaurantNode::setMealPrice(float price)
{
    mealPrice = price;
}

void RestaurantNode::setNext(RestaurantNode *n)
{
    next = n;
}

// Print method
void RestaurantNode::print() const {
    cout << "Restaurant: " << restaurantName << endl;
    cout << "Rating: " << fixed << setprecision (1) << restaurantRating << endl;
    cout << "Meal: " << mealName << endl;
    cout << "Type: " << mealType << endl;
    cout << "Price: $" << fixed << setprecision(2) << mealPrice << endl;
    cout << endl;
}
