# include <stdlib.h>
# include <stdio.h>

# include "fdf.h"
# include "mlx/mlx.h"


typedef struct s_test
{
	int *arr;
} t_test;

void maker(t_test *test)
{
	test->arr = malloc(sizeof(int) * 500);
}

void filler(t_test *test)
{
	for(int i = 0; i < 500; i++)
	{
		test->arr[i] = i;
	}
}

void printer(t_test *test)
{
	for(int i = 0; i < 500; i++)
	{
		printf("%d\n", test->arr[i]);
	}
}

int main()
{
	t_test test;

	maker(&test);

	t_mlx* mlx;

	mlx = malloc(sizeof(t_mlx));
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "FDF by Thibauld Nuyten");
	mlx->img.img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	mlx->img.addr = mlx_get_data_addr(mlx->img.img, &mlx->img.bits_per_pixel, &mlx->img.line_length, &mlx->img.endian);



	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img, 0, 0);
	mlx_loop(mlx->mlx);


	filler(&test);
	printer(&test);


}

