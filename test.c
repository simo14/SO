#include "libreria.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
int main (int argc, char *argv[]) {
	
	if(argc>2){
		if(!strcmp(argv[1],"head")) {
			if(head(atoi(argv[2]))!=0){
				printf("Hubo un error\n");
				return -1;
			}
		} else if(!strcmp(argv[1], "tail")) {
			if(tail(atoi(argv[2]))!=0){
				printf("Hubo un error\n");
				return -1;
			}
		}
		else if(!strcmp(argv[1], "longlines")) {
			if(longlines(atoi(argv[2]))!=0){
				printf("Hubo un error\n");
				return -1;
			}
		}

	}
	return 0;
}
