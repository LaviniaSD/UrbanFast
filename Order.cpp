/**
 * @file Order.cpp
 * @brief Implementation file for the Order class.
 */

#include "Order.h"

Order::Order(int iOrderNumber, int iDestination, int iOrigin, bool bType):
iOrderNumber(iOrderNumber),
iDestination(iDestination),
next(nullptr),
pProducts(nullptr),
bType(bType),
iPrice(0),
iWeight(0){
    if(bType){
        iOrigin = -1;
    }
}


Order::~Order() {
    // Free the dynamically allocated memory for the product items
    while (pProducts != nullptr) {
        ProductQuantity* temp = pProducts;
        pProducts = pProducts->getNext();
        delete temp;
    }
}

void Order::addProducts(int iProductID, int iPriceProduct, int iQuantityProduct, int iWeightProduct) {
    ProductQuantity* currentProduct = pProducts;

    // Check if the product already exists in the order
    while (currentProduct) {
        // If the product exists, update its quantity, total price, and total weight
        if (currentProduct->getProduct().getProductID() == iProductID) {
            currentProduct->setQuantity(currentProduct->getQuantity() + iQuantityProduct);
            iPrice += currentProduct->getProduct().getPrice() * iQuantityProduct;
            iWeight += currentProduct->getProduct().getWeight() * iQuantityProduct;
            return;
        }
        currentProduct = currentProduct->getNext();
    }
    
    // If the product doesn't exist, create a new product and add it to the order
    Product newProduct(iProductID, iPriceProduct, iQuantityProduct, iWeightProduct,nullptr);
    
    ProductQuantity* newProductQuantity = new ProductQuantity(newProduct, iQuantityProduct);
    iPrice += newProduct.getPrice() * iQuantityProduct;
    iWeight += newProduct.getWeight() * iQuantityProduct;

    // Link the new product to the existing products in the order
    if (pProducts == nullptr) {
        pProducts = newProductQuantity;
    } else {
        newProductQuantity->setNext(pProducts);
        pProducts = newProductQuantity;
    }
}


