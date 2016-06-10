#ifndef PRAC1_H_INCLUDED		//avoids including the same header file twice in the same compilation
#define PRAC1_H_INCLUDED
	/*
	  Auxiliar methos
	*/
	struct listel{
		struct listel *next;
		char *content;
		int size;
	};
	struct linea{
		struct linea *next;
		char *contenido;
	};
	struct cola{
		struct linea *primero;
		struct linea *ultimo;
		int elementos;
	};
	int encolar(struct cola *queue, struct linea *nuevo);
	int descolar(struct cola *queue);
	int eliminarCola(struct cola *queue);
	int addInOrder(struct listel **list, char *content);
	int rmv(struct listel **listel, int position);
	int rmvList(struct listel *list);
	int compare(struct listel *list1,struct listel *list2); //return 1 if list1>2, 2 if list2>1 and 0 if list1=list2 (only fisrt element)
	
	/*
	  Library methods
	*/
	int head(int m);
	int tail(int p);
	int longlines(int r);
	void leerCola(struct cola *q);
#endif
