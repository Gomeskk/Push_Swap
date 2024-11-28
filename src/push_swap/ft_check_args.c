/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joafaust <joafaust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 11:53:52 by joafaust          #+#    #+#             */
/*   Updated: 2024/11/28 12:27:27 by joafaust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

/* function which checks the character if it is alphanumerical */
int	ft_isalpha(int c)
{
	if ((c >= 58 && c <= 126) || (c >= 33 && c <= 42)
		|| (c == 44) || (c == 46) || (c == 47))
		return (1);
	return (0);
}

/* Here arguments are send to make ASCII check
regarding the alphanumeric values */
void	alpha_check(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while ((av[i][j]) != '\0')
		{
			if (ft_isalpha(av[i][j]))
				return (ft_error());
			j++;
		}
		i++;
	}
}

/* With this function it is checked 
whether arguments include alfanumeric or not */
int	check_args(char **av)
{
	alpha_check(av);
	if (!check_error(av, 1, 0))
		return (false);
	return (true);
}
