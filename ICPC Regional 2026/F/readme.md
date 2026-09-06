# Problema F

As leis da flor dizem que `f` (a função que transforma sementes depositadas em sementes devolvidas) é: definida sobre inteiros, estritamente crescente, sempre devolve mais do que foi depositado, e satisfaz `f(f(n)) = 3n`. Essas condições, juntas, determinam `f` de forma **única** — dá para reconstruí-la sem nunca calcular potências de 3 explicitamente, usando a própria relação `f(f(n)) = 3n` para "propagar" valores já conhecidos.

A ideia: mantemos dois vetores enquanto calculamos `f(1), f(2), ..., f(N)` em ordem.

- `indexs[n]` guarda `f(n)`, assim que descoberto.
- `nums[v]` guarda, se já soubermos, qual `m` satisfaz `f(m) = v` — ou seja, `v` já está "reservado" como imagem de `m`.

Ao processar cada `n`, dois casos:

- **`n` já é imagem de algum `m` anterior** (`nums[n] = m`, ou seja, `f(m) = n`): então, pela própria regra da flor, `f(n) = f(f(m)) = 3m`. Aproveitamos e já reservamos `nums[3m] = n`, pois isso implica `f(3m) = f(f(n)) = 3n`, informação que será usada quando o laço chegar em `3m`.
- **`n` ainda não apareceu como imagem de ninguém**: como `f` é estritamente crescente e não há nenhuma restrição forçando um valor maior, a escolha mínima válida é simplesmente continuar a sequência: `f(n) = f(n-1) + 1`. Também reservamos essa nova imagem em `nums`.

O caso base é `f(1) = 2` (o menor valor estritamente maior que `1`, consistente com `f(f(1)) = 3`).

Como `f` é estritamente crescente e `f(f(n)) = 3n > f(n)`, vale `f(n) < 3n` para todo `n` — por isso os vetores só precisam de tamanho da ordem de `3N` para acomodar qualquer índice usado.

## Algoritmo

1. Inicializa o caso base: `nums[2] = 1`, `indexs[1] = 2`.
2. Para `n` de `2` até `N`:
   - se `nums[n] != 0`: `indexs[n] = 3 * nums[n]` e `nums[indexs[n]] = n`;
   - senão: `indexs[n] = indexs[n-1] + 1` e `nums[indexs[n]] = n`.
3. Imprime `indexs[N]`.

## Complexidade

- **Tempo:** `O(N)`.
- **Memória:** `O(N)` (vetores dimensionados até `~3N`, já que `f(n) < 3n`).
