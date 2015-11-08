#include <stdlib.h>

#include <string.h>

#include <stdio.h>

#include "liststruc.h"

	int addInOrder(struct listel **list, char *content){
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
			while((iterator->next!=NULL)&&(iterator->next->size > len)){
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
		int n=position;
		if (!listel) return 0;
		if (position == 0) {
			free(*listel);
			*listel=NULL;
			return 1;
		}
		iterator = *listel;
		while((n>1)&&(iterator->next!=NULL)){			
			
			iterator=iterator->next;
			n=n-1;

		}
		if(n==1){
			free(iterator->next);
			iterator->next=NULL;
			return 1;
		}
		return 0;
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
