Site do professor: https://sites.google.com/view/slagop/in%C3%ADcio/estruturas-de-dados-m




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


