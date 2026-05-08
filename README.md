Site do professor: https://sites.google.com/view/slagop/in%C3%ADcio/estruturas-de-dados-m



# Estrutura de dados

## Lista

### Estrutura nó encadeado
- O tipo Item é definido como um tipo inteiro, mas pode ser modificado para outros tipos de dados conforme necessário. `typedef int Item`
- Composto por item do tipo Item e um ponteiro de ponteiro para referenciar o endereço do próximo nó da lista.
    `typedef struct no {
    Item item;
    struct no *prox;
    }*Lista`
- Lista é a nomeação da estrutura nó e é um ponteiro `*Lista`
- A função no é responsável por criar um novo nó, alocando memória para ele, atribuindo o valor do item e o ponteiro para o próximo nó. Aqui, pode ser inicializada por uma Lista p do tipo ponteiro e inicialmente com valor NULL

    Lista no(Item x, Lista p) {
    Lista n = malloc(sizeof(struct no));
    n->item = x;
    n->prox = p;
    return n;
    }

Perceba que as funções que realizam alterações em lista, recebem como parâmetro de entrada o endereço da Lista, pela utilização do operador (&L).
Exemplo, no caso da função de anexar listas em listas:

        void anexa(Lista *A, Lista B) {
        if( !B ) return;
        while( *A )
            A = &(*A)->prox;
        *A = B;
        }

Na main, chamamos a função `anexa(&A,B)`.Na execução, `while (*A)` verifica se o ponteiro de A está apontando para o último endereço da Lista A, que quando incializada é NULL. Desse modo, garantimos que a chamada `A = &(*A) -> prox` navegua pela lista encadeada, ao definir o endereço de A como o endereço do próximo item. Ao final do looping, quando *A já se refere ao endereço do último termo de A (ou seja, NULL), atribuimos a ele o valor de B, sendo, por definição, o ponteiro que referencia o primeiro termo de B;

Sobre a tática de remoção, há um passo intermediário ao criar uma estrutura auxiliar, que referencia para o mesmo valor que L. Dessa forma, avançamos o a lista para o próximo valor e conseguimos liberar o ponteiro que referencia a um endereço que queremos apagar.

        void rem(Item x,Lista *L){
            
            while(*L != NULL && (*L)->item < x)
                L = &(*L)-> prox;
            if (*L == NULL || (*L)->item > x) return;
            Lista n = *L;
            *L = n->prox;
            free(n);
            }

Na execução, ao utilizar `Lista n == *L`, definimos `n` como o ponteiro que referencia o endereço atual de L. Assim, alteramos o ponteiro que referencia L para o próximo ponteiro na estrutura replicada. Assim, podemos usar `free(n)` para liberar o ponteiro que referencia um endereço na memória, garantindo que L continue intacta.



## Mapeamento

- é uma lista encadeada ordenada cujos nós associam valores a chaves

## Dicionário (tabela de hash)

é uma estrutura de dados para associar valores a chaves que:
- é mais eficiente que um mapeamento simples.
- é util quando o universo de chaves é muito maior que o conjunto de chaves efetivas.
- A função hash tem como objetivo mapear chaves com índice do vetor de ponteiro. O problema inicial desse escolha é o conceito de colisões, que são casos onde a função hash direciona o mesmo índice para mais de uma chave.
- Vetor de mapeamentos são utilizados para tratar colisões.

### Função de hash
Sejam C um conjunto de chaves e m o tamanho de um vetor
h: C -> [0...m-1] chave c pertence C num indice correspondente h(c) percente [0...m-1]
A função h espalha as chaves nas posições de um vetor. Uma função de hash é otima se, e só se, produz um espalhamento uniforme das chaves. Se h é ótima e m é tamanho de C, então o espalhamento é perfeito.

