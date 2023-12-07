#include "Order.h"

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


ReturnDijkstra Order::FindRoute(Map map,DeliveryMan deliveryman){
    if (getType == 0){
        // Obter posições do entregador, vendedor e cliente
        int deliverymanPosition = deliveryman.getLocation();
        int sellerPosition = getOrigin();
        int customerPosition = getDestination();

        // Calcular rotas usando Dijkstra
        ReturnDijkstra routeDeliverymanToSeller = map.cptDijkstra(deliverymanPosition);
        ReturnDijkstra routeSellerToCustomer = map.cptDijkstra(sellerPosition);

        // Calcular rota completa concatenando as rotas parciais
        int* DeliverymanToSeller = routeDeliverymanToSeller.parents;
        int* SellerToCustomer = routeSellerToCustomer.parents;
        int* fullRoute = new int[map.getNumVertices()];
        int* distances = new int[map.getNumVertices()];
        int* minDistance = 0;
    
        // Calcula a rota do cliente ao vendedor
        int current = customerPosition;
        while (current != sellerPosition){
            minDistance += routeSellerToCustomer.distances[current];
            fullRoute[current] = SellerToCustomer[current];
            distances[current] = routeSellerToCustomer.distances[current];
            current = SellerToCustomer[current];
        }

        // Calcula a rota do vendedor ao entregador
        while (current != deliverymanPosition){
            minDistance += routeSellerToCustomer.distances[current];
            fullRoute[current] = DeliverymanToSeller[current];
            distances[current] = routeDeliverymanToSeller.distances[current];
            current = DeliverymanToSeller[current];
        }

        fullRoute[deliverymanPosition] = deliverymanPosition;
        minDistance += routeDeliverymanToSeller.distances[deliverymanPosition];
        distances[deliverymanPosition] = 0;

        // Retorna a rota completa
        ReturnDijkstra fullRouteReturn;
        fullRouteReturn.distances = distances;
        fullRouteReturn.parents = fullRoute;
        fullRouteReturn.minDistance = minDistance;

        return fullRouteReturn;

    }

}




