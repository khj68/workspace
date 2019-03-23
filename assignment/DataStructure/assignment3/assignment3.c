#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
  int key;
  struct Node *left;
  struct Node *right;
} Node;

typedef struct inputNode{
  int iKey;
  int iChild;
  int safe;
} inputNode;

typedef struct isRoot{
  int rKey;
  int isRoot;
}isRoot;

Node* makeNewNode(int key){
  Node* new = malloc(sizeof(Node));
  new->key = key;
  new->left = NULL;
  new->right = NULL;
  return new;
}

void makeTree(Node* temp, inputNode* firstTreeInput, int firstNodeNum){
  int i,j;
  for(i=0; i<firstNodeNum-1; i++){
    for(j=0; j<firstNodeNum-1; j++){
      if(firstTreeInput[j].iKey == temp->key){
        if(firstTreeInput[j].iChild > temp->key){
          temp->right = makeNewNode(firstTreeInput[j].iChild);
        }else{
          temp->left = makeNewNode(firstTreeInput[j].iChild);
        }
      }
    }
    if(temp->left != NULL) makeTree(temp->left, firstTreeInput, firstNodeNum);
    if(temp->right != NULL) makeTree(temp->right, firstTreeInput, firstNodeNum);
  }
}

// void pre(Node* temp){
//   printf("%d 방문!\n", temp->key);
//   if(temp->left != NULL) pre(temp->left);
//   if(temp->right != NULL) pre(temp->right);
// }

void fPre(FILE* fp, Node* temp){
  if(temp->left != NULL) fprintf(fp, "%d %d\n", temp->key, temp->left->key);
  if(temp->right != NULL) fprintf(fp, "%d %d\n", temp->key, temp->right->key);
  if(temp->left != NULL) fPre(fp, temp->left);
  if(temp->right != NULL) fPre(fp, temp->right);
}

void mergeTree (Node* firstRoot, Node* secondRoot){
  Node* temp = firstRoot;
  int isRight = 0;
  while(1){
    if(temp->key > secondRoot->key){
      isRight = 0;
      if(temp->left == NULL) break;
      temp = temp->left;
    }else{
      isRight = 1;
      if(temp->right == NULL) break;
      temp = temp->right;
    } 
  }
  
  if(isRight == 1){
    temp->right = makeNewNode(secondRoot->key);
  }else{
    temp->left = makeNewNode(secondRoot->key);
  }

  if(secondRoot->left != NULL){
    mergeTree(firstRoot, secondRoot->left);
  }

  if(secondRoot->right != NULL){
    mergeTree(firstRoot, secondRoot->right);
  }
}

