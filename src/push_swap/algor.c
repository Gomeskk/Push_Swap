/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joafaust <joafaust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 11:49:33 by joafaust          #+#    #+#             */
/*   Updated: 2024/11/27 14:44:11 by joafaust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

/*  This function does three things.
 1. It checks if the number of input is less than 2.
 2. It checks if the number of input is equal to 2.
    If it is, it means it is a quoted string.
 3. It checks if the number of input is greater than 2.
     If it is, it lists the arguements. */
int	ft_atoi2(const char *str)
{
	int				mod;
	long long int	i;

	i = 0;
	mod = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\f'
		|| *str == '\v' || *str == '\r')
		str++;
	if (*str == '-')
	{
		mod = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			ft_error();
		i = i * 10 + (*str - 48);
		str++;
	}
	if ((mod * i) > 2147483647 || (mod * i) < -2147483648)
		ft_error();
	return (mod * i);
}

/*  This function works and sorts the stacks
 in case of they are passed in between quotation
 marks. In this scenario, this function takes the
 string, and splits the numbers in order to create
 seperated integer number. */
t_stack	*sub_process(char **av)
{
	t_stack	*a;
	char	**tmp;
	int		i;
	int		j;

	a = NULL;
	i = 0;
	tmp = ft_split(av[1], 32);
	while (tmp[i])
	{
		j = ft_atoi2(tmp[i]);
		ft_add_back(&a, ft_stack_new(j));
		i++;
	}
	ft_freestr(tmp);
	free(tmp);
	return (a);
}

/*  This function does three things.
 1. It checks if the number of input is less than 2.
 2. It checks if the number of input is equal to 2.
    If it is, it means it is a quoted string. Call
	  another function. <sub_process>
 3. It checks if the number of input is greater than 2.
     If it is, it lists the arguements. */
t_stack	*process(int ac, char **av)
{
	t_stack	*a;
	int		i;
	int		j;

	i = 1;
	a = NULL;
	if (ac < 2)
		ft_error();
	if (ac == 2)
		a = sub_process(av);
	else
	{
		while (i < ac)
		{
			j = ft_atoi2(av[i]);
			ft_add_back(&a, ft_stack_new(j));
			i++;
		}
	}
	return (a);
}
