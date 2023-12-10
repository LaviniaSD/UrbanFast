/**
 * @file Warehouse.cpp
 * @brief Implementation file for the Warehouse class.
 */

#include "Warehouse.h"
#include <iostream>

using namespace std;

// Constructor for the Warehouse class
Warehouse::Warehouse(int iWarehouseID, int WarehouseLocation, Warehouse* next):
iWarehouseID(iWarehouseID),
iWarehouseLocation(iWarehouseLocation),
next(next),
pProductsList(nullptr){}

// Destructor for the Warehouse class
Warehouse::~Warehouse() {
    // Release the dynamically allocated memory for the products
    while (pProductsList != nullptr) {
        Product* temp = pProductsList;
        pProductsList = pProductsList->getNext();
        delete temp;
    }
}

// Method to add products to the warehouse's product list
void Warehouse::addProducts(int iProductID, int iPrice, int iQuantity, int iWeight){
    Product* newProduct = new Product(iProductID, iPrice, iQuantity, iWeight, nullptr);
    if(!pProductsList){
        pProductsList = newProduct;
    }
    else{
        newProduct->setNext(pProductsList);
        pProductsList = newProduct;
    }
}

// Method to add products to the warehouse's product list
void Warehouse::addProducts(Product* newProduct){
    if(!pProductsList){
        pProductsList = newProduct;
    }
    else{
        newProduct->setNext(pProductsList);
        pProductsList = newProduct;
    }
}

// Method to remove products from the warehouse's product list
void Warehouse::removeProducts(int iProductID, int iQuantity) {
    Product* currentProduct = pProductsList;
    Product* previousProduct = nullptr;

    while (currentProduct) {
        if (currentProduct->getProductID() == iProductID) {
            if (iQuantity >= currentProduct->getQuantity()) {
                // Remove the product node from the list
                if (previousProduct) {
                    previousProduct->setNext(currentProduct->getNext());
                } else {
                    pProductsList = currentProduct->getNext();
                }
                delete currentProduct;
            } else {
                // Update the quantity if there is still remaining quantity
                currentProduct->setQuantity(currentProduct->getQuantity() - iQuantity);
            }
            return;
        }

        previousProduct = currentProduct;
        currentProduct = currentProduct->getNext();
    }

    // If the product is not found, display a message
    cout << "Produto não encontrado na lista do centro de distribuição." << endl;
}

bool Warehouse::hasProduct(Product pProduct, int iQuantity) {
    // Iterate through the list of products
    Product* currentProduct = pProductsList;

    while (currentProduct!=nullptr) {
        // Check if the current product matches the specified product
        if (currentProduct->getProductID() == pProduct.getProductID() &&
            currentProduct->getQuantity() >= pProduct.getQuantity()) {
            return true;  // Product found with sufficient quantity
        }

        currentProduct = currentProduct->getNext();
    }

    return false;  // Product not found or quantity insufficient
}