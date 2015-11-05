#include <stdio.h>
#include <stdlib.h>
#include "prac1.h"
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
	while(fgets(buf, sizeof buf, stdin) != NULL){
		struct linea *l;
		l=malloc(sizeof(struct linea));
		l->contenido = buf;
		encolar(c,l);
		if(c->elementos >= p){
			descolar(c);
		}
	}
	leerCola(c);
	eliminarCola(c);
}

void leerCola(struct cola *q){
	struct linea *aux = q->primero;
	while(aux->next != NULL) { 
		printf("leo uno");
		printf("%s\n", aux->contenido);
		aux=aux->next;
	}
}
               
