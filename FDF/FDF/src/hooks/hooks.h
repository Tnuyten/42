/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 13:53:07 by tnuyten           #+#    #+#             */
/*   Updated: 2022/08/31 19:18:06 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_H
# define HOOKS_H

# include "../../fdf.h"
# include "../draw/draw.h"

int	keyhooks(int keycode, t_mlx *mlx);
int	more_keyhooks(int keycode, t_mlx *mlx);
int	close_window_button(t_mlx *mlx);

#endif