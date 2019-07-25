/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 18:05:11 by udraugr-          #+#    #+#             */
/*   Updated: 2019/07/25 16:35:39 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractal.h"

int					julia_print(t_screen *screen, t_complex_numb *current)
{
	int				iter;
	long double		last_res;
	long double		tmp_a;
	long double		tmp_bi;

	iter = 0;
	last_res = ft_range(current);
	while (iter < screen->iter && last_res <= 2.0L)
	{
		tmp_a = current->a * current->a - current->bi * current->bi + ((t_complex_numb *)screen->c_for_julia)->a;
		tmp_bi = 2 * current->a * current->bi + ((t_complex_numb *)screen->c_for_julia)->bi;
		current->a = tmp_a;
		current->bi = tmp_bi;
		last_res = ft_range(current);
		++iter;
	}
	return (iter);
}
