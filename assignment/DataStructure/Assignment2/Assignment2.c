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

int isEmpty() { //List가 비어있는지 확인
	if (head == NULL) {
		return 1;
	}
	else {
		return 0;
	}
}

void qPush(int r, int c, int d) { //queue로 사용할 때의 push
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

void sPush(int r, int c, int d) { //stack으로 사용할 때의 push
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

void pop() { //queue, stack일 때의 pop
	if (isEmpty() == 1) { //비어있다면 안내문 출력 후 반환
		printf("The list is empty!\n");
		return;
	}
	point* temp;
	temp = head->next;
	free(head);
	head = temp;
}

void bfs(int r, int c) { //넓이 우선 탐색
	int i;
	int tempDepth = head->depth;
	for (i = 0; i < 4; i++) { //갈 수 있는지 조건 따지기
		if (r + dx[i] < 1 || c + dy[i]<1 || r + dx[i] > row || c + dy[i] > col) {
			continue;
		}
		else if (map[r + dx[i]][c + dy[i]] == '*') {
			continue;
		}
		else if (visit[r + dx[i]][c + dy[i]] > 0) {
			continue;
		}
		//큐에 넣는다.
		if (map[r + dx[i]][c + dy[i]] == 'w') { //워프일 경우 모든 워프를 큐에 넣는다
			if (findFirstWarp == 0) { //가장 처음 이용한 워프를 기록
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
		else if (map[r + dx[i]][c + dy[i]] == 'e') { //end에 도달하면 답이 있다는 것을 지표로 알림
			haveAnswer = 1;
			distance = tempDepth + 1;
		}
		else { //0일 때에 큐에 넣는다
			qPush(r + dx[i], c + dy[i], tempDepth + 1);
		}

		visit[r + dx[i]][c + dy[i]] = tempDepth + 1; //방문체크는 depth를 이용해서 한다
	}
}

void bfs2(int r, int c, int depth) { //end에서 부터 거꾸로 길을 찾아가는 과정
	int i;

	for (i = 0; i < 4; i++) { //continue 조건설정
		if (r + dx[i] < 1 || c + dy[i]<1 || r + dx[i] > row || c + dy[i] > col) {
			continue;
		}
		else if (map[r + dx[i]][c + dy[i]] == '*') {
			continue;
		}

		if (map[r + dx[i]][c + dy[i]] == 's') { //start에 도달
			haveAnswer = 1;
			sPush(r + dx[i], c + dy[i], depth - 1);
			return;
		}

		if (visit[r + dx[i]][c + dy[i]] == depth - 1) { //depth가 자기보다 하나 작은것으로만 가기
			sPush(r + dx[i], c + dy[i], depth - 1);
			return;
		}

		if (i == 3) { //워프에 도달했을 시에 맨 처음 워프로 이동
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
			space = fgetc(fpRead); //띄어쓰기 처리

			if (map[row][col] == 'w') { //워프들 저장
				warpList[warpCount].row = row;
				warpList[warpCount].col = col;
				warpCount++;
			}
			else if (map[row][col] == 's') { //시작점 저장
				start.row = row;
				start.col = col;
			}
			else if (map[row][col] == 'e') { //끝점 저장
				end.row = row;
				end.col = col;
			}

			if (space == 10 || space == EOF) { //개행이면 다음 row로
				break;
			}
			col++;
		}

		if (space == EOF) break; //입력 마침
		row++;
	}

	qPush(start.row, start.col, 0); //시작점 먼저 큐에 넣는다
	visit[start.row][start.col] = 1; //시작점 방문체크

	while (head != NULL) { //큐에 아무것도 없을 때 까지
		bfs(head->row, head->col);
		pop();
		if (haveAnswer == 1) {
			break;
		}
	}

	if (haveAnswer == 0) { //가는길이 없을시에 NULL 입력
		fprintf(fpWrite, "NULL");
		fclose(fpRead);
		fclose(fpWrite);
		return 0;
	}

	fprintf(fpWrite, "%d\n", distance); //s까지 걸리는 거리 파일출력

	while (head != NULL) { //queue 정리
		pop();
	}
	haveAnswer = 0; //답 지표 초기화

	sPush(end.row, end.col, distance); //stack으로써 사용할 것
	while (1) {
		bfs2(head->row, head->col, head->depth);
		if (haveAnswer == 1) { //s에 도달하면 탈출
			break;
		}
	}

	while (head != NULL) { //Linked List를 이용해 stack 순서대로 출력
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