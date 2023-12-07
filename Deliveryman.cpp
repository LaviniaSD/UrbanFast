#include "Deliveryman.h"

DeliveryMan::DeliveryMan(int iDeliveryManID, int iLocation, int iCapacity, int iItems, int iQuantity):
iDeliveryManID(iDeliveryManID), 
iLocation(iLocation), 
iCapacity(iCapacity), 
iItems(iItems), 
iQuantity(iQuantity) {}

Order DeliveryMan::OrderSugestion(int* route[],int max_distance){
    // Estrutura para armzenar os CD e vendedores nos arredores

    // Percorra a rota armazenando os CD e vendedores nos aredores com a distância máxima definida

    // Para cada vendedor, verifique os pedidos que ele possui e armazene em uma estrutura com peso e valor agregado pelo peso e valor dos itens

    // Para cada pedido, verifique se seus itens estão disponíveis no CD e se a quantidade é suficiente para atender o pedido

    // Caso seja, armazene o pedido em uma estrutura com peso e valor agregado pelo peso e valor dos itens

    // Implemente um algoritmo de Knapsack para escolher os pedidos que serão entregues

    // Altere a rotas para que ela passe pelos vendedores e CDS escolhidos

    // Retorne os pedidos escolhidos

}

