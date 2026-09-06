# Problema L

A única operação permitida e a troca de bits de mesma posição entre dois números. Como isso nunca mistura bits de posições diferentes, o que importa é só a quantidade de números que têm aquele bit ligado, essa quantidade não muda, só é redistribuída entre os N números.

Para deixar a lista lexicograficamente máxima, a estratégia é simples: dar prioridade ao primeiro número. Sempre que sobrar um bit disponível naquela posição, ele vai para `a_1`. O que sobrar depois vai para `a_2`, depois `a_3`, e assim por diante.

## Algoritmo

1. Ler a lista de N inteiros.
2. Para cada bit i do numero N, contar quantos estão ligados, guardando em `b[i]`.
3. Para cada posição j de 0 a N-1 (nessa ordem), percorrer os bits: se `b[i] > 0`, ligar o bit no número atual e decrementar `b[i]`.
4. Imprimir os N números remontados.

## Complexidade

* Tempo: `O(n · 31)`, duas passadas percorrendo até 31 bits por número.
* Memória: `O(n)` para a lista, mais `O(31)` para o vetor de contagem de bits.