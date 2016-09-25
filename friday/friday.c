/*
ID: priyans8
LANG: C
TASK: friday
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
typedef enum{false,true} bool;


int wdays[7]={0};
int month[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
int nextday(int year,int day){
  bool leap=false;
  if (year%100 == 0) {
    if (year%400 == 0) {
      leap = true;
    }
  }else{
    if (year%4 == 0) {
      leap = true;
    }
  }
  if (leap) {
    int val=-1;
    for (size_t i = 0; i < 12; i++) {
      if (i!=1) {
           val = (day+12)%7;
           wdays[val]++;
           day = (day+month[i])%7;
         }else{
           val = (day+12)%7;
           wdays[val]++;
           day = (day+month[i]+1)%7;
         }
      }
    }else{
      for (size_t i = 0; i < 12; i++) {
             int val = (day+12)%7;
             wdays[val]++;
             day = (day+month[i])%7;
        }
    }
    return day;
  }

int main(void)
{

    FILE *fin, *fout;
    int day=2, n;

    fin = fopen("friday.in", "r");
    fout = fopen("friday.out", "w");

    fscanf(fin,"%d", &n);
    for (size_t i = 1900; i < 1900+n; i++) {
      day = nextday(i,day);
    }

    /* print days count totals */
    for(int i=0; i< 6; i++)
          fprintf(fout,"%d ", wdays[i]);
    fprintf(fout,"%d\n", wdays[6]);
    exit (0);
}
