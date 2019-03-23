#include <stdio.h>
#include <stdlib.h>
#define BYTE_SIZE 1024

int n, i, j, num = 0, count;
int operCount=0;
int **A;
int **B;
char buf[BYTE_SIZE];
char oper;
int **ans;
int **result;



void DorS(int **ans, FILE *fp2) {
	(operCount == 0) ? operCount ++ : fprintf(fp2, "$\n");
	count = 0;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (ans[i][j] != 0)
				count++;
		}
	}
	
	if (count > n*n / 3) {
		fprintf(fp2, "%c\n", 'D');
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
                if(j == n) fprintf(fp2,"%d", ans[i][j]);
				else fprintf(fp2, "%d ", ans[i][j]);
			}
			fprintf(fp2, "\n");
		}
	}

	else {
		fprintf(fp2, "%c\n", 'S');
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				if (ans[i][j] != 0) {
					fprintf(fp2, "%d %d %d\n", i + 1, j + 1, ans[i][j]);
				}
			}
		}
	}
}

int **AorB(char c) {
	if (c == 'A')
		return A;
	else
		return B;
}

int **mul(int **first, int **second) {
	int k,sum;
	
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			sum = 0;
			for (k = 0; k < n; k++) {
				sum += first[i][k] * second[k][j];
			}
			result[i][j] = sum;
		}
	}
	return result;
}

int **add(int **first, int **second) {
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			result[i][j] = first[i][j] + second[i][j];
		}
	}
	return result;
}

int **trans(int **first) {
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			result[j][i] = first[i][j];
		}
	}

	return result;
}



void copyArr(int **to, int **from) {
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			to[i][j] = from[i][j];
		}
	}
}

int main() {
	

	FILE *fp1 = fopen("hw1_input.txt", "r");
	FILE *fp2 = fopen("hw1_output.txt", "w");

	if (fp1 == NULL) {
		puts("error");
		exit(-1);
	}

	fread(buf, sizeof(char), 1, fp1);
	n = (int)buf[0] -'0';

	A = malloc(sizeof(int *)*n);
	B = malloc(sizeof(int *)*n);
	ans = malloc(sizeof(int *)*n);
	result = malloc(sizeof(int*)*n);
	

	for (i = 0; i < n; i++) {
		A[i] = malloc(sizeof(int)*n);
		B[i] = malloc(sizeof(int)*n);
		ans[i] = malloc(sizeof(int)*n);
		result[i] = malloc(sizeof(int)*n);
	}
	
	fseek(fp1, 3, SEEK_CUR);

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			fscanf(fp1, "%d", &A[i][j]);
		}
	}

	fseek(fp1, 3, SEEK_CUR);

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			fscanf(fp1, "%d", &B[i][j]);
		}
	}

	fseek(fp1, 3, SEEK_CUR);
	fgets(buf, BYTE_SIZE, fp1);	
	ans = AorB(buf[num++]);
	

	while (buf[num] != '\0') {
		oper = buf[num++];

		switch (oper) {
		case '+' :
			copyArr(ans, add(ans, AorB(buf[num++])));
			DorS(ans,fp2);
			break;
		case '*' :
			copyArr(ans, mul(ans, AorB(buf[num++])));
			DorS(ans,fp2);
			break;
		case '\'' :
			copyArr(ans, trans(ans));
			DorS(ans,fp2);
			break;
		}

	}
	
	fclose(fp1);
	fclose(fp2);
	
	return 0;
}
