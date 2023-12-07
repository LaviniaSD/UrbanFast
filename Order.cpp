#include "Order.h"
#include "DeliveryMan.h"

// Constructor for the Order class
Order::Order(int iOrderNumber, int iDestination, int iOrigin, bool bType):
iOrderNumber(iOrderNumber),
iDestination(iDestination),
next(nullptr),
iOrigin(iOrigin),
pProducts(nullptr),
bType(bType),
iPrice(0),
iWeight(0){}

// Destructor for the Order class
Order::~Order() {
    // Free the dynamically allocated memory for the product items
    while (pProducts != nullptr) {
        ProductQuantity* temp = pProducts;
        pProducts = pProducts->getNext();
        delete temp;
    }
}

// Method to add products to the order
void Order::addProducts(int iProductID, int iPrice, int iQuantity, int iWeight) {
    ProductQuantity* currentProduct = pProducts;

    // Check if the product already exists in the order
    while (currentProduct) {
        // If the product exists, update its quantity, total price, and total weight
        if (currentProduct->getProduct().getProductID() == iProductID) {
            currentProduct->setQuantity(currentProduct->getQuantity() + iQuantity);
            iPrice += currentProduct->getProduct().getPrice() * iQuantity;
            iWeight += currentProduct->getProduct().getWeight() * iQuantity;
            return;
        }
        currentProduct = currentProduct->getNext();
    }

    // If the product doesn't exist, create a new product and add it to the order
    Product newProduct(iProductID, iPrice, iQuantity, iWeight, nullptr);
    
    ProductQuantity* newProductQuantity = new ProductQuantity(newProduct, iQuantity);
    iPrice += newProduct.getPrice() * iQuantity;
    iWeight += newProduct.getWeight() * iQuantity;

    // Link the new product to the existing products in the order
    if (pProducts != nullptr) {
        newProductQuantity->setNext(pProducts);
    }
    pProducts = newProductQuantity;
}







