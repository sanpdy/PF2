//
// Created by Sankalp Pandey on 2/8/23.
//

// Default Constructor
#include <string>
#include "RestaurantList.h"

using namespace std;

// Default Constructor
RestaurantList::RestaurantList()
{
    head = NULL;
}
// Copy Constructor
RestaurantList::RestaurantList(const RestaurantList &r)
{
    head = NULL;
    RestaurantNode *current = r.head;
    while (current != NULL)
    {
        addMeal(current->getRestaurantName(), current->getRestaurantRating(), current->getMealName(),current->getMealType(), current->getMealPrice());
        current = current->getNext();
    }
    }

    // Destructor
    RestaurantList::~RestaurantList() {
        while (head != NULL) {
            RestaurantNode *temp = head;
            head = head->getNext();
            delete temp;
        }
    }

    // Adds a meal to the linked list
    void RestaurantList::addMeal(string restaurantName, float restaurantRating, string mealName, string mealType, float mealPrice) {
        RestaurantNode *n = new RestaurantNode(restaurantName, restaurantRating, mealName, mealType, mealPrice);
        n->setNext(head);
        head = n;
    }

    // Finds the meal with the highest price
    RestaurantNode* RestaurantList::highestPrice() {
        if (!head) {
            return NULL;
        }

        RestaurantNode* max = head;
        float highestPrice = head->getMealPrice();
        RestaurantNode* current = head->getNext();
        while (current) {
            float price = current->getMealPrice();
            if (price > highestPrice) {
                highestPrice = price;
                max = current;
            }
            current = current->getNext();
        }
        return max;
    }

    // Changes the price of a meal
    bool RestaurantList::changePrice(const string& name, float price) {
        RestaurantNode* current = head;
        while (current) {
            if (current->getMealName() == name) {
                current->setMealPrice(price);
                return true;
            }
            current = current->getNext();
        }
        return false;
    }

    // Prints the list
    void RestaurantList::print() const
    {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }
        RestaurantNode *current = head;
        while (current != NULL) {
            current->print();
            current = current->getNext();
        }
    }
