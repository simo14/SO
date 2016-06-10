#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libreria.h"
#include "colastruc.h"
#include "liststruc.h"

int head(int m) {
	int n = m;
	int i;
	char string[1024];
	for(i=0; i<=n-1; i++){
		if(fgets(string, sizeof(string), stdin)){
			if(!fputs(string, stdout)){		//fputs doesn't add newline like puts	
				fprintf(stderr, "Output error.");	
				return -1;	
			}	
		}else {	
			fprintf(stderr, "Input error.");
			return -1;
		}
		
	}
	return 0;
}

int tail(int p) {
	int q=p;
	char buf[1024];
	void leerCola(struct cola *q);
	struct cola *c;
	c=malloc(sizeof(struct cola));
	struct linea *l;
	while(fgets(buf, sizeof buf, stdin) != NULL){
		l=malloc(sizeof(struct linea));
		l->contenido=malloc(sizeof(char[1024]));
		strcpy(l->contenido, buf);
		encolar(c,l);
		
		if(c->elementos > p){
			descolar(c);
		}
	}
	leerCola(c);
	eliminarCola(c);
	return 0;
}

int longlines(int r) {
	int m=r;
	if (m<1) return 0;
	char buf[1024];
	struct listel *l;
	l=malloc(sizeof(struct listel));
	while(fgets(buf,sizeof buf, stdin)!=NULL){		
		addInOrder(&l,buf);
		if(m==0){
			rmv(&l,r);
		}else{
			m=m-1;
		}
	}
	struct listel *iterator = l;
	while((iterator!=NULL)){
		printf("%s",iterator->content);
		iterator = iterator->next;
	}
	rmvList(l);
	return 0;
}

void leerCola(struct cola *q){
	if(q->primero!=NULL){
		struct linea *aux = q->primero;
		while(aux->next != NULL) { 
			printf("%s", aux->contenido);
			aux=aux->next;
		}
		printf("%s", aux->contenido);
	}
	return;
}

/*
    Estructuras auxiliares
*/

//lista dinámica simplemente enlazada
struct listel{

		struct listel *next;

		char *content;

		int size;

};

	//Add a string to the list in order
	int addInOrder(struct listel **list, char *content){
		if(!list) return -1;		
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

	//Remove the i-element of listel
	int rmv(struct listel **listel, int position){
		struct listel *iterator;
		struct listel *aux;
		int n=position;
		if (!listel) return -1;
		if (position == 0) {
			aux = *listel;
			*listel=aux->next;
			free(aux);
			return 0;
		}
		iterator = *listel;
		while((n>1)&&(iterator->next!=NULL)){			
			
			iterator=iterator->next;
			n=n-1;

		}
		if(n==1){
			free(iterator->next);
			iterator->next=NULL;
			return 0;
		}
		return 0;
	}


	int rmvList(struct listel *list){
		while(list->next!=NULL){
			rmv(&list, 0);
		}
	}


	int compare(struct listel *list1,struct listel *list2){

		if (list1->size > list2->size){
			return 1;
		} else if (list2->size > list1->size){
			return -1;
		} else
			return 0;

	}

          
