#include "../get_next_line.h"
#include "tester.h"
#include "color/color.h"
#include "tests.c"

static char filePath[PATH_MAX];

int main()
{
	bzero(filePath, PATH_MAX);

	test_high_fd();
	test_neg_fd();
	test_empty();
	test_empty_nl();
	test_char();
	test_char_nl();
	test_one_line();
	test_one_line_nl();
	test_41();
	test_42();
	test_43();
	test_41_nl();
	test_42_nl();
	test_43_nl();
	test_30000();
	test_30000_nl();
	test_multi_nl();
	test_multi_char();
	test_multi_char_nl();
	test_multi_char_2();
	test_multi_char_2_nl();
	test_multi_char_random();
	test_multi_char_random_nl();
	test_multi_line_41();
	test_multi_line_41_nl();
	test_multi_line_42();
	test_multi_line_42_nl();
	test_multi_line_43();
	test_multi_line_43_nl();
	test_multi_line_random();
	test_multi_line_random_nl();
}

int	file_path(int fd, char *fp)
{
	int	check;

	check = fcntl(fd, F_GETPATH, fp);
	if (check == -1)
	{
		yellow();
		// printf("%s\n", "Could not get file name");
		reset_color();
	}
	return (check);
}

void test(int fd, char *expected_output)
{
	static int test_number = 1;
	int check;
	char *filename;
	char *line;
	char filePath_temp[PATH_MAX];

	file_path(fd, filePath_temp);

	if(strcmp(filePath_temp, filePath) != 0)
	{
		check = file_path(fd, filePath);
		if(check != -1)
		{
			filename = strrchr(filePath, '/') + 1;
			printf("Test %2d %-20s: ", test_number++, filename);
		} else {
			printf("Test %2d Unknown File : ", test_number++);
		}
	}

	line = get_next_line(fd);
	if(expected_output == NULL || line == NULL)
	{
		if(expected_output == line)
			correct();
		else
			wrong();
	}
	else
	{
		if(strcmp(expected_output, line) == 0)
			correct();
		else
			wrong();
	}
	if(expected_output == NULL)
		printf("\n");
	free(line);
}

void correct()
{
	green();
	printf("%s", "[OK] ");
	reset_color();
}

void wrong()
{
	red();
	printf("%s", "[NOPE] ");
	reset_color();
}
