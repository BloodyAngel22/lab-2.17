#include "Ring.h"

/*По кругу выложены карточки с цифрами. Слева от карточек с
цифрами, кратными пяти, положили карту со случайной цифрой, а
саму карточку убрали. Действие выполнили некоторое количество
раз. Вывести на экран исходный и полученный набор карточек*/

Ring ring;

void LoopRing() {
	int switcher;
	while (true) {
		printf("Работа с Ring\n1 - Добавить элемент; 2 - Удалить элемент; 3 - прокрутить вперед; 4 - прокрутить назад; 5 - карточки кратные 5; 6 - очистка; 7 - Выход\n");
		scanf_s("%d", &switcher);
		int tmp;
		switch (switcher) {
		case 1:
			printf("Введите элемент: "); scanf_s("%d", &tmp);
			printf("Куда добавляем элемент?\n1 - next; 2 - prev; "); scanf_s("%d", &switcher);
			if (switcher == 1) {
				pushNext(ring, tmp);
			}
			if (switcher == 2) {
				pushPrev(ring, tmp);
			}
			break;
		case 2:
			tmp = pull(ring);
			printf("Удаление элемента %d\n", tmp);
			break;
		case 3:
			Next(ring);
			break;
		case 4:
			Prev(ring);
			break;
		case 5:
			cards(ring);
			break;
		case 6:
			clear(ring);
			break;
		case 7:
			clear(ring);
			exit(1);
			break;
		}
		printRing(ring);
	}
}

int main() {
	srand(time(NULL));
	system("chcp 1251");
	LoopRing();
}