int main(){
  int firstNodeNum, secondNodeNum;
  int firstIndex=0, secondIndex=0;
  int key, child;
  int new=0, delete=0, skip=0;
  int something;
  int i, j;
  FILE *fp = fopen("hw3_input.txt", "r");
  FILE *outFp = fopen("hw3_output.txt", "w+");

  fscanf(fp, "%d", &firstNodeNum);

  inputNode* firstTreeInput = malloc(sizeof(Node)*(firstNodeNum-1));
  isRoot* findFirstRoot = malloc(sizeof(isRoot)*firstNodeNum-1);
  Node *firstRoot = NULL;

  for (i = 0; i < firstNodeNum-1; i++){
    fscanf(fp,"%d", &firstTreeInput[i].iKey);
    fscanf(fp,"%d", &firstTreeInput[i].iChild);
    firstTreeInput[i].safe = 0;
    if(i==0){
      findFirstRoot[i].rKey = firstTreeInput[i].iKey;
      findFirstRoot[i].isRoot = 0;
      firstIndex++;
    }else{
      int isIn = 0;
      for(j=0; j< firstIndex; j++){
        if(findFirstRoot[j].rKey == firstTreeInput[i].iKey){
          isIn = 1;
          break;
        }
      }

      if(isIn == 0){
        findFirstRoot[firstIndex].rKey = firstTreeInput[i].iKey;
        findFirstRoot[firstIndex].isRoot = 0;

        firstIndex++;
      }
    }
  }

  for(i=0; i<firstIndex; i++){
    for(j=0; j<firstNodeNum-1; j++){
      if(findFirstRoot[i].rKey == firstTreeInput[j].iChild){
        findFirstRoot[i].isRoot = 1;
        break;
      }
    }
  }

  for(i=0; i<firstIndex; i++){
    if(findFirstRoot[i].isRoot == 0){
      // printf("root는 %d이다.\n", findFirstRoot[i].rKey);
      firstRoot = makeNewNode(findFirstRoot[i].rKey);
      fprintf(outFp, "%d\n", findFirstRoot[i].rKey);
      break;
    }
  }

  Node* temp = firstRoot;
  makeTree(temp, firstTreeInput, firstNodeNum);
  // pre(firstRoot);

  fscanf(fp, "%d", &secondNodeNum);

  inputNode* secondTreeInput = malloc(sizeof(Node)*(secondNodeNum-1));
  isRoot* findSecondRoot = malloc(sizeof(isRoot)*secondNodeNum-1);
  Node *secondRoot = NULL;

  for (i = 0; i < secondNodeNum-1; i++){
    fscanf(fp,"%d", &secondTreeInput[i].iKey);
    fscanf(fp,"%d", &secondTreeInput[i].iChild);
    secondTreeInput[i].safe = 0;
    if(i==0){
      findSecondRoot[i].rKey = secondTreeInput[i].iKey;
      findSecondRoot[i].isRoot = 0;
      secondIndex++;
    }else{
      int isIn = 0;
      for(j=0; j< secondIndex; j++){
        if(findSecondRoot[j].rKey == secondTreeInput[i].iKey){
          isIn = 1;
          break;
        }
      }

      if(isIn == 0){
        findSecondRoot[secondIndex].rKey = secondTreeInput[i].iKey;
        findSecondRoot[secondIndex].isRoot = 0;
        secondIndex++;
      }
    }
  }

  for(i=0; i<secondIndex; i++){
    for(j=0; j<secondNodeNum-1; j++){
      if(findSecondRoot[i].rKey == secondTreeInput[j].iChild){
        findSecondRoot[i].isRoot = 1;
        break;
      }
    }
  }

  for(i=0; i<secondIndex; i++){
    if(findSecondRoot[i].isRoot == 0){
      // printf("root는 %d이다.", findSecondRoot[i].rKey);
      secondRoot = makeNewNode(findSecondRoot[i].rKey);
      break;
    }
  }

  temp = secondRoot;
  makeTree(temp, secondTreeInput, secondNodeNum);
  // pre(secondRoot);
  
  // printf("\n\nmerge 하였다!\n\n");
  mergeTree(firstRoot, secondRoot);

  // pre(firstRoot);
  fPre(outFp, firstRoot);

  fseek(outFp, 0, SEEK_SET);
  fscanf(outFp, "%d", &something);
  
  for(i=0; i<firstNodeNum + secondNodeNum - 1; i++){
    skip = 0;
    fscanf(outFp, "%d %d", &key, &child);
    for (j = 0; j < firstNodeNum-1; j++){
      if(key == firstTreeInput[j].iKey && child == firstTreeInput[j].iChild){
        firstTreeInput[j].safe = 1;
        skip = 1;
        break;
      }
    }

    if(skip == 1) continue;

    for(j=0; j< secondNodeNum-1; j++){
      if(key == secondTreeInput[j].iKey && child == secondTreeInput[j].iChild){
        secondTreeInput[j].safe = 1;
        skip = 1;
        break;
      }
    }

    if(skip == 0) new++;
  }

  for(i=0; i < firstNodeNum-1; i++){
    if(firstTreeInput[i].safe == 0) delete++;
  }
  
  for(i=0; i< secondNodeNum-1; i++){
    if(secondTreeInput[i].safe == 0) delete++;
  }

  fseek(outFp, 0, SEEK_END);
  fprintf(outFp, "%d\n%d", new, delete);
  
  fclose(fp);
  return 0;
}