# Problema D

As marcações no pergaminho correspondem exatamente ao conjunto de células livres do terreno. Como cada orientação do pergaminho (rotação/reflexão) é uma transformação bijetora, o número de marcações que caem sobre o terreno depois de transformado é sempre igual à quantidade original de células livres. Só existem duas possibilidades: ou todas caem sobre células livres (e portanto caem **exatamente** sobre o mesmo conjunto de células livres do terreno, já que a quantidade é a mesma), ou pelo menos uma cai sobre um obstáculo. Ou seja, uma orientação é válida **se e somente se aplicá-la ao grid original reproduz o grid original de novo** — o problema vira contar quantas das 8 simetrias do grupo diedral `D4` (identidade, rotações de 90°/180°/270°, e essas 4 mais um espelhamento) deixam o grid invariante.

Um detalhe importante: girar 90° ou 270° troca as dimensões (`N x M` vira `M x N`). Isso só "alinha aos limites originais" quando `N = M`; nos demais casos, essas rotações são automaticamente inválidas (e o código detecta isso comparando as dimensões antes mesmo de comparar o conteúdo).

## Algoritmo

1. Lê o grid `v1` (`N x M`). A orientação identidade sempre conta como válida (é dada pelo enunciado).
2. Gira `v1` em 90°, 180° e 270° (aplicando a rotação sucessivamente) e compara cada resultado com o grid original.
3. Espelha `v1` horizontalmente e repete o mesmo processo: compara o espelhado puro e suas rotações de 90°, 180° e 270° com o original.
4. A resposta é `8` menos a quantidade de orientações (dentre as 7 não-identidade) que **não** reproduziram o grid original.

## Complexidade

- **Tempo:** `O(N * M)` — cada uma das 8 orientações é gerada e comparada em tempo linear no tamanho do grid.
- **Memória:** `O(N * M)` para guardar as matrizes.
