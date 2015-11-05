#include <stdio.h>
#include <stdlib.h>
#include "prac1.h"

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

int tail(int m) {
	char buff[1024];
	struct cola *c;
	c=malloc(sizeof(struct cola));
	struct linea *l;
	l=malloc(sizeof(struct linea));
	while(fgets(buf, sizeof buf, stdin) != NULL){
		l->contenido=buf;
	}
}
               
