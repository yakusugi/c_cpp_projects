#include <stdio.h>

int main() {
   FILE *fp;
   char filename[100];
   char line[100];
   int linenumber;

   printf("Enter filename: ");
   scanf("%s", filename);

   printf("Enter line number: ");
   scanf("%d", &linenumber);

   fp = fopen(filename, "r");

   if (fp == NULL) {
      printf("Error opening file\n");
      return 1;
   }

   for (int i = 1; i <= linenumber; i++) {
      if (fgets(line, sizeof(line), fp) == NULL) {
         printf("Error reading file\n");
         return 1;
      }
      if (i == linenumber) {
         printf("%s", line);
      }
   }

   fclose(fp);
   return 0;
}
