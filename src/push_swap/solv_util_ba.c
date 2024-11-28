/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solv_util_ba.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joafaust <joafaust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:47:29 by joafaust          #+#    #+#             */
/*   Updated: 2024/11/28 12:29:48 by joafaust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

/* This function calculates the required amount of rotation.
Calculations are done for ra+rb case. */
int	ft_case_rarb_a(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = ft_find_place_a(a, c);
	if (i < ft_find_index(b, c))
		i = ft_find_index(b, c);
	return (i);
}

/* This function calculates the required amount of rotation.
Calculations are done for rra+rrb case. */
int	ft_case_rrarrb_a(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (ft_find_place_a(a, c))
		i = lstsize(a) - ft_find_place_a(a, c);
	if ((i < (lstsize(b) - ft_find_index(b, c))) && ft_find_index(b, c))
		i = lstsize(b) - ft_find_index(b, c);
	return (i);
}

/* This function calculates the required amount of rotation.
Calculations are done for ra+rrb case. */
int	ft_case_rarrb_a(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (ft_find_index(b, c))
		i = lstsize(b) - ft_find_index(b, c);
	i = ft_find_place_a(a, c) + i;
	return (i);
}

/* This function calculates the required amount of rotation.
Calculations are done for rra+rb case. */
int	ft_case_rrarb_a(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (ft_find_place_a(a, c))
		i = lstsize(a) - ft_find_place_a(a, c);
	i = ft_find_index(b, c) + i;
	return (i);
}
