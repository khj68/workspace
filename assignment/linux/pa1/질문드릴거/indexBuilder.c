/*-----------------------------------------------------------
 *
 * SSE2033: System Software Experiment 2 (Spring 2017)
 *
 * Skeleton code for PA#1
 * 
 * March 21, 2017.
 * CSLab, Sungkyunkwan University
 *
 * Student Id   :
 * Student Name :
 *
 *-----------------------------------------------------------
 */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#define BYTE_SIZE 512

#include <stdio.h>

int fdR, fdW;
int jangSum = 0, julSum = 0, wordCount = 0, listCount=0, julCount = 0, indexCount = 0;
int currentJang = 0;
int ans_i;
char ans[50];

typedef struct Tree{
	int jang;
	int jul;
	int location;
	struct Tree* next;
}Tree;

typedef struct Queue{
	Tree* first;
	Tree* last;
	int count;
}Queue;

typedef struct List{
	char word[23];
	struct List* next;
	int howMany;
	Queue *queue;
}List;

List *head;

void newQueue(List *list){
	list->queue = (Queue*)malloc(sizeof(Queue));
	list->queue->first = NULL;
	list->queue->last = NULL;
	list->queue->count = 0;
}

int empty(List *list){
	if(list->queue->first == NULL){
		return 1;
	}else{
		return 0;
	}
}

void push(List *temp, int jang, int jul, int location){
	Tree *new = (Tree*)malloc(sizeof(Tree));
	new->jang = jang;
	new->jul = jul;
	new->location = location;
	new->next = NULL;
	if(temp->queue->count == 0){
		temp->queue->first = new;
	}else{
		temp->queue->last->next=new;
	}
	temp->queue->last = new;
	temp->queue->count++;
}

void pop(List *list){
	Tree *now;
	// if(empty(queue))
	//   return;
	
	now = list->queue->first;
	list->queue->first = now->next;
	free(now);
	list->queue->count--;
}

int pass(char *buf,int i){
	while(buf[i] != '\n'){
		i++;
	}
	i+=2;
	return i;
}
void createList(char *word){
	int i=0;
	indexCount++;
	List *newList = (List *)malloc(sizeof(List));
	newList->next = head->next;
	newList->howMany = 1;
	head->next = newList;
	while(word[i] != '\0') // 이거 수정하고 있었음 10.05 .. 장절 위치 반환을 어케할지 생각하자.
	{
		if(word[i]<=90 && word[i] >= 65){
			word[i] += 32; // 대문자를 소문자로 변환
		}
		newList->word[i] = word[i];
		i++;
	}
	newQueue(newList);
}

int getNum(char * buf) {
	int colonCount = 0, i = 0, j = 0, numCount = 0, sum=0;
	char num[5];
	julSum=0;

	while(buf[i]==' '){
		i++;
	}
	if(!(buf[i]>=48 && buf[i]<=57)){
		i = pass(buf,i);
	}

	while (1) {
		if (buf[i] == ':') {
			colonCount++;
			i++;

			if (colonCount == 1) {
				for (j = 0; j < numCount; j++) {
					int ten = 1, k;
					for (k = numCount - (j + 1); k > 0; k--) {
						ten *= 10;
					}
					sum += (num[j] - '0') * ten;
				}
				currentJang = sum;
				numCount = 0;
				j = 0;
				sum = 0;
				continue;
			}

			if (colonCount == 2) {
				for (j = 0; j < numCount; j++) {
					int ten = 1, k;
					for (k = numCount - (j + 1); k > 0; k--) {
						ten *= 10;
					}
					julSum += (num[j] - '0') * ten;
				}
				julCount++;
				i++;
				break;
			}
		}
		num[j++] = buf[i++];
		numCount++;
	}

	return i;
}

int compare(char *a, char *b){
	int i;

	for(i=0; i<23;i++){
		if(a[i]>=65 && a[i] <= 90){
			a[i] += 32;
		}


		if(a[i]== NULL || a[i] == 32){
			if(b[i] != NULL && b[i] != 32){
				return 0;
			}
			continue;
		}
			

		if(a[i] != b[i]){
			return 0;
		}
		
	}
	return 1;
}

