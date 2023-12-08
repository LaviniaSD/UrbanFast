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