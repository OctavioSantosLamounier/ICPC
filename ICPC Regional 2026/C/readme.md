# Problema C

Só existem duas opções de compra, e o problema pede o menor valor entre elas: comprar no Brasil custa `C` reais, comprar no exterior custa `K * T` reais (já convertido). A resposta é simplesmente `min(C, K * T)`.

```cpp
int ans = min(t * k, c);
```

## Complexidade

- **Tempo:** `O(1)`.
- **Memória:** `O(1)`.
