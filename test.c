#include "prac1.h"
#include "liststruc.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
int main (int argc, char *argv[]) {
	if(argc>1){
		if(head(atoi(argv[1]))!=0){
			printf("Hubo un error\n");
			return -1;
		}

	}
	struct cola *c;
	c=malloc(sizeof(struct cola));
	struct linea *l;
	l=malloc(sizeof(struct linea));
	l->contenido="AAAAAAAA";
	encolar(c,l);
	printf("%s\n",c->primero->contenido);
	descolar(c);
	//printf("%s\n",c->primero->contenido);		Lo has descolado
	tail(2);
	return 0;
}
