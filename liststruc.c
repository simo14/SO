#include <stdlib.h>

#include <string.h>

#include <stdio.h>

#include "liststruc.h"







	int addInOrder(struct listel *list, char *content){

		struct listel *iterator;		
		struct listel *element;
		iterator = listel;
		int len;
		len = strlen(*content);
		element = malloc(sizeof(struct listel));
		element->size = len;
		strcpy(element->content,*content);
		

		if (list = NULL){ //First element
			element->next=NULL;			
			list = element;	
		} else{ //another element

			while((iterator->size > len)&&(iterator->next!=NULL)){
				iterator = iterator->next;
			}
			element->next = iterator->next;
			iterator->next = element;
		}



	}





	int rmv(struct listel *listel, int position){

		struct listel *iterator;
		struct listel *aux;
		aux= listel;
		iterator = listel;
		if(listel == NULL){
			return 0;
		} else if (listel->next == NULL) {
			listel = NULL;			
			free(aux);			
			return 	1;	
		} else{	
			while ((iterator->next!=NULL)&&(position>0)){
				aux= iterator;			
				position = position -1;
				iterator = iterator->next;
			}
			aux->next = iterator->next;
			free(iterator);
			return 1;

		}		



	}







	int rmvList(struct listel *list){



	}



	int compare(struct listel *list1,struct listel *list2){

		if (list1->size > list2->size){
			return 1;
		} else if (list2->size > list1->size){
			return 2;
		} else
			return 0;

	}















	/*int encolar (struct cola *queue, struct linea *nuevo) {



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



*/

	


