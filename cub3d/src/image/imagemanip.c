#include "imagemanip.h"

mlx_image_t*	ft_resize_image(mlx_t *mlx, mlx_image_t *image, t_uint nwidth, t_uint nheight);
int32_t			mlx_get_pixel(mlx_image_t *image, t_uint x, t_uint y, int endianness);

mlx_image_t*	ft_scale_image(mlx_t *mlx, mlx_image_t *image, float scale)
{
	return ft_resize_image(mlx, image, (t_uint)image->width * scale, (t_uint)image->height * scale);
}

mlx_image_t* ft_resize_image(mlx_t *mlx, mlx_image_t *image, t_uint nwidth, t_uint nheight)
{
	mlx_image_t	*newimage;
	double		wratio;
	double		hratio;

	wratio = (double)nwidth / image->width;
	hratio = (double)nheight / image->height;
	// Preserves aspect ratio. We might not want this if we want to be able to stretch images.
	// if (wratio < hratio)
	// {
	// 	nheight = (t_uint)(image->height * wratio);
	// }
	// else
	// {
	// 	nwidth = (t_uint)(image->width * hratio);
	// }
	newimage = mlx_new_image(mlx, nwidth, nheight);
	if (newimage != NULL)
	{
		for (unsigned int y = 0; y < nheight; y++)
		{
			for (unsigned int x = 0; x < nwidth; x++)
			{
				double origx = (double)x / nwidth * image->width;
				double origy = (double)y / nheight * image->height;
				uint32_t color = mlx_get_pixel(image, (t_uint)origx, (t_uint)origy, 1); //#TODO detect endiannes.
				mlx_put_pixel(newimage, x, y, color);
			}
		}
	}
	return newimage;
}

int32_t mlx_get_pixel(mlx_image_t *image, t_uint x, t_uint y, int endianness)
{
	uint32_t	subscr;
	uint32_t	*nt;
	uint32_t	color;

	subscr = (y * image->width + x) * sizeof(int32_t);
	nt = (uint32_t*)&image->pixels[subscr];
	color = *nt;
	if (endianness)
		color = ntohl(*nt);
	return (color);
}

// mlx_image_t*	ft_rotate_image(mlx_t *mlx, mlx_image_t *image, int xangle, int yangle, int zangle)
// {
// 	(void)mlx;
// 	(void)image;
// 	(void)xangle;
// 	(void)yangle;
// 	(void)zangle;
// 	//#TODO
// 	return (NULL);
// }

//Absolutely not plagiarized by ChatGPT.
mlx_image_t* ft_rotate_image(mlx_t* mlx, mlx_image_t* image, int angle)
{
    // calculate the sine and cosine of the angle
    double sin_angle = sin(angle * M_PI / 180.0);
    double cos_angle = cos(angle * M_PI / 180.0);

    // calculate the new dimensions of the rotated image
    int new_width = abs((int)(image->width * cos_angle) + (int)(image->height * sin_angle));
    int new_height = abs((int)(image->height * cos_angle) + (int)(image->width * sin_angle));

    // create a new image with the rotated dimensions
    mlx_image_t* new_image = mlx_new_image(mlx, new_width, new_height);

    // get the center point of the image
    double cx = image->width / 2.0;
    double cy = image->height / 2.0;

    // iterate over the pixels of the new image and copy the rotated pixels from the original image
    for (int y = 0; y < new_height; y++) {
        for (int x = 0; x < new_width; x++) {
            // calculate the position of the pixel in the original image
            double rx = cos_angle * (x - new_width / 2) + sin_angle * (y - new_height / 2) + cx;
            double ry = cos_angle * (y - new_height / 2) - sin_angle * (x - new_width / 2) + cy;

            // copy the pixel from the original image to the new image
            if (rx >= 0 && rx < image->width && ry >= 0 && ry < image->height) {
                int32_t color = mlx_get_pixel(image, (int)rx, (int)ry, 1);
                mlx_put_pixel(new_image, x, y, color);
            }
        }
    }

    // return the new rotated image
    return new_image;
}

void	clear_image(mlx_image_t *img, t_uint color)
{
	t_uint	x;
	t_uint	y;

	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			mlx_put_pixel(img, x, y, color);
			x++;
		}
		y++;
	}
}
