#ifndef list_H_INCLUDED		//avoids including the same header file twice in the same compilation
#define list_H_INCLUDED
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
#endif
