/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft_test.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tnuyten <tnuyten@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/11 14:09:57 by tnuyten       #+#    #+#                 */
/*   Updated: 2021/10/12 18:29:07 by tnuyten       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

int	main(void)
{
	printf("is_alpha test: \n");
	printf("%d\n", ft_isalpha('a') == 1);
	printf("%d\n", ft_isalpha('1') == 0);
	printf("%d\n", ft_isalpha('@') == 0);
	printf("%d\n", ft_isalpha(-1) == 0);
	printf("%d\n", ft_isalpha(200) == 0);
	printf("%d\n", ft_isalpha(0) == 0);
	printf("\n");


	printf("ft_isdigit test: \n");
	printf("%d\n", ft_isdigit('1') == 1);
	printf("%d\n", ft_isdigit('b') == 0);
	printf("%d\n", ft_isdigit('@') == 0);
	printf("%d\n", ft_isdigit(-1) == 0);
	printf("%d\n", ft_isdigit(200) == 0);
	printf("%d\n", ft_isdigit(0) == 0);
	printf("\n");


	printf("ft_isalnum test: \n");
	printf("%d\n", ft_isalnum('a') == 1);
	printf("%d\n", ft_isalnum('-') == 0);
	printf("%d\n", ft_isalnum('9') == 1);
	printf("%d\n", ft_isalnum(-1) == 0);
	printf("%d\n", ft_isalnum(200) == 0);
	printf("%d\n", ft_isalnum(0) == 0);
	printf("\n");


	printf("ft_isascii test: \n");
	printf("%d\n", ft_isascii('a') == 1);
	printf("%d\n", ft_isascii(200) == 0);
	printf("%d\n", ft_isascii(-1) == 0);
	printf("\n");


	printf("ft_isprint test: \n");
	printf("%d\n", ft_isprint('a') == 1);
	printf("%d\n", ft_isprint('a') == 1);
	printf("%d\n", ft_isprint(-1) == 0);
	printf("%d\n", ft_isprint(200) == 0);
	printf("\n");


	printf("ft_strlen test: \n");
	printf("%d\n", ft_strlen("test") == 4);
	printf("%d\n", ft_strlen("") == 0);
	printf("%d\n", ft_strlen(" ") == 1);
	printf("\n");


	printf("ft_memset test: \n");
	char a[] = "test";
	ft_memset(a, 'x', 4);
	printf("%d\n", strcmp(a,"xxxx") == 0);
	ft_memset(a, '0', 2);
	printf("%d\n", strcmp(a,"00xx") == 0);
	ft_memset(a, 0, 9);
	printf("%d\n", strcmp(a,"\0") == 0);
	printf("Four zeroes: %d - %d - %d - %d\n", a[0], a[1], a[2], a[3]);
	printf("\n");


	printf("ft_bzero test: \n");
	strlcpy(a, "test", 4);
	ft_bzero(a, 4);
	printf("%d\n", strcmp(a,"\0\0\0\0") == 0);
	printf("Four zeroes: %d - %d - %d - %d\n", a[0], a[1], a[2], a[3]);
	printf("\n");


	printf("ft_memcpy test: \n");
	char dst[] = "blabla";
	char src[] = "testte";
	ft_memcpy(dst, src, 3);
	printf("%d\n", strncmp(dst,"tesbla", 5) == 0);
	printf("%d\n", strncmp(dst,"tesbla", 6) == 0);
	printf("%d\n", strncmp(dst,"tesbla", 7) == 0);
	printf("%d\n", strncmp(dst,"tesbla", 20000) == 0);
	printf("%d\n", strncmp(src,"testte",6) == 0);
	printf("\n");


	printf("ft_memmove test:\n");
	char b[] = "teststring";
	char c[20];
	printf("%d\n", strncmp(ft_memmove(c, b, 5),"tests", 5) == 0);
	printf("%d\n", strncmp(ft_memmove(c, b, 5),"tests\0", 6) == 0);

	char dest[30] = "lorem ipsum dolor sit amet";
	ft_memmove(dest, "consectetur", 5);
	printf("%s\n", dest);

	printf("\n");


	printf("ft_strlcpy test:\n");
	char d[20] = "pindakaas";
	char e[20];
	char f[20];
	ft_strlcpy(e, d, 20);
	strlcpy(f,d,20);
	printf("%d\n", strcmp(e,f) == 0);

	ft_strlcpy(e, d, 10);
	strlcpy(f,d,10);
	printf("%d\n", strcmp(e,f) == 0);

	ft_strlcpy(e, d, 9);
	strlcpy(f,d,9);
	printf("%d\n", strcmp(e,f) == 0);

	ft_strlcpy(e, d, 8);
	strlcpy(f,d,8);
	printf("%d\n", strcmp(e,f) == 0);

	ft_strlcpy(e, d, 6);
	strlcpy(f,d,6);
	printf("%d\n", strcmp(e,f) == 0);

	ft_strlcpy(e, d, 6);
	strlcpy(f,d,6);
	printf("%d\n", strcmp(e,f) == 0);

	ft_strlcpy(e, d, 0);
	strlcpy(f,d,0);
	printf("%d\n", strcmp(e,f) == 0);
	printf("\n");


	printf("ft_strlcat test:\n");
	char g[20] = "pinda";
	char h[20] = "kaas";
	char j[20] = "pinda";
	ft_strlcat(g,h,20);
	strlcat(j,h,20);
	printf("%d\n", strcmp(g,j) == 0);

	strcpy(g,"pinda");
	strcpy(j,"pinda");

	ft_strlcat(g,h,2);
	strlcat(j,h,2);
	printf("ft: %s\n",g);
	printf("reg: %s\n", j);
	printf("%d\n", strcmp(g,j) == 0);
	printf("\n");


	printf("ft_toupper test:\n");
	printf("%d\n", ft_toupper('c') == 'C');
	int i = 0;
	int letters = 0;
	while(i < 300)
	{
		if(ft_toupper(i) == i - 32)
			letters++;
		i++;
	}
	printf("%d\n", letters == 26);
	printf("\n");


	printf("ft_tolower test:\n");
	printf("%d\n", ft_tolower('C') == 'c');
	i = 0;
	letters = 0;
		while(i < 300)
	{
		if(ft_toupper(i) == i - 32)
			letters++;
		i++;
	}
	printf("%d\n", letters == 26);
	printf("\n");


	printf("ft_strchr test:\n");
	char l[20] = "hitckhiker";
	printf("%d\n",ft_strchr(l,'h') == strchr(l,'h'));
	printf("%d\n",ft_strchr(l,'r') == strchr(l,'r'));
	printf("%d\n",ft_strchr(l,'k') == strchr(l,'k'));
	printf("%d\n",ft_strchr(l,'z') == strchr(l,'z'));
	printf("%d\n",ft_strchr(l,'\0') == strchr(l,'\0'));
	printf("\n");


	printf("ft_strrchr test:\n");
	char m[20] = "galaxy";
	printf("%d\n",ft_strrchr(m,'r') == strrchr(m,'r'));
	printf("%d\n",ft_strrchr(m,'a') == strrchr(m,'a'));
	printf("%d\n",ft_strrchr(m,'l') == strrchr(m,'l'));
	printf("%d\n",ft_strrchr(m,'g') == strrchr(m,'g'));
	printf("%d\n",ft_strrchr(m,'y') == strrchr(m,'y'));
	printf("%d\n",ft_strrchr(m,'\0') == strrchr(m,'\0'));
	printf("\n");


	printf("ft_strncmp test:\n");
	char n[20] = "asd\200fMelvin";
	char o[20] = "asd\0fMarvin";
	printf("%d\n", ft_strncmp(n,o,2) == strncmp(n,o,2));
	printf("%d\n", ft_strncmp(n,o,3) == strncmp(n,o,3));
	printf("%d\n", ft_strncmp(n,o,10) == strncmp(n,o,10));
	printf("%d\n", ft_strncmp(n,o,0) == strncmp(n,o,0));
	printf("%d\n", ft_strncmp(n,o,1) == strncmp(n,o,1));


	printf("%d\n", ft_strncmp(o,n,2) == strncmp(o,n,2));
	printf("%d\n", ft_strncmp(o,n,3) == strncmp(o,n,3));
	printf("%d\n", ft_strncmp(o,n,10) == strncmp(o,n,10));
	printf("%d\n", ft_strncmp(o,n,0) == strncmp(o,n,0));
	printf("%d\n", ft_strncmp(o,n,1) == strncmp(o,n,1));
	printf("\n");


	printf("ft_memchr test:\n");
	char p[20] = "codam";
	long q[20] = {1234,2345,3456,4567};
	printf("%d\n", ft_memchr(p,'c',5) == memchr(p,'c',5));
	printf("%d\n", ft_memchr(p,'c',0) == memchr(p,'c',0));
	printf("%d\n", ft_memchr(p,'c',21) == memchr(p,'c',21));
	printf("%d\n", ft_memchr(q,'c',sizeof(long) * 20) == memchr(q,'c',sizeof(long) * 20));
	printf("\n");


	printf("ft_memcmp test:\n");
	char x[20] = "aaaa";
	char y[20] = "xxxx";
	printf("%d\n", ft_memcmp(x,y,4) == memcmp(x,y,4));
	printf("%d\n", ft_memcmp(x,y,1) == memcmp(x,y,1));
	printf("%d\n", ft_memcmp(x,y,0) == memcmp(x,y,0));
	printf("%d\n", ft_memcmp(x,y,10) == memcmp(x,y,10));
	printf("\n");


	printf("ft_strnstr test:\n");
	char r[200] = "I want to be, the very best, like no one ever was.";
	char s[20] = "ery be";
	printf("%d\n", ft_strnstr(r,s,200) == strnstr(r,s,200));
	printf("%d\n", ft_strnstr(r,s,0) == strnstr(r,s,0));
	printf("%d\n", ft_strnstr(r,s,1) == strnstr(r,s,1));
	printf("%d\n", ft_strnstr(r,s,2000) == strnstr(r,s,2000));
	printf("%d\n", ft_strnstr(r,s,20) == strnstr(r,s,20)); //cut off half way

	// printf("%d\n", ft_strnstr("this is a needle","needle",100) == strnstr("this is a needle","needle",100));
	// printf("%s - %s \n", ft_strnstr(r,s,200), strnstr(r,s,200));
	// printf("%s - %s \n", ft_strnstr(r,s,0), strnstr(r,s,0));
	// printf("%s - %s \n", ft_strnstr(r,s,1), strnstr(r,s,1));
	// printf("%s - %s \n", ft_strnstr(r,s,2000), strnstr(r,s,2000));
	// printf("%s - %s \n", ft_strnstr(r,s,20), strnstr(r,s,20));
	printf("\n");


	printf("%s\n", "ft_atoi test: ");
	char atoi[20] = " 	\f\v\r\t  ++-78245";
	int res = ft_atoi(atoi);
	printf("%d\n", res == -78245);
	printf("\n");

	printf("ft_calloc test:\n");
	char *ptr = 0;
	char *ptr2 = 0;
	ptr = ft_calloc(5,5);
	ptr2 = calloc(5,5);

	i = 0;
	while(i < 26)
	{
		printf("%d.%d - ", i, ptr[i]);
		i++;
	}	
	printf("\n");
	i = 0;
	while(i < 26)
	{
		printf("%d.%d - ", i, ptr2[i]);
		i++;
	}
	printf("\n");
	//below is copypasta'd from the internet, and edited
	size_t alloc_len = 100;
	char *ptr3 = (char *)calloc(1, alloc_len);
	if(ptr3 == (void *)0)
		printf("%s\n", "wrong");
	for (size_t i = 0; i < alloc_len; i++)
	{
		if(0 != ptr3[i])
			printf("%s\n", "wrong");
	}
	free(ptr3);
	printf("\n");


	printf("ft_strdup test:\n");
	char z[20] = "bullshit";
	char za[0] = "";
	char zb[26] = "abcdefghijklmnopqrstuvwxyz";
	char *zz = (void *)0;
	char *yy = (void *)0;

	zz = ft_strdup(z);
	yy = strdup(z);
	printf("%d\n", strcmp(zz,yy) == 0);
	zz = ft_strdup(za);
	yy = strdup(za);
	printf("%d\n", strcmp(zz,yy) == 0);
	zz = ft_strdup(zb);
	yy = strdup(zb);
	printf("%d\n", strcmp(zz,yy) == 0);
	printf("\n");

	free(ptr);
	free(ptr2);

	/////////////////////////////PART 2

	printf("ft_substr test:\n");
	char a1[20] = "this_is_a_string";
	char *ptr4;
	i = 0;
	while(i < 20)
	{
		ptr4 = ft_substr(a1,i,20-i);
		printf("%.2d: %s -\n", i, ptr4);
		i++;
		free(ptr4);
	}
	printf("\n");
	printf("\n");

	printf("ft_strjoin test:\n");
	char b1[20] = "super";
	char b2[20] = "string";
	char *b3 = ft_strjoin(b1,b2);

	printf("%s\n", b3);

	// printf("ft_strtrim2 test:\n");
	// char c1[20] = "t@e!s#t$s%t^r&i*n(g)";
	// char *mask = "@!#$%^&*()";
	// char *c2 = ft_strtrim(c1, mask);
	// printf("%s\n", c2);

	printf("ft_strtrim test:\n");
	char c1[25] = "!@#$%testst@@@ring^&*()";
	char *mask = "@!#$%^&*()";
	char *c2 = ft_strtrim(c1, mask);
	printf("%s\n", c2);
	char *c3 = "        ";
	char *mask2 = "\t \n";
	char *c4 = ft_strtrim(c3,mask2);
	printf("%s\n",c4);


	printf("ft_split test: \n");
	char d1[50] = "THIS@IS@A@TEST@STRING";
	char **str_arr = ft_split(d1, '@');
	i=0;
	while(i < 6)
	{
		printf("%d - %s\n", i, str_arr[i]);
		i++;
	}

	char d2[300] = "lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse";
	char **str_arr2 = ft_split(d2, ' ');
	i=0;
	while(i < 12)
	{
		// printf("split %d: - %s\n", i, str_arr2[i]);
		char *pp = str_arr2[i];
		write(1, "1: ", 2);
		ft_putstr_fd(pp, 1);
		printf("\n");
		i++;
	}

	printf("ft_itoa test:\n");
	int e1 = 1234;
	int e2 = -9786;
	int e3 = 0;
	int e4 = 1;
	int e5 = -1;
	int e6 = 2147483647;
	int e7 = -2147483648;

	printf("%d\n", strcmp(ft_itoa(e1),"1234") == 0);
	printf("%d\n", strcmp(ft_itoa(e2),"-9786") == 0);
	printf("%d\n", strcmp(ft_itoa(e3),"0") == 0);
	printf("%d\n", strcmp(ft_itoa(e4),"1") == 0);
	printf("%d\n", strcmp(ft_itoa(e5),"-1") == 0);
	printf("%d\n", strcmp(ft_itoa(e6),"2147483647") == 0);
	printf("%d\n", strcmp(ft_itoa(e7),"-2147483648") == 0);


	// printf("ft_strmapi test:\n");
	// char f1[20] = "teststring";
	// printf("%s\n", ft_strmapi(f1, strmapi_tester));

	// printf("ft_striteri test:\n");
	// char g1[20] = "cheese";
	// ft_striteri(g1, striteri_tester);
	// printf("%s\n", g1);

	printf("ft_putchar_fd test:\n");
	ft_putchar_fd('C',1);
	ft_putchar_fd('o',1);
	ft_putchar_fd('D',1);
	ft_putchar_fd('a',1);
	ft_putchar_fd('M',1);
	ft_putchar_fd('\n',1);

	printf("ft_putstr_fd test:\n");
	ft_putstr_fd("Brodam\n",1);

	printf("ft_putendl_fd test:\n");
	ft_putendl_fd("Yeet",1);

	printf("ft_putnbr_fd test:\n");
	ft_putnbr_fd(123456789,1);
	ft_putchar_fd('\n',1);

	printf("%s\n", "retest:");
	printf("%d\n",ft_memcmp("t\200", "t\0", 2));
	printf("%d\n",ft_memcmp("testss", "test", 5));
	printf("%d\n",ft_memcmp("test", "tEst", 4));
	printf("%d\n",ft_memcmp("abcdefgh", "abcdwxyz", 6));


}

// char	**ft_split(char const *s, char c)
// {
// 	char	**str_arr;
// 	char	*next_delim;
// 	size_t	len;
// 	int		i;
// 	int		j;

// 	len = count_words(s, c);
// 	str_arr = malloc(sizeof(char *) * len + 1);

// 	next_delim = ft_strchr(s, c);
// 	len = next_delim - s;
// 	str_arr[0] = malloc(sizeof(char) * len + 1);

// 	j = 0;
// 	i = 0;
// 	while (*s)
// 	{
// 		if (s == next_delim)
// 		{
// 			str_arr[j++][i] = '\0';
// 			i = 0;
// 			next_delim = ft_strchr(s + 1, c);
// 			if (next_delim)
// 				len = next_delim - s;
// 			else
// 			{
// 				len = ft_strchr(s + 1, '\0') - s;
// 				str_arr[j + 1] = NULL;
// 			}
// 			str_arr[j] = malloc(sizeof(char) * len + 1);
// 		}
// 		else
// 			str_arr[j][i++] = *s;
// 		s++;
// 	}
// 	return (str_arr);
// }

 size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
 {
 	int		i;
 	size_t	dst_len;
 	size_t	src_len;

 	src_len = ft_strlen(src);
 	dst_len = ft_strlen(dst);
 	if (dstsize == 0)
 		return (0);
 	// if(dstsize <= dst_len)
 	// 	return (dst_len);
 	i = 0;
 	while (dst[i] && dstsize-- != 0)
 		i++;
 	if(dstsize == 0)
 		return (i);
 	while (dstsize > 1 + dst_len && *src != '\0')
 	{
 		dst[i] = *src++;
 		dstsize--;
 		i++;
 	}
 	dst[i] = '\0';
 	return (dst_len + src_len);
 }


// size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
// {
// 	char *d = dst;
// 	const char *s = src;

// 	size_t src_len = ft_strlen(src);

// 	while(*d != '\0' && dstsize-- != 0)
// 		d++;

// 	size_t dlen = d - dst;

// 	if(dstsize == 0)
// 		return (dlen + src_len);

// 	while(*s != '\0')
// 	{
// 		if(dstsize > 1)
// 		{
// 			*d++ = *s;
// 			dstsize--;
// 		}
// 		s++;
// 	}
// 	*d = '\0';

// 	return dlen + (s - src);
// }

//Copypasta'd
size_t ft_strlcat2(char *dst, const char *src, size_t siz)
{
	char *d = dst;
	const char *s = src;
	size_t dstsize = siz;
	size_t dlen;

	/* Find the end of dst and adjust bytes left but don't go past end */
	while (dstsize-- != 0 && *d != '\0')
		d++;
	dlen = d - dst;
	dstsize = siz - dlen;

	if (dstsize == 0)
		return(dlen + ft_strlen(s));

	while (*s != '\0') {
		if (dstsize != 1) {
			*d++ = *s;
			dstsize--;
		}
		s++;
	}
	*d = '\0';

	return(dlen + (s - src));	/* count does not include NUL */
}
