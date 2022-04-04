#include <stdio.h>
#include "libft_proj/libft.h"

size_t    count_words(char const *s, char c);

 int main()
 {
      char *s1 = "";
      printf("test: %d\n", count_words(s1,'-') == 0);
      // printf("output: %zu\n\n", count_words(s1,'-'));
      char *s2 = "-";
      printf("test: %d\n", count_words(s2,'-') == 0);
      // printf("output: %zu\n\n", count_words(s2,'-'));
      char *s3 = "a";
      printf("test: %d\n", count_words(s3,'-') == 1);
      // printf("output: %zu\n\n", count_words(s3,'-'));
      char *s4 = "-a";
      printf("test: %d\n", count_words(s4,'-') == 1);
      // printf("output: %zu\n\n", count_words(s4,'-'));
      char *s5 = "a-";
      printf("test: %d\n", count_words(s5,'-') == 1);
      // printf("output: %zu\n\n", count_words(s5,'-'));
     
      char *s6 = "-a-";
      printf("test: %d\n", count_words(s6,'-') == 1);
      // printf("output: %zu\n\n", count_words(s6,'-'));
      char *s7 = "a-a";
      printf("test: %d\n", count_words(s7,'-') == 2);
      // printf("output: %zu\n\n", count_words(s7,'-'));
      char *s8 = "a-a-";
      printf("test: %d\n", count_words(s8,'-') == 2);
      // printf("output: %zu\n\n", count_words(s8,'-'));
      char *s9 = "-a-a";
      printf("test: %d\n", count_words(s9,'-') == 2);
      // printf("output: %zu\n\n", count_words(s9,'-'));
      char *s10 = "-a-a-";
      printf("test: %d\n", count_words(s10,'-') == 2);
      // printf("output: %zu\n\n", count_words(s10,'-'));
      char *s11 = "a-a-a";
      printf("test: %d\n", count_words(s11,'-') == 3);
      // printf("output: %zu\n\n", count_words(s11,'-'));
     
      char *s12 = "--";
      printf("test: %d\n", count_words(s12,'-') == 0);
      // printf("output: %zu\n\n", count_words(s12,'-'));
     
      char *s13 = "aaa";
      printf("test: %d\n", count_words(s13,'-') == 1);
      // printf("output: %zu\n\n", count_words(s13,'-'));
      char *s14 = "---aaa";
      printf("test: %d\n", count_words(s14,'-') == 1);
      // printf("output: %zu\n\n", count_words(s14,'-'));
      char *s15 = "aaa---";
      printf("test: %d\n", count_words(s15,'-') == 1);
      // printf("output: %zu\n\n", count_words(s15,'-'));
     
      char *s16 = "---aaa---";
      printf("test: %d\n", count_words(s16,'-') == 1);
      // printf("output: %zu\n\n", count_words(s16,'-'));
      char *s17 = "aaa---aaa";
      printf("test: %d\n", count_words(s17,'-') == 2);
      // printf("output: %zu\n\n", count_words(s17,'-'));
      char *s18 = "aaa---aaa---";
      printf("test: %d\n", count_words(s18,'-') == 2);
      // printf("output: %zu\n\n", count_words(s18,'-'));
      char *s19 = "---aaa---aaa";
      printf("test: %d\n", count_words(s19,'-') == 2);
      // printf("output: %zu\n\n", count_words(s19,'-'));
      char *s20 = "---aaa---aaa---";
      printf("test: %d\n", count_words(s20,'-') == 2);
      // printf("output: %zu\n\n", count_words(s20,'-'));
      char *s21 = "aaa---aaa---aaa";
      printf("test: %d\n", count_words(s21,'-') == 3);
      // printf("output: %zu\n\n", count_words(s21,'-'));
 }

