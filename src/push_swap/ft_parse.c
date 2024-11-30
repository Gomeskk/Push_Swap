/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joafaust <joafaust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 12:07:07 by joafaust          #+#    #+#             */
/*   Updated: 2024/11/30 17:26:06 by joafaust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

/* This function does three things.
1. It checks if the number of input is less than 2.
2. It checks if the number of input is equal to 2.
   If it is, it means it is a quoted string.
3. It checks if the number of input is greater than 2.
    If it is, it lists the arguements. */
t_stack	*ft_parse(int ac, char **av)
{
	t_stack	*stack_a;

	stack_a = NULL;
	if (ac < 2)
		ft_error();
	else if (ac == 2)
		stack_a = ft_parse_args_quoted(av);
	else
	{
		list_args(av, &stack_a);
	}
	return (stack_a);
}
