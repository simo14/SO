#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prac1.h"
#include "colastruc.h"
#include "liststruc.h"

int head(int m) {
	int n = m;
	int i;
	char string[1024];
	for(i=0; i<=n-1; i++){
		if(fgets(string, sizeof(string),stdin)){
			if(fputs(string, stdout)){		//fputs doesn't add newline like puts	
				return 0;
			}else {
				fprintf(stderr, "Output error.");	
				return -1;	
			}	
		}else {	
			fprintf(stderr, "Input error.");
			return -1;
		}
		
	}
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
}

int longlines(int r) {
	int m=r;
	char buf[1024];
	struct listel *l;
	l=malloc(sizeof(struct listel));
	while(fgets(buf,sizeof buf, stdin)!=NULL){
		addInOrder(&l,buf);
		if(m==0){
			rmv(&l,m);
		}else {
			m=m-1;
		}
	}
	struct listel *iterator = l;
	while(iterator!=NULL){
		printf("%s", iterator->content);
		iterator = iterator->next;
	}
}

void leerCola(struct cola *q){
	if(q->primero!=NULL){
		struct linea *aux = q->primero;
		while(aux->next != NULL) { 
			printf("leo uno: ");
			printf("%s\n", aux->contenido);
			aux=aux->next;
		}
		printf("%s\n", aux->contenido);
	}
}
          
