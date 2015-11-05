#include <stdlib.h>
#include <stdio.h>
#include "liststruc.h"
	
	int encolar (struct cola *queue, struct linea *nuevo) {
		printf("Encolo %s",nuevo->contenido);
		if(queue->primero==NULL){
			queue->primero=nuevo;
			queue->ultimo=nuevo;
			queue->primero->next=NULL;
			queue->elementos = 1;
		}else{
			queue->ultimo->next = nuevo;
			queue->ultimo = queue->ultimo->next;
			queue->elementos = queue->elementos++;
		}
		return 0;
	}
	
	int descolar (struct cola *queue) {
		printf("Desencolo");
		if(queue->primero != queue->ultimo){
			struct linea *temp = queue.primero;
			queue.primero = queue->primero.next;
			free(temp);
			queue->elementos = queue->elementos--;
		}else {
			queue.primero=NULL;
			queue.ultimo=NULL;
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
	

