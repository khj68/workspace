#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Node{
  char word[30];
  char capitalWord[30];
  int num;
  int wordSize;
  struct Node* next;
}Node;

int compare(char *c, char *b, int n, int m){ //두 문자를 비교하는 것
	int i;
  char *a = malloc(sizeof(char)*(n+1));
  strncpy(a,c,n);

	for(i=0; i<n;i++){ //대문자는 소문자로 변형
		if(a[i]>=65 && a[i] <= 90){
			a[i] += 32;
		}
  }

  for(i=0; i<m-n+1; i++){ //단어 중간에 존재할 경우까지 고려
    if(b[i] == a[0]){
      if(strncmp(a, &b[i], n) == 0){
        free(a);
        return 0;
      }
    }
  }

  free(a);
	return 1;
}

void sort(Node** arr, int first, int last){ //빈도 기준으로 퀵정렬
  int l = first, r = last;
  Node* temp;
  int pivot = arr[(first+last)/2]->num;

  while(l <= r){
    while(arr[l]->num > pivot) l++;
    while(arr[r]->num < pivot) r--;

    if(l<=r){
      if(l!=r){
        temp = arr[l];
        arr[l] = arr[r];
        arr[r] = temp;
      }
      l++; r--;
    }
  }

  if(first<r) sort(arr,first,r);
  if(l<last) sort(arr,l, last);
}

void alSort(Node** arr, int first, int last){ //아스키코드 기준으로 정렬
  int l = first, r = last;
  Node* temp;
  char pivot = arr[(first+last)/2]->capitalWord[0];

  while(l <= r){
    while(arr[l]->capitalWord[0] < pivot) {
      l++;
    }
    while(arr[r]->capitalWord[0] > pivot) {
      r--;
    }

    if(l<=r){
      if(l!=r){
        temp = arr[l];
        arr[l] = arr[r];
        arr[r] = temp;
      }
      l++; r--;
    }
  }

  if(first<r) alSort(arr,first,r);
  if(l<last) alSort(arr,l, last);
}



int main(){

  char trash[10];
  int i,j, dictNum, nodeNum = 0;
  int alFirst = 0, alLast;
  int desFirst = 0, desLast;
  int count = 1;


  Node* head = NULL;

  FILE* dict = fopen("dict.txt", "r");
  FILE* input = fopen("hw4_input.txt", "r");
  FILE* output = fopen("hw4_output.txt", "w");

  while(1){
    char buf[30] = {0, };
    int isEnd = 0;
      for(i = 0; i< 30; i++){

        buf[i] = fgetc(dict);
        
        if(buf[i] == 10 || buf[i] == EOF){
          if(buf[i] == EOF) isEnd = 1;
          buf[i] = 0;
          break;
        }
      }

      nodeNum++;
      Node* newNode = malloc(sizeof(Node));
      strcpy(newNode->word, buf);
      newNode->num = 0;
      newNode->wordSize = i;
      memset(newNode->capitalWord, 0, 30);

      if(head != NULL){
        newNode->next = head;
        head = newNode;
      }else{
        newNode->next = NULL;
        head = newNode;
      }

      if(isEnd == 1) break;
  }

  Node** arr = malloc(sizeof(Node*)*nodeNum);

  fscanf(input, "%d", &dictNum);
  fgets(trash, sizeof(trash), input);
  fgets(trash, sizeof(trash), input);

  while(1){
      char buf[30] = {0, };
      int isEnd = 0;
      for(i = 0; i< 30; i++){
        
        buf[i] = fgetc(input);
        
        if(buf[i]>=65 && buf[i]<=90){
          buf[i] += 32;
        }
        
        if(buf[i] == ' ' || buf[i] == EOF){
          if(buf[i] == EOF) isEnd = 1;
          buf[i] = 0;
          break;
        }
      }

      Node* search = head;

      while(search != NULL){
        if(compare(search->word, buf, search->wordSize, i) == 0){
          search->num++;
        }
        search = search->next;
      }

      if(isEnd == 1) break;
  }

  Node* search = head;
  i = nodeNum;
  while(search != NULL){
    arr[i-1] = search;
    i--;
    search = search->next;
  }

  sort(arr, 0, nodeNum -1); //단어 빈도수대로 정렬

  for(i=0; i<nodeNum; i++){ //소문자를 대문자로 변경
    for(j=0; j<arr[i]->wordSize; j++){
      if(arr[i]->word[j] >= 97 && arr[i]->word[j] <= 122){
        arr[i]->capitalWord[j] = arr[i]->word[j] - 32;
      }else{
        arr[i]->capitalWord[j] = arr[i]->word[j];
      }
    }
  }

  for(i=0; i<nodeNum-1; i++){ //아스키 코드에 대한 정렬
    if(arr[i]->num != arr[i+1]->num){
      alLast = i;
      if(alLast != alFirst) alSort(arr, alFirst, alLast);
      alFirst = i+1;
    }
  }


  for(i=0; i<nodeNum-1; i++){ //같은 문자에 대한 정렬
    j=0;
    if(arr[i]->capitalWord[j] == arr[i+1]->capitalWord[j]){
      j++;
      while(arr[i]->capitalWord[j] == arr[i+1]->capitalWord[j]) j++;
      if(arr[i]->capitalWord[j] > arr[i+1]->capitalWord[j]){
        Node* temp = arr[i];
        arr[i] = arr[i+1];
        arr[i+1] = temp;
        i-=2;
      }
    }
  }



  for(i=0; i<nodeNum; i++){
    if(arr[i]->num == 0) break;
    fprintf(output, "%s %d\n", arr[i]->word, arr[i]->num);
    count++;
    if(count > dictNum && i+1 <nodeNum && (arr[i]->num != arr[i+1]->num)) break;
  }


  fclose(dict);
  fclose(input);
  fclose(output);
  
  return 0;
}
