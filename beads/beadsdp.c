/*
O(n) solution:

Dynamic Programming is good method for solving this problem in O(N).
If we consider two copies of the string we easy transform cyclic
configuration of the necklace to linear. Now we can compute for each
 breaking point how many beads of the same color can be collected on
 the left and on the right from the breaking point. I show how we can
 compute it only for the left side. For right side it is analogical.
 Let r[p] and b[p] be the number of red / blue beads that can be collected,
  when necklace is broken in point p. If we know this and color of next
   bead (c) we can compute r[p+1] and b[p+1].
 r[0] = p[0] = 0
 If c = 'r' then r[p+1] = r[p] + 1 and b[p+1] = 0
        because the length of the blue beads is 0.
 if c = 'b' then b[p+1] = b[p] + 1 and r[p+1] = 0
 if c = 'w' then both length of the red and length of blue beads
             can be longer.
so r[p+1] = r[p]+1 and b[p+1] = b[p] + 1.
The number of beads that can be collected in breaking point p
 is then max(left[r[p]], left[b[p]]) + max(right[r[p]], right[b[p]]).
 And the maximum from this value is answer for the problem.
 
*/

#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

FILE *in,*out;

int main () {
   in = fopen("beads.in", "r");
   out = fopen ("beads.out", "w");

   int n;
   char tmp[400], s[800];
   fscanf(in, "%d %s", &n, tmp);

   strcpy(s, tmp);
   strcat(s, tmp);

   int left[800][2], right[800][2];
   left[0][0] = left[0][1] = 0;

   for (int i=1; i<= 2 * n; i++){
       if (s[i - 1] == 'r'){
           left[i][0] = left[i - 1][0] + 1;
           left[i][1] = 0;
       } else if (s[i - 1] == 'b'){
           left[i][1] = left[i - 1][1] + 1;
           left[i][0] = 0;
       } else {
           left[i][0] = left[i - 1][0] + 1;
           left[i][1] = left[i - 1][1] + 1;
       }
     }

   right[2 * n][0] = right[2 * n][1] = 0;
   for (int i=2 * n - 1; i >= 0; i--){
       if (s[i] == 'r'){
           right[i][0] = right[i + 1][0] + 1;
           right[i][1] = 0;
       } else if (s[i] == 'b'){
           right[i][1] = right[i + 1][1] + 1;
           right[i][0] = 0;
       } else {
           right[i][0] = right[i + 1][0] + 1;
           right[i][1] = right[i + 1][1] + 1;
       }
   }

   int m = 0;
   for (int i=0; i<2 * n; i++)
       m = max(m, max(left[i][0], left[i][1]) + max(right[i][0], right[i][1]));
   m = min(m, n);
   fprintf(out, "%d\n", m);
   fclose(in); fclose(out);
   return 0;
}
