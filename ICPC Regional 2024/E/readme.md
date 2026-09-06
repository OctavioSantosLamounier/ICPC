# Problema E

A estrutura original do estojo é crescente da esquerda para a direita e crescente de cima para baixo. Isso significa que, no estado original, o canto superior esquerdo sempre contém o menor valor de toda a matriz, e esse valor é sempre menor que seus dois vizinhos (o da direita e o de baixo).

Como o estojo só pode ter sido rotacionado 0, 1, 2 ou 3 vezes de 90° no sentido horário, o valor mínimo local muda para um canto diferente a cada rotação:

- Se o **canto superior esquerdo** for o mínimo local → o estojo já está no estado original → **0** rotações.
- Se o **canto superior direito** for o mínimo local → precisa de **1** rotação anti-horária.
- Se o **canto inferior direito** for o mínimo local → precisa de **2** rotações anti-horárias.
- Se o **canto inferior esquerdo** for o mínimo local → precisa de **3** rotações anti-horárias.

Ou seja, basta analisar os quatro cantos da matriz para descobrir em qual estado de rotação ela se encontra, sem precisar simular nenhuma rotação de fato.

## Algoritmo

1. Ler a matriz `N x N`.
2. Testar cada um dos 4 cantos, verificando se ele é menor que seus vizinhos adjacentes.
3. Imprimir o índice (`0`, `1`, `2` ou `3`) do canto que satisfaz a condição.

## Complexidade

- **Tempo:** `O(n²)`, para ler e armazenar a matriz.
- **Memória:** `O(n²)`, para armazenar a matriz `N x N`.