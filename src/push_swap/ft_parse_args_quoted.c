/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_args_quoted.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joafaust <joafaust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 12:10:08 by joafaust          #+#    #+#             */
/*   Updated: 2024/11/30 17:26:27 by joafaust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

/* This function free the string which is 
the integer values in between quotes. */
void	ft_freestr(char **lst)
{
	char	*n1;

	if (!lst)
		return ;
	while (*lst)
	{
		n1 = *lst;
		lst++;
		free(n1);
	}
	*lst = NULL;
}

/* Function to parse the arguments from the quoted string
and send them to list_args function to add them into list.
With ft_split we split numbers from spaces. */
t_stack	*ft_parse_args_quoted(char **av)
{
	t_stack	*stack_a;
	char	**tmp;

	stack_a = NULL;
	tmp = ft_split(av[1], 32);
	list_args(tmp, &stack_a);
	ft_freestr(tmp);
	free(tmp);
	return (stack_a);
}
