/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_process.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joafaust <joafaust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 17:08:52 by joafaust          #+#    #+#             */
/*   Updated: 2024/11/30 18:28:55 by joafaust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

/* This function checks if the argument its a letter */
int	its_letters(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str) && *str != '-' && *str != '+')
			return (0);
		str++;
	}
	return (1);
}

/* Handle errors */
void	handle_error(t_stack **stack)
{
	ft_error();
	if (stack)
		ft_free(stack);
	exit(1);
}

/* Handle Quotes */
int	is_invalid_quotes(char *str)
{
	if ((str[0] == '\'' && str[1] == '\0') || (str[0] == '\0'))
		return (0);
	if ((str[0] == '\'' && str[1] != '\0') || (str[0] == '\0'))
		return (0);
	return (1);
}

/* Handle signals */
int	checkk_signal(char *a)
{
	int	i;
	int	signal;

	i = -1;
	signal = 0;
	while (a[++i])
	{
		if ((a[i] == '-' || a[i] == '+') && signal)
			return (1);
		else if (a[i] == '-' || a[i] == '+')
			signal = 1;
	}
	return (0);
}