




#include <stdlib.h>

#include <stdio.h>

#include <string.h>

#include "mapeamento.h"

typedef struct dic {
	int tam;
	Map *vet;}*Dic;

Dic dic(int m) {
   Dic d = malloc(sizeof(struct dic));
   d->tam = m;
   d->vet = malloc(m*sizeof(Map));
   for(int i=0; i<m; i++) d->vet[i] = NULL;
   return d;
}


int hash(int c, int m) {
   return (c % m);
}



void insd(Chave c, Valor v, Dic d) {
   insm_rec(c, v, &d->vet[hash(c,d->tam)]);
}

void exibed(Dic d) {
   for(int i=0; i<d->tam; i++) {
      printf("%d: ", i);
      exibem(&d->vet[i],&d->vet[i]);
   }
}
void remd(Chave c, Dic d) {
   remm_rec(c, &d->vet[hash(c,d->tam)]);
}

int pertd(Chave c, Valor v, Dic d) {
   return pertm(c, v, d->vet[hash(c,d->tam)]);
}

void destroid(Dic *d) {
   for(int i=0; i<(*d)->tam; i++)
      free((*d)->vet[i]);
	  
   free(*d);
   *d = NULL;
}

int main(void){
	Dic D = dic(15);
    insd(9, "Bia", D);
	insd(15, "Boa", D);
	remd(15,D);
	remd(9,D);
	exibed(D);
	destroid(&D);
	


	return 0;}