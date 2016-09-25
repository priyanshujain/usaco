/*
ID: priyans8
LANG: C
TASK: ride
*/
#include <stdio.h>
#include<stdlib.h>
#include<string.h>

int charconv(char letter){
  int num;
  if (letter >= 'A' && letter <= 'Z'){
    num = letter - 'A'+1;
  }
  else{
    num =1;
  }
  return num;
}
int main () {
    FILE *fin  = fopen ("ride.in", "r");
    FILE *fout = fopen ("ride.out", "w");
    char name1[7],name2[7];
    fscanf(fin,"%s\n%s",name1,name2);
    int val1=1,val2=1;
    for (size_t i = 0; i < strlen(name1); i++) {
      val1 = val1*charconv(name1[i]);
    }
    for (size_t i = 0; i < strlen(name2); i++) {
      val2 = val2*charconv(name2[i]);
    }
    val1 = val1 % 47;
    val2 = val2 % 47;
    if (val1==val2) {
      fprintf(fout, "GO\n" );
    }
    else{
      fprintf(fout, "STAY\n");
    }

    exit (0);
}
