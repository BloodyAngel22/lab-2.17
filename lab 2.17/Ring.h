#pragma once
#include <iostream>
#include <time.h>

struct Element {
	int data;
	Element* prev = NULL,*next = NULL;
};

struct Ring {
	Element* current = NULL;
};

void pushNext(Ring& r, int data); void pushPrev(Ring& r, int data);
int pull(Ring& r);
void printRing(const Ring& r); void clear(Ring& r);
void Next(Ring& r); void Prev(Ring& r);
void cards(Ring& r); int random();