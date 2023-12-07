#include "Seller.h"

#include <iostream>

using namespace std;

// Constructor for the Seller class
Seller::Seller(int iSellerID, int SellerLocation, Seller* next):
iSellerID(iSellerID),
iSellerLocation(iSellerLocation),
next(next),
pProductsList(nullptr){}

// Destructor for the Seller class
Seller::~Seller() {
    while (pProductsList != nullptr) {
        Product* temp = pProductsList;
        pProductsList = pProductsList->getNext();
        delete temp;
    }
}

// Method to add products to the seller's product list
void Seller::addProducts(int iProductID, int iPrice, int iQuantity, int iWeight){
    Product* newProduct = new Product(iProductID, iPrice, iQuantity, iWeight, nullptr);
    if(!pProductsList){
        pProductsList = newProduct;
    }
    else{
        newProduct->setNext(pProductsList);
        pProductsList = newProduct;
    }
}

// Method to remove products from the seller's product list
void Seller::removeProducts(int iProductID, int iQuantity) {
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
    cout << "Produto não encontrado na lista do vendedor." << endl;
}