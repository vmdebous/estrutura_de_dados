#include <stdlib.h>

#include <stdio.h>


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


typedef struct fila {
   int   max;
   int   total;
   int   inicio;
   int   final;
   Itemf *item;
} *Fila;




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


void ins(Item x, Lista *L) {
   while( *L != NULL && (*L)->item < x ) 
      L = &(*L)->prox;
   *L = no(x,*L);
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
int main(void) {
 	Lista A = aleatoria(3,10);
	exibe(A);
	Lista B = aleatoria(5,100);
	exibe(B);
	anexa(&A,B);
	exibe(A);
	Lista C = NULL;
	ultimo(&C);
	Lista D = inversa(A);
	exibe(D);
	printf("%d\n",len(&A));
	printf("%d\n",sum(&A));
	Lista E = clone(&A);
	exibe(E);
	A -> item = 900;
	exibe(A);
	exibe(E);
	return 0;
}
