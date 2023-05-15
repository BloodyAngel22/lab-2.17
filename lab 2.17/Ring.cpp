#include "Ring.h"

void pushNext(Ring& r, int data) {
	Element* e = (Element*)malloc(sizeof(Element));
	e->data = data;
	
	if (r.current == NULL) {
		r.current = e;
		e->next = e->prev = e;
	}
	else {
		e->next = r.current->next;
		e->prev= r.current;
		r.current->next->prev = e;
		r.current->next = e;
	}
}

void pushPrev(Ring& r, int data) {
	Element* e = (Element*)malloc(sizeof(Element));
	e->data = data;

	if (r.current == NULL) {
		r.current = e;
		e->next = e->prev = e;
	}
	else {
		e->next = r.current;
		e->prev = r.current->prev;
		r.current->prev->next = e;
		r.current->prev = e;
	}
}

int pull(Ring& r) {
	if (r.current == NULL) return 0;

	int d = r.current->data;
	Element* e = r.current;

	if (r.current->next == r.current) {
		r.current = NULL;
	}
	else {
		r.current->prev->next = r.current->next;
		r.current->next->prev = r.current->prev;
		r.current = r.current->next;
	}
	free(e);
	return d;
}

void clear(Ring& r) {
	if (r.current == NULL) return;

	while (r.current != NULL) {
		Element* e = r.current;

		if (r.current->next == r.current) {
			r.current = NULL;
		}
		else {
			r.current->prev->next = r.current->next;
			r.current->next->prev = r.current->prev;
			r.current = r.current->next;
		}
		free(e);
	}
}

void printRing(const Ring& r) {
	if (r.current == NULL) return;

	printf("%d", r.current->data);
	for (Element* cur = r.current->next; cur != r.current; cur = cur->next)
		printf(" <-> %d", cur->data);
	printf("\n");
}

void Next(Ring& r) {
	if (r.current == NULL) return;

	r.current = r.current->next;
}

void Prev(Ring& r) {
	if (r.current == NULL) return;

	r.current = r.current->prev;
}

void cards(Ring& r) {
	if (r.current == NULL) return;

		//Добавление карты, если число кратно 5
	if (r.current->data % 5 == 0) {
		Element* tmp = (Element*)malloc(sizeof(Element));
		tmp->data = random();
		tmp->next = r.current;
		tmp->prev = r.current->prev;
		r.current->prev->next = tmp;
		r.current->prev = tmp;
	}
	for (Element* cur = r.current->next; cur != r.current; cur = cur->next) {
		if (cur->data % 5 == 0) {
			Element* tmp = (Element*)malloc(sizeof(Element));
			tmp->data = random();
			tmp->next = cur;
			tmp->prev = cur->prev;
			cur->prev->next = tmp;
			cur->prev = tmp;
		}
	}
	//Вывод эдементов
	printf("%d", r.current->data);
	for (Element* cur = r.current->next; cur != r.current; cur = cur->next)
		printf(" <-> %d", cur->data);
	printf("\n");
	system("pause");
	//Удаление элементов кратных 5
	if (r.current->data % 5 == 0) {
		if (r.current->next == r.current) {
			r.current = NULL;
		}
		else {
			r.current->prev->next = r.current->next;
			r.current->next->prev = r.current->prev;
			r.current = r.current->next;
		}
	}
	for (Element* cur = r.current->next; cur != r.current; cur = cur->next) {
		if (cur->data % 5 == 0) {
			cur->prev->next = cur->next;
			cur->next->prev = cur->prev;
			cur = cur->next;
		}
	}
	//Вывод эдементов
	printf("%d", r.current->data);
	for (Element* cur = r.current->next; cur != r.current; cur = cur->next)
		printf(" <-> %d", cur->data);
	printf("\n");
	system("pause");
}

int random() {
	return rand() % 30;
}