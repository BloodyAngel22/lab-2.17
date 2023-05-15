#include "Ring.h"

/*�� ����� �������� �������� � �������. ����� �� �������� �
�������, �������� ����, �������� ����� �� ��������� ������, �
���� �������� ������. �������� ��������� ��������� ����������
���. ������� �� ����� �������� � ���������� ����� ��������*/

Ring ring;

void LoopRing() {
	int switcher;
	while (true) {
		printf("������ � Ring\n1 - �������� �������; 2 - ������� �������; 3 - ���������� ������; 4 - ���������� �����; 5 - �������� ������� 5; 6 - �������; 7 - �����\n");
		scanf_s("%d", &switcher);
		int tmp;
		switch (switcher) {
		case 1:
			printf("������� �������: "); scanf_s("%d", &tmp);
			printf("���� ��������� �������?\n1 - next; 2 - prev; "); scanf_s("%d", &switcher);
			if (switcher == 1) {
				pushNext(ring, tmp);
			}
			if (switcher == 2) {
				pushPrev(ring, tmp);
			}
			break;
		case 2:
			tmp = pull(ring);
			printf("�������� �������� %d\n", tmp);
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