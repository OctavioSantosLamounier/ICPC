# Problema K

Esse é o clássico problema de garantir uma cota de cada tipo no **pior caso** de uma retirada cega. Se você precisa de pelo menos `K_i` unidades do componente `i`, no pior cenário possível o adversário esvazia completamente todos os outros tipos primeiro (`soma(C) - C_i` retiradas) e só depois começa a entregar o componente `i` — e ainda assim pode segurar até `C_i - K_i` unidades dele antes de finalmente ser obrigado a te dar a `K_i`-ésima. Ou seja, no pior caso, pode ser necessário retirar até

```
soma(C) - (C_i - K_i)
```

componentes antes de a meta do tipo `i` estar **garantida**. Como as metas de todos os tipos precisam ser cumpridas simultaneamente, a resposta é o maior desses valores entre todos os `i` — esse número de retiradas é suficiente para satisfazer até o tipo mais "demorado", e portanto também todos os demais.

Se algum tipo já tem estoque insuficiente (`C_i < K_i`), a meta nunca pode ser cumprida, independentemente da ordem — resposta `-1`.

## Algoritmo

1. Lê `C_i` (somando em `soma`) e `K_i` para cada tipo.
2. Se existir `i` com `C_i < K_i`, imprime `-1` e encerra.
3. Caso contrário, calcula `max_i(soma - (C_i - K_i))` e imprime o resultado.

## Complexidade

- **Tempo:** `O(N)`.
- **Memória:** `O(N)`.
