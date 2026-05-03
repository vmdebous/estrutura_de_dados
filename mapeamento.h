#include <stdlib.h>

#include <stdio.h>

typedef int Chave;
typedef char Valor[22];
typedef struct map {
   Chave chave;
   Valor valor;
   struct map *prox;
} *Map;
#define avanca(i) (i = (i+1) % F->max)

typedef int Itemf;

typedef int Item;

typedef struct no {
   Item item;
   struct no *prox;
} *Lista;
Lista no(Item x, Lista p) {
   Lista n = malloc(sizeof(struct no));
   n->item = x;
   n->prox = p;
   return n;
}




void exibe(Lista L) {
   while( L != NULL ) {
      printf("%d\n",L->item);
      L = L->prox;
   }
}

void troca(int v[], int i, int j) {
   int x = v[i];
   v[i] = v[j];
   v[j] = x;
}


Lista aleatoria(int n, int m) {
   Lista L = NULL;
   while( n>0 ) {
      L = no(rand()%m, L);
      n--;
   }
   return L;
}

void anexa(Lista *A, Lista B) {
   if( !B ) return;
   while( *A )
      A = &(*A)->prox;
   *A = B;
}
void ultimo(Lista *A) {
         if( (*A) == NULL ) printf("sou nulo\n");
         while( *A ){
		   if ((*A)-> prox == NULL){ printf("%d\n",(*A)->item);} 
			A = &(*A)->prox;}
}


int len(Lista *L) {
   if ((*L) == NULL) return 0;
   return 1+len(&(*L)->prox);
}

int sum(Lista *L) {
   if ((*L) == NULL) return 0;
   return (*L)->item +sum(&(*L)->prox);
}

Lista clone(Lista *L) {
   if ((*L) == NULL) return NULL;
   return no((*L)->item,clone(&(*L)->prox));
}



Lista inversa(Lista L) {
	Lista I = NULL;
	while(L){
		I = no(L->item,I);
		L = L ->prox;	
	}
	return I;
	}


// insere sem repetição
void ins_isr(Item x,Lista *L){
	while ((*L) != NULL && (*L)-> item < x){
		L = &(*L) -> prox;}
	if (*L == NULL || x < (*L) -> item){
		*L = no(x,*L);
		}
	}

void ins_rec(Item x, Lista *L){
	if (*L == NULL || x <= (*L)->item) *L = no(x,*L);
	else ins_rec(x,&(*L)->prox);
	}

void ins(Item x, Lista *L) {
   while( *L != NULL) 
      L = &(*L)->prox;
   *L = no(x,*L);
}

// insere ordenado
void ins_ord(Item x, Lista *L) {
   while( *L != NULL && (*L)->item < x ) 
      L = &(*L)->prox;
   *L = no(x,*L);
}

void ins_isr_rec(Item x, Lista *L){
	if (*L == NULL || x < (*L)->item) *L = no(x,*L);
	else if (x>(*L)->item) ins_isr_rec(x,&(*L)->prox);
	}

void rem(Item x,Lista *L){
	
	while(*L != NULL && (*L)->item < x)
		L = &(*L)-> prox;
	if (*L == NULL || (*L)->item > x) return;
	Lista n = *L;
	*L = n->prox;
	free(n);
	}

void rem_todo(Item x,Lista *L){
	
	while(*L != NULL && (*L)->item < x)
		L = &(*L)-> prox;
	if (*L == NULL || (*L)->item > x) return;
	
	while(*L != NULL && (*L)->item == x){
		Lista n = *L;
		*L = n->prox;
		free(n);}
	if (*L == NULL || (*L)->item > x) return;
}

int pert_rec(Item x, Lista L) {
   if (L == NULL || L -> item < x) return 0;
   if (L->item == x) return 1;
   return pert_rec(x,L->prox);
}

int csc(Lista L){
   if (L == NULL) return 1;
   if (L->prox == NULL) return 1;
   if (L->item > L->prox->item) return 0;
   return csc(L->prox);
}


// estritamente crescente
int cec(Lista L){
   if (L == NULL) return 1;
   if (L->prox == NULL) return 1;
   if (L->item >= L->prox->item) return 0;
   return cec(L->prox);
}

int dsc(Lista L){
   if (L == NULL) return 1;
   if (L->prox == NULL) return 1;
   if (L->item < L->prox->item) return 0;
   return dsc(L->prox);
}

int dec(Lista L){
   if (L == NULL) return 1;
   if (L->prox == NULL) return 1;
   if (L->item < L->prox->item) return 0;
   return dec(L->prox);
}
int main(void) {
 	// Lista A = aleatoria(3,10);
	// exibe(A);
	// Lista B = aleatoria(5,100);
	// exibe(B);
	// anexa(&A,B);
	// exibe(A);
	// Lista C = NULL;
	// ultimo(&C);
	// Lista D = inversa(A);
	// exibe(D);
	// printf("%d\n",len(&A));
	// printf("%d\n",sum(&A));
	// Lista E = clone(&A);
	// exibe(E);
	// A -> item = 900;
	// exibe(A);
	// exibe(E);

   Lista L = NULL;
	ins_isr_rec(5,&L);
	ins_isr_rec(10,&L);
	ins_isr_rec(15,&L);
	ins_isr_rec(2,&L);
	ins_isr_rec(15,&L);
	ins_isr_rec(15,&L);
	ins_isr_rec(15,&L);
	ins_rec(15,&L);
	
	rem_todo(15,&L);
	//printf("%d\n",pert_rec(100,L));
	printf("simplesmente crescente? %d\n",csc(L));
	ins(1,&L);
	printf("simplesmente crescente? %d\n",csc(L));
	return 0;
}
