/*
ID: priyans8
LANG: C
TASK: beads
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
typedef enum{false,true} bool;

void strcut(char *str, size_t begin, size_t len)
{
    size_t l = strlen(str);

    if (len < 0) len = l - begin;
    if (begin + len > l) len = l - begin;
    memmove(str + begin, str + begin + len, l - len + 1);
}

size_t numbeads(char str[],size_t nbreak){
  size_t len = strlen((char*)str);
  char* ct;
  ct = strncpy(ct,str,nbreak);
   str = strcut(str,nbreak,len-nbreak);
   str = strncat(str,ct,nbreak);
   char t = str[0];
   size_t i=0,nlen=0;
   while (t == str[i]) {
     nlen++;
     i++;
   }
   t = str[len-1];
   i = len-1;
   while (t == str[len-1]) {
     nlen++;
     i--;
   }
   return nlen;
}

int main(void)
{

    FILE *fin, *fout;

    fin = fopen("beads.in", "r");
    fout = fopen("beads.out", "w");
    size_t n;
    fscanf(fin,"%d", &n);
    char str = str[n];
    fscanf(fin,"%s",str);
    size_t strl = strlen((char*)str);
    size_t max =0;
    for (size_t i = 0; i < strl; i++) {
      size_t temp;
      temp = numbeads(str,i);
      if (temp > max) {
        max = temp;
      }
    }
    /* print days count totals */
    fprintf(fout,"%d", max);
    exit (0);
}
