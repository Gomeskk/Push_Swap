/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joafaust <joafaust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 12:06:04 by joafaust          #+#    #+#             */
/*   Updated: 2024/11/27 12:50:50 by joafaust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

/* While arguments are valid, we start to add them 
into stack here one by one with while loop.
Atoi takes the number and turn it into an integer 
value where we can make math operations.
With stack new we create a new node for the current 
argument without linking it to list.
We make linking stage in ft_add_back call. */
void	list_args(char **av, t_stack **stack_a)
{
	long	i;

	i = 1;
	while (av[i] != NULL)
	{
		ft_add_back(stack_a, ft_stack_new(ft_atoi(av[i])));
		i++;
	}
}
