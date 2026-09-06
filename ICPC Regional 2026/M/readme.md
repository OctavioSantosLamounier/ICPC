# Problema M

É um caminho mínimo com um "orçamento" de arestas especiais — o clássico truque de **Dijkstra em camadas**. Como `K <= 10` é pequeno, dá para expandir o estado de "ponto de presença atual" para `(ponto atual, quantidade de links de micro-ondas ainda disponíveis)`. A partir de cada estado é sempre possível seguir por uma conexão de fibra (custo `f_ij`, sem gastar orçamento) e, se a conexão também tiver canal de micro-ondas (`w_ij != -1`) e ainda sobrar orçamento, também é possível segui-la pelo custo `w_ij`, consumindo um link do orçamento.

Como todos os pesos são não-negativos, basta rodar Dijkstra normalmente sobre esse grafo expandido com `N * (K+1)` estados; a primeira vez que o ponto `N` (com qualquer orçamento restante) sai da fila de prioridade já é a resposta.

## Algoritmo

1. Monta a lista de adjacência guardando, para cada conexão, os dois pesos `f_ij` (fibra) e `w_ij` (micro-ondas, ou ausente).
2. Roda Dijkstra sobre os estados `(v, k)`, começando em `(1, K)` com distância `0`.
3. De cada estado `(u, k)`, relaxa `(v, k)` usando o peso da fibra, e `(v, k-1)` usando o peso do micro-ondas quando disponível e `k > 0`.
4. Assim que o ponto `N` é retirado da fila de prioridade pela primeira vez, imprime a distância — essa já é a menor latência possível usando no máximo `K` links de micro-ondas.

## Complexidade

- **Tempo:** `O((N + M) * K * log(N * K))`.
- **Memória:** `O(N * K)`.
