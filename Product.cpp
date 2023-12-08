#include "Product.h"

Product::Product(int iProductID, int iPrice, int iQuantity, int iWeight, Product* next):
iProductID(iProductID),
iPrice(iPrice),
iQuantity(iQuantity),
iWeight(iWeight){}