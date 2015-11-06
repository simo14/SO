#include <stdlib.h>
#include <stdio.h>
#include "colastruc.h"
	
	int encolar (struct cola *queue, struct linea *nuevo) {
		if(queue->primero==NULL){
			queue->primero=nuevo;
			queue->ultimo=nuevo;
			queue->primero->next=NULL;
			queue->elementos = 1;
		}else{
			queue->ultimo->next = nuevo;
			queue->ultimo = queue->ultimo->next;
			queue->elementos = queue->elementos+1;
		}
		return 0;
	}
	
	int descolar (struct cola *queue) {
		if(queue->primero != queue->ultimo){
			struct linea *temp = queue->primero;
			queue->primero = queue->primero->next;
			free(temp);
			queue->elementos = queue->elementos-1;
		}else {
			queue->primero=NULL;
			queue->ultimo=NULL;
			queue->elementos=0;
		}
		return 0;	
	}

	int eliminarCola(struct cola *queue) {
		while (queue->ultimo!=NULL) {
			descolar(queue);
		}
		return 0;	
	}
	