int getWord(char *buf, int i) {
	char temp[23] = {NULL, };
	int temp_i = 0, new = 1, index = 0, j=0;
	List *search;
	while (1) {
		if (buf[i] == '\n') {
			i++;
			break;
		}
        
		if ((buf[i] == ' ' && buf[i-1] !=' ') 
		|| (buf[i] == 46 || (buf[i]>=33 && buf[i]<=38) || (buf[i]>=40 && buf[i] <=44) 
		|| (buf[i] >=58 && buf[i]<=64))) {
			
			// if(temp[0] == ' '){
			// 	if(buf[i+1] != '\n'){
			// 		while(!((buf[i]>=65 && buf[i]<=90) || (buf[i] >=97 && buf[i] <= 122))){
			// 			index++;
			// 			i++;
			// 		}
			// 		temp_i = 0;
					
			// 		continue;
			// 	}
			// }
			wordCount++;
			new =1;

			// printf("temp는 %s\n", temp);
			if(buf[i+1]== '\n'){
				wordCount--;
			}
			//리스트 원소들과 비교하는 것 만들자
			search = head->next;
			while(search != NULL){
				if(temp[0] == NULL){
					new = 0;
 					break;
				}
				if(compare(temp, search->word) == 1){
					//자신의 장, 절, 위치를 반환하면서 while탈출
					new = 0;
					break;
				}


				search = search->next;
			}
			if(new == 1){
					createList(temp);
			}

			if(buf[i] == 46 || (buf[i]>=33 && buf[i]<=44) || (buf[i] >=58 && buf[i]<=64)){ //특수문자 처리
				if(buf[i+1] != '\n'){
					// while(buf[i]!=' '){
					// 	i++;
					// 	index++;
					// }
					wordCount--;
				}
			}
			//여기서 장 절 위치를 tree에 넣자
			if(search!=NULL) {
				search->howMany++;
				push(search, currentJang, julSum, index - temp_i);
			}else{
				push(head->next, currentJang,julSum, index - temp_i);
			}
			temp_i = 0;
			for(j=0; j< 23; j++){
				temp[j] = NULL;
			} //temp 초기화
		}else if(buf[i] != ' ' && buf[i] != NULL){
			temp[temp_i] = buf[i];
			temp_i++;
		}

		index++;
		i++;
	}
	wordCount++;

	return i;
}

int findFirst(char *buf){
	int i=4;
	while(1){
		if(buf[i] == '1'){
			break;
		}
		i++;
	}
	return i;
}

int digit(int a){
	int count=1, temp;
	temp = a;
	while((temp/=10) != 0){
		count++;
	}
	return count;
}

void final(int X, int sum){
	int i,count=0;
	for(i=0; i<X; i++){
		int j;
		for(j = X-1 -i; j>=0; j--){
			int ten=1, k;
			for(k=0; k<j; k++){
				ten *= 10;
			}
			if(count == X){
				break;
			}
			ans[ans_i++] = sum/ten + '0';
			sum %= ten;
			count++;
		}
	}
}

void writeTitle(char *name){
	int i = 0; 
	char buf[50];
	while(name[i] != '_'){
		buf[i] = name[i];
		i++;
	}
	buf[i++] = ':';
	buf[i] = ' ';
	write(fdW, buf, i+1);
}

void writeWord(List* list){
	int i = 0, j =0; 
	char buf[50] ={NULL, };
	while(list->word[i] != NULL){
		buf[i] = list->word[i];
		i++;
	}
	buf[i++] = ':';
	buf[i++] = ' ';
	final(digit(list->howMany), list->howMany);
	// printf("HOWMANY는 %d\n", list->howMany);
	ans_i = 0;
	do{
		buf[i] = ans[ans_i];
		i++;
		ans_i++;
	}while(ans[ans_i] != NULL);
	buf[i++] = ',';
	buf[i] = ' ';
	write(fdW, buf, i+1);
	
	for(i=0; i<50; i++){
		ans[i] = NULL;
	}
}

void writeIndex(List* list){
	int i;
	final(digit(list->queue->first->jang), list->queue->first->jang);
	ans[ans_i++] = ':';
	final(digit(list->queue->first->jul), list->queue->first->jul);
	ans[ans_i++] = ':';
	final(digit(list->queue->first->location), list->queue->first->location);
	ans[ans_i++] = ',';
	ans[ans_i] = ' ';

	if(list->queue->count == 1){
		ans_i--;
		ans[ans_i] = '\n';
	}
	// printf("ans는 %s", ans);
	write(fdW, ans, ans_i+1);
	
	for(i=0; i<25; i++){
		ans[i] = NULL;
	}
}
void indexBuilder(const char* inputFileNm, const char* indexFileNm)
{
	int nbytes,i;
	char *file_name = inputFileNm;
	/* Write your own C code */
	fdR = open(file_name, O_RDONLY);
	file_name = indexFileNm;
	fdW = open(file_name, O_WRONLY | O_CREAT, 0777); //index파일 생성

	writeTitle(file_name); // 제목만 작성

	char buf[BYTE_SIZE];
	read(fdR, buf, BYTE_SIZE-1);
	i = findFirst(buf);	
	lseek(fdR, (-BYTE_SIZE+1+i), SEEK_CUR);



	head = (List*)malloc(sizeof(List));
	head->next = NULL;

	while ((nbytes = read(fdR,buf, BYTE_SIZE-1)) > 0) {
		
		i = getNum(buf);
		i = getWord(buf, i);
		if(buf[i]=='\n'){
			break;
		}
		
		lseek(fdR, -nbytes + i, SEEK_CUR);
	}
	List* search = (List*)malloc(sizeof(List));
	search->next = head->next;
	search = search->next;
	
	ans_i =0 ;
	final(digit(currentJang), currentJang);
	ans[ans_i++] = ' ';
	final(digit(julCount), julCount);
	ans[ans_i++] = ' ';
	final(digit(indexCount), indexCount);
	ans[ans_i++] = ' ';
	final(digit(wordCount), wordCount);
	ans[ans_i] = '\n';

	write(fdW, ans, ans_i +1);

	for(i=0; i<35; i++){
		ans[i] = NULL;
	}


	while(search ->next != NULL){
		ans_i = 0;
		writeWord(search);
		while(search->queue->first != NULL){
			ans_i = 0;
			writeIndex(search);
			pop(search);
		}
		search = search->next;
	}

	
	close(fdR);
	close(fdW);
}
