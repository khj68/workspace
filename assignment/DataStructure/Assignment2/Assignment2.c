#include <stdio.h>
#include <stdlib.h>

typedef struct point {
	int row;
	int col;
	int depth;
	struct point* next;
}point;

int row = 1, col = 1, haveAnswer = 0, warpCount = 0, findFirstWarp = 0;
point warpList[20], firstWarp;
int distance;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
char map[301][301] = { NULL, };
int visit[301][301] = { 0, };
point* head = NULL;
point* tail = NULL;
point start, end;

int isEmpty() { //List�� ����ִ��� Ȯ��
	if (head == NULL) {
		return 1;
	}
	else {
		return 0;
	}
}

void qPush(int r, int c, int d) { //queue�� ����� ���� push
	point* newPoint = (point*)malloc(sizeof(point));
	newPoint->row = r;
	newPoint->col = c;
	newPoint->depth = d;
	newPoint->next = NULL;
	if (isEmpty() == 1) {
		head = newPoint;
		tail = newPoint;
	}
	else {
		tail->next = newPoint;
		tail = newPoint;
	}
}

void sPush(int r, int c, int d) { //stack���� ����� ���� push
	point* newPoint = (point*)malloc(sizeof(point));
	newPoint->row = r;
	newPoint->col = c;
	newPoint->depth = d;
	if (isEmpty() == 1) {
		newPoint->next = NULL;
	}
	else {
		newPoint->next = head;
	}
	head = newPoint;
}

void pop() { //queue, stack�� ���� pop
	if (isEmpty() == 1) { //����ִٸ� �ȳ��� ��� �� ��ȯ
		printf("The list is empty!\n");
		return;
	}
	point* temp;
	temp = head->next;
	free(head);
	head = temp;
}

void bfs(int r, int c) { //���� �켱 Ž��
	int i;
	int tempDepth = head->depth;
	for (i = 0; i < 4; i++) { //�� �� �ִ��� ���� ������
		if (r + dx[i] < 1 || c + dy[i]<1 || r + dx[i] > row || c + dy[i] > col) {
			continue;
		}
		else if (map[r + dx[i]][c + dy[i]] == '*') {
			continue;
		}
		else if (visit[r + dx[i]][c + dy[i]] > 0) {
			continue;
		}
		//ť�� �ִ´�.
		if (map[r + dx[i]][c + dy[i]] == 'w') { //������ ��� ��� ������ ť�� �ִ´�
			if (findFirstWarp == 0) { //���� ó�� �̿��� ������ ���
				firstWarp.row = r + dx[i];
				firstWarp.col = c + dy[i];
				findFirstWarp = 1;
			}
			while (warpCount != 0) {
				qPush(warpList[warpCount - 1].row, warpList[warpCount - 1].col, tempDepth + 1);
				warpCount--;
				visit[warpList[warpCount - 1].row][warpList[warpCount - 1].col] = tempDepth + 1;
			}
		}
		else if (map[r + dx[i]][c + dy[i]] == 'e') { //end�� �����ϸ� ���� �ִٴ� ���� ��ǥ�� �˸�
			haveAnswer = 1;
			distance = tempDepth + 1;
		}
		else { //0�� ���� ť�� �ִ´�
			qPush(r + dx[i], c + dy[i], tempDepth + 1);
		}

		visit[r + dx[i]][c + dy[i]] = tempDepth + 1; //�湮üũ�� depth�� �̿��ؼ� �Ѵ�
	}
}

void bfs2(int r, int c, int depth) { //end���� ���� �Ųٷ� ���� ã�ư��� ����
	int i;

	for (i = 0; i < 4; i++) { //continue ���Ǽ���
		if (r + dx[i] < 1 || c + dy[i]<1 || r + dx[i] > row || c + dy[i] > col) {
			continue;
		}
		else if (map[r + dx[i]][c + dy[i]] == '*') {
			continue;
		}

		if (map[r + dx[i]][c + dy[i]] == 's') { //start�� ����
			haveAnswer = 1;
			sPush(r + dx[i], c + dy[i], depth - 1);
			return;
		}

		if (visit[r + dx[i]][c + dy[i]] == depth - 1) { //depth�� �ڱ⺸�� �ϳ� ���������θ� ����
			sPush(r + dx[i], c + dy[i], depth - 1);
			return;
		}

		if (i == 3) { //������ �������� �ÿ� �� ó�� ������ �̵�
			sPush(firstWarp.row, firstWarp.col, depth);
		}
	}
}

int main() {
	char space;

	FILE* fpRead = fopen("hw2_input.txt", "r");
	FILE* fpWrite = fopen("hw2_output.txt", "w");

	while (1) {
		col = 1;

		while (1) {

			map[row][col] = fgetc(fpRead);
			space = fgetc(fpRead); //���� ó��

			if (map[row][col] == 'w') { //������ ����
				warpList[warpCount].row = row;
				warpList[warpCount].col = col;
				warpCount++;
			}
			else if (map[row][col] == 's') { //������ ����
				start.row = row;
				start.col = col;
			}
			else if (map[row][col] == 'e') { //���� ����
				end.row = row;
				end.col = col;
			}

			if (space == 10 || space == EOF) { //�����̸� ���� row��
				break;
			}
			col++;
		}

		if (space == EOF) break; //�Է� ��ħ
		row++;
	}

	qPush(start.row, start.col, 0); //������ ���� ť�� �ִ´�
	visit[start.row][start.col] = 1; //������ �湮üũ

	while (head != NULL) { //ť�� �ƹ��͵� ���� �� ����
		bfs(head->row, head->col);
		pop();
		if (haveAnswer == 1) {
			break;
		}
	}

	if (haveAnswer == 0) { //���±��� �����ÿ� NULL �Է�
		fprintf(fpWrite, "NULL");
		fclose(fpRead);
		fclose(fpWrite);
		return 0;
	}

	fprintf(fpWrite, "%d\n", distance); //s���� �ɸ��� �Ÿ� �������

	while (head != NULL) { //queue ����
		pop();
	}
	haveAnswer = 0; //�� ��ǥ �ʱ�ȭ

	sPush(end.row, end.col, distance); //stack���ν� ����� ��
	while (1) {
		bfs2(head->row, head->col, head->depth);
		if (haveAnswer == 1) { //s�� �����ϸ� Ż��
			break;
		}
	}

	while (head != NULL) { //Linked List�� �̿��� stack ������� ���
		fprintf(fpWrite, "(%d,%d)", head->row, head->col);
		pop();
		if (head != NULL) {
			fprintf(fpWrite, ",");
		}
	}

	fclose(fpRead);
	fclose(fpWrite);
	return 0;
}