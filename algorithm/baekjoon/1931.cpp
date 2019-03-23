#include <cstdio>
#include <algorithm>
using namespace std;


typedef struct meeting {
  int start;
  int fin;
} meeting;

meeting* meeting_arr[100000];
int total_meeting = 0;
int now_num = 0;

bool cmp_Edge(meeting* a, meeting* b) {
  return a->fin < b->fin;
}

bool cmp_Edge2(meeting* a, meeting* b) {
  return a->start < b->start;
}

int main() {  
  int t;
  scanf("%d", &t);

  for(int i=0; i<t; i++) {
    int start, end;
    scanf("%d %d", &start, &end);

    meeting_arr[i] = (meeting*)malloc(sizeof(meeting));
    meeting_arr[i]->start = start;
    meeting_arr[i]->fin = end;
  }

  for(int i=0; i<t; i++) {

    printf("%d to %d\n", meeting_arr[i]->start, meeting_arr[i]->fin);
    
  }

  sort(meeting_arr, meeting_arr + t, cmp_Edge);

  for(int i=0; i<t; i++){
    if(now_num <= meeting_arr[i]->start) {
      int j= i+1;
      while( (j<t) && (meeting_arr[i]->fin == meeting_arr[j]->fin)){
        j++;
      }
      sort(meeting_arr+i, meeting_arr +j, cmp_Edge2);

      now_num = meeting_arr[i]->fin;
      total_meeting++;
    }
  }

  printf("\n");
  for(int i=0; i<t; i++) {
        printf("%d to %d\n", meeting_arr[i]->start, meeting_arr[i]->fin);

  }


  printf("%d", total_meeting);


  return 0;
}