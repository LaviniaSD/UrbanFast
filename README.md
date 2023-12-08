# UrbanFast

Repositório do trabalho avaliatico de A2 para a disciplina de Projetos e Análise de Algoritmos. O trabalho foi desenvolvido pelo grupo de alunos:

- [Lavínia Silva](https://github.com/LaviniaSD)
- [Isabela Yabe](https://github.com/IsabelaYabe)
- [Almir Fonseca](https://github.com/AlmirFonseca)
- [Mariana Lima](https://github.com/MarianaLima2000)
- [George Dutra](https://github.com/georgedutra)

## Resumo

O objetivo do trabalho é a implementação de algoritmos de grafos no contexto de um sistema de entregas de produtos, ao estilo IFood. O núcleo principal do sistema, contido no arquivo `Map.cpp`, se trata de um grafo que representa o mapa da cidade, retratando esquinas como vértices, e segmentos de ruas como arestas, cada aresta tendo como peso o tamanho em metros do segmento. 

O grafo é essencialmente não-dirigido, ou seja, todas as ruas são de mão dupla, e não levamos em consideração fatores como tráfego. Para mais detalhes acerca das tarefas e objetivos do trabalho, verifique o arquivo `Descrição do Trabalho.pdf`.

## Estrutura

O trabalho se divide em vários módulos, cada um focado em definir uma classe que exerce um papel no sistema. Cada um desses módulos possuem um arquivo de *header* e um arquivo de implementação.

- `Heap`: Implementa a estrutura de dados *Heap* (ou Fila de Prioridade);
- `Map`: Implementa o corpo principal do sistema, na forma de um grafo;
- `EdgeNode`: Implementa a classe de arestas do grafo;
- `DeliveryMan`: Representa entregadores espalhados pelo mapa;
- `Order`: Representa um pedido de entrega;
- `Product`: Representa um produto a ser incluído num pedido;
- `Seller`: Representa vendedores espahados pelo mapa, de onde saem pedidos;
- `Warehouse`: Representa um Centro de Distribuição, que pode ser utilizado em entregas otimizadas (vide tarefa 3 do pdf).

## Build e Testes

A aplicação é feita para ser testada com o Docker. Para tanto é preciso ter o `docker` instalado e rodar o comando `make build`. Isto criará a imagem do docker `my-running-app`.

Da mesma forma, para rodar os testes basta usar o comando `make test` após o build.
