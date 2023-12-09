#include "Order.h"

Order::Order(int iOrderNumber, int iDestination, int iOrigin, bool bType)
    : iOrderNumber(iOrderNumber),
      iDestination(iDestination),
      iOrigin(iOrigin),
      next(nullptr),
      pProducts(nullptr),
      bType(bType),
      iPrice(0),
      iWeight(0),
      numTypeProducts(0) {}

Order::~Order() {
    // Free the dynamically allocated memory for the product items
    while (pProducts != nullptr) {
        Product* temp = pProducts;
        pProducts = pProducts->getNext();
        delete temp;
    }
}

void Order::addProducts(int iProductID, int iPrice, int iQuantity, int iWeight) {
    Product* newProduct = new Product(iProductID, iPrice, iQuantity, iWeight, nullptr);
    if(!pProducts){
        pProducts = newProduct;
    }
    else{
        newProduct->setNext(pProducts);
        pProducts = newProduct;
    }
    iPrice += iPrice * iQuantity;
    iWeight += iWeight * iQuantity;
    numTypeProducts++;
}

void Order::addProducts(Product* newProduct) {
    if(!pProducts){
        pProducts = newProduct;
    }
    else{
        newProduct->setNext(pProducts);
        pProducts = newProduct;
    }
    iPrice += iPrice * newProduct->getQuantity();
    iWeight += iWeight * newProduct->getQuantity();
    numTypeProducts++;
}
