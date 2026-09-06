# Problema A

O sinal é `I_n = (C_n - V_n) / (C_n + V_n)`, mas repare que `C_n` e `V_n` são somas de valores não-negativos e o enunciado garante `c_1 + v_1 > 0`. Logo, para qualquer profundidade `n >= 1`, o denominador `C_n + V_n` é sempre estritamente positivo — ele só cresce (ou fica igual) a partir do primeiro nível.

Isso significa que **o sinal de `I_n` é exatamente o sinal do numerador `C_n - V_n`**: nunca precisamos calcular a divisão de verdade, só comparar `C_n` com `V_n` (evitando de quebra qualquer problema de precisão com ponto flutuante).

Como as consultas só pedem profundidades `n_j` (não intervalos), basta pré-computar as somas prefixo `C_i` e `V_i` uma única vez e responder cada consulta em `O(1)`.

## Algoritmo

1. Percorre os `N` níveis acumulando `C_i = C_{i-1} + c_i` e `V_i = V_{i-1} + v_i`, guardando o sinal de `C_i - V_i` (`1`, `0` ou `-1`) num vetor.
2. Para cada uma das `Q` consultas `n_j`, consulta o sinal pré-computado em `n_j` e imprime `COMPRA`, `VENDA` ou `NEUTRO`.

## Complexidade

- **Tempo:** `O(N + Q)`.
- **Memória:** `O(N)`.
