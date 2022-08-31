/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 18:04:26 by tnuyten           #+#    #+#             */
/*   Updated: 2022/06/27 13:21:36 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "../queue/queue.h"
# include "../libft/libft.h"
# include <limits.h>
# include "../ft_printf/ft_printf.h"

int		has_duplicates(t_queue *queue);
int		parse_input(t_queue **a, int argc, char **argv);
int		intstr_less_than_max(char *str);

#endif
