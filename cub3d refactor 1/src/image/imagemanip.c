/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imagemanip.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 20:19:11 by tnuyten           #+#    #+#             */
/*   Updated: 2023/04/12 20:19:12 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "imagemanip.h"

void	clear_image(mlx_image_t *img, size_t color)
{
	size_t	x;
	size_t	y;

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
