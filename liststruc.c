#include <stdlib.h>

#include <string.h>

#include <stdio.h>

#include "liststruc.h"

	int addInOrder(struct listel **list, char *content){
		//struct listel *list = *listpointer;
		struct listel *iterator;		
		struct listel *element;
		iterator = *list;
		int len;
		len = strlen(content);
		element = malloc(sizeof(struct listel));
		element->content = malloc(sizeof(char[1024]));
		element->size = len;
		strcpy(element->content,content);
		

		if ((*list)->content==NULL){ 			//First element
			element->next=NULL;			
			*list = element;	
		} else if ((*list)->size < len){
			element->next=*list;
			*list=element;	
		} else if (iterator->next ==NULL){
			(*list)->next=element;
			element->next=NULL;		
		} else{ 					//Another element
			while((iterator->next->size > len)&&(iterator->next->next!=NULL)){
				iterator = iterator->next;
			}
			element->next = iterator->next;
			iterator->next = element;
		}
		return 0;

	}


	int rmv(struct listel **listel, int position){

		struct listel *iterator;
		struct listel *aux;
		aux= *listel;
		iterator = *listel;
		if(((*listel)->content) == NULL){
			return 0;
		} else if ((*listel)->next == NULL) {
			*listel = NULL;			
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