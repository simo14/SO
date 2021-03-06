#ifndef liststruc_H_INCLUDED		//avoids including the same header file twice in the same compilation

#define liststruc_H_INCLUDED

	struct listel{

		struct listel *next;

		char *content;

		int size;

	};

	int addInOrder(struct listel **list, char *content);

	int rmv(struct listel **listel, int position);

	int rmvList(struct listel *list);

	int compare(struct listel *list1,struct listel *list2); //return 1 if list1>2, 2 if list2>1 and 0 if list1=list2 (only fisrt element)

#endif
