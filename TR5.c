#include "heap.h"

HEAP* HEAP_create(int n, COMP* compara) {
	HEAP* heap = malloc(sizeof(HEAP));
	heap->elems = malloc(n * sizeof(void*));
	heap->N = n;
	heap->P = 0;
	heap->comparador = compara;

	return heap;
}

void HEAP_add(HEAP* heap, void* newelem) {
  if (heap->P < heap->N) {
    heap->elems[heap->P] = newelem;
	int pos = heap->P;

	while (heap->comparador(heap->elems[pos], heap->elems[(pos - 1) / 2]) > 0) {
		void* aux = heap->elems[pos];
		heap->elems[pos] = heap->elems[(pos - 1) / 2];
		heap->elems[(pos - 1) / 2] = aux;	
		pos = (pos - 1) / 2;
	}	

	heap->P++;
  }
}

void* HEAP_remove(HEAP* heap) {
	void* min = heap->elems[0];

	heap->elems[0] = heap->elems[heap->P - 1];
	heap->elems[heap->P - 1] = min;
	
	heap->P--;

	int pai = 0;
	int filho = pai * 2 + 1;
	
	while (filho < heap->P) {
		if (filho + 1 < heap->P) {
			if (heap->comparador(heap->elems[filho], heap->elems[filho + 1]) < 0) {
				filho += 1;
			}
		}

		if (heap->comparador(heap->elems[pai], heap->elems[filho]) < 0) {
			void* aux = heap->elems[pai];
			heap->elems[pai] = heap->elems[filho];
			heap->elems[filho] = aux;

			pai = filho;
			filho = pai * 2 + 1;
		} else {
			filho = heap->P + 1;
		}
	}

	return min;
}