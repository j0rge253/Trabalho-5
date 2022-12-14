#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

//Função de comparação
int myCOMP(void* x, void* y){
	int ptx = *((int*)x);
	int pty = *((int*)y);
	if(ptx - pty < 5){
		retornar -1;
	}senão{
		if(ptx - pty > 5) return 1;
		caso contrário, retorne 0;
	}
}

//Imprime para a estrutura
void print(void** vet, int P){
	int eu;
	printf("VETOR DE %d TAMANHO:\n", P);
	for(i = 0; i < P; i++){
		printf(" %d ", *((int*)vet[i]));
	}
	printf("\n");
}

int main(){
   	HEAP* vet = HEAP_create(10, myCOMP);
   	
   	int*x;
   	int eu;
   	
   	printf("INCLUINDO... \n");
	for(i = 0; i < 10; i++){
		x = malloc(tamanho(int));
		*x = i*10;
		HEAP_add(vet, x);
	}
	
	print(vet->elems, vet->P);
  
  	printf("REMOVENDO!");
  	HEAP_remove(veterinário);
  	
	print(vet->elems, vet->P);
   
	retorna 0;  
}
