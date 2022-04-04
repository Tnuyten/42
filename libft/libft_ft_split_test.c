#include <stdio.h>
#include <string.h>
#include "libft_proj/libft.h"

int main() {
    char **res;

    //len 0
    printf("%s\n", "len 0:");
    res = ft_split("",'-');
    printf("%d\n", res[0] == NULL);

    //len 1
    printf("%s\n", "len 1:");
    res = ft_split("-",'-');
    printf("%d\n", res[0] == NULL);

    res = ft_split("a",'-');
    printf("%d\n", strcmp(res[0],"a") == 0);
    printf("%d\n", res[1] == NULL);

    //len 2
    printf("%s\n", "len 2:");
    res = ft_split("a-",'-');
    printf("%d\n", strcmp(res[0],"a") == 0);
    printf("%d\n", res[1] == NULL);

    res = ft_split("-a",'-');
    printf("%d\n", strcmp(res[0],"a") == 0);
    printf("%d\n", res[1] == NULL);

    res = ft_split("--",'-');
    printf("%d\n", res[0] == NULL);

    res = ft_split("aa",'-');
    printf("%d\n", strcmp(res[0],"aa") == 0);
    printf("%d\n", res[1] == NULL);

    //len 3
    printf("%s\n", "len 3:");
    res = ft_split("-a-",'-');
    printf("%d\n", strcmp(res[0],"a") == 0);
    printf("%d\n", res[1] == NULL);

    res = ft_split("a-a",'-');
    printf("%d\n", strcmp(res[0],"a") == 0);
    printf("%d\n", strcmp(res[1],"a") == 0);
    printf("%d\n", res[2] == NULL);

    res = ft_split("--a",'-');
    printf("%d\n", strcmp(res[0],"a") == 0);
    printf("%d\n", res[1] == NULL);

    res = ft_split("aa-",'-');
    printf("%d\n", strcmp(res[0],"aa") == 0);
    printf("%d\n", res[1] == NULL);

    res = ft_split("aa-",'-');
    printf("%d\n", strcmp(res[0],"aa") == 0);
    printf("%d\n", res[1] == NULL);

    res = ft_split("aaa",'-');
    printf("%d\n", strcmp(res[0],"aaa") == 0);
    printf("%d\n", res[1] == NULL);

    //len 4
    printf("%s\n", "len 4:");
    res = ft_split("a-a-",'-');
    printf("%d\n", strcmp(res[0],"a") == 0);
    printf("%d\n", strcmp(res[1],"a") == 0);
    printf("%d\n", res[2] == NULL);

    res = ft_split("-a-a",'-');
    printf("%d\n", strcmp(res[0],"a") == 0);
    printf("%d\n", strcmp(res[1],"a") == 0);
    printf("%d\n", res[2] == NULL);

    //len 5
    printf("%s\n", "len 5:");
    res = ft_split("-a-a-",'-');
    printf("%d\n", strcmp(res[0],"a") == 0);
    printf("%d\n", strcmp(res[1],"a") == 0);
    printf("%d\n", res[2] == NULL);

    res = ft_split("a-a-a",'-');
    printf("%d\n", strcmp(res[0],"a") == 0);
    printf("%d\n", strcmp(res[1],"a") == 0);
    printf("%d\n", strcmp(res[2],"a") == 0);
    printf("%d\n", res[3] == NULL);

    //len 6 and up
    printf("%s\n", "len 6 and up:");
    res = ft_split("aaa---",'-');
    printf("%d\n", strcmp(res[0],"aaa") == 0);
    printf("%d\n", res[1] == NULL);

    res = ft_split("---aaa",'-');
    printf("%d\n", strcmp(res[0],"aaa") == 0);
    printf("%d\n", res[1] == NULL);

    res = ft_split("---aaa---",'-');
    printf("%d\n", strcmp(res[0],"aaa") == 0);
    printf("%d\n", res[1] == NULL);

    res = ft_split("aaa---aaa",'-');
    printf("%d\n", strcmp(res[0],"aaa") == 0);
    printf("%d\n", strcmp(res[1],"aaa") == 0);
    printf("%d\n", res[2] == NULL);

    res = ft_split("aaa---aaa---",'-');
    printf("%d\n", strcmp(res[0],"aaa") == 0);
    printf("%d\n", strcmp(res[1],"aaa") == 0);
    printf("%d\n", res[2] == NULL);

    res = ft_split("---aaa---aaa",'-');
    printf("%d\n", strcmp(res[0],"aaa") == 0);
    printf("%d\n", strcmp(res[1],"aaa") == 0);
    printf("%d\n", res[2] == NULL);

    res = ft_split("---aaa---aaa---",'-');
    printf("%d\n", strcmp(res[0],"aaa") == 0);
    printf("%d\n", strcmp(res[1],"aaa") == 0);
    printf("%d\n", res[2] == NULL);

    res = ft_split("aaa---aaa---aaa",'-');
    printf("%d\n", strcmp(res[0],"aaa") == 0);
    printf("%d\n", strcmp(res[1],"aaa") == 0);
    printf("%d\n", strcmp(res[2],"aaa") == 0);
    printf("%d\n", res[3] == NULL);
}
