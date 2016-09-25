/*
ID: priyans8
LANG: C
TASK: gift1
*/
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
char member[10][14];
int NP=0,amount=0,num=0;


void assign(char name[14],int amount,int money[10]) {
  for (size_t i = 0; i < NP; i++) {
    if (strcmp(name,member[i])==0) {
      money[i]+=amount;
    }
  }
}
int main () {
    FILE *fin  = fopen ("gift1.in", "r");
    FILE *fout = fopen ("gift1.out", "w");
    int imoney[10]={0},fmoney[10]={};
    char name[14];

    fscanf(fin,"%d",&NP);

    for (size_t i = 0; i < NP; i++) {
      fscanf(fin,"%14s",member[i]);
    }
    for (size_t i = 0; i < NP; i++) {
      fscanf(fin,"%14s",name);
      fscanf(fin,"%d %d",&amount,&num);

      if (num==0) {
        continue;
      }
      else{
        if (amount==0) {
          for (size_t j = 0; j < num; j++) {
            fscanf(fin,"%14s",name);
           }
        }
        else{
          assign(name,amount,imoney);
          assign(name,amount,fmoney);

          assign(name,(amount%num)-amount,fmoney);

          for (size_t j = 0; j< num; j++) {
            fscanf(fin,"%14s",name);
            assign(name,amount/num,fmoney);
          }
        }

      }

    }
    for (size_t i = 0; i < NP; i++) {
      fprintf(fout, "%s %d\n",member[i],fmoney[i]-imoney[i] );
    }
    exit (0);
}
