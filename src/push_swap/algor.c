/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joafaust <joafaust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 11:49:33 by joafaust          #+#    #+#             */
/*   Updated: 2024/12/02 12:10:43 by joafaust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

/*  This function does three things.
 1. It checks if the number of input is less than 2.
 2. It checks if the number of input is equal to 2.
	If it is, it means it is a quoted string.
 3. It checks if the number of input is greater than 2.
		If it is, it lists the arguements. */
int	ft_atoi2(const char *str, t_stack *a)
{
	int				mod;
	long long int	i;

	i = 0;
	mod = 1;
	if (*str == '-')
	{
		mod = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	if (*str == '\0')
		handle_error(&a);
	while (*str)
	{
		if (!ft_isdigit(*str))
			handle_error(&a);
		i = i * 10 + (*str - 48);
		str++;
		if ((mod * i) > 2147483647 || (mod * i) < -2147483648)
			handle_error(&a);
	}
	return (mod * i);
}

/*  This function does three things.
 1. It checks if the number of input is less than 2.
 2. It checks if the number of input is equal to 2.
 3. It checks if the number of input is greater than 2.
		If it is, it lists the arguements. */
t_stack	*process(int ac, char **av)
{
	t_stack	*a;
	int		i;
	int		j;

	i = 0;
	a = NULL;
	if (ac < 2)
		handle_error(NULL);
	while (++i < ac)
	{
		if (checkk_signal(av[i]))
			handle_error(&a);
		if (!is_invalid_quotes(av[i]))
			handle_error(&a);
		j = ft_atoi2(av[i], a);
		ft_add_back(&a, ft_stack_new(j));
	}
	return (a);
}
