/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joafaust <joafaust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 11:49:33 by joafaust          #+#    #+#             */
/*   Updated: 2024/11/28 17:24:39 by joafaust         ###   ########.fr       */
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
			return (0);
		i = i * 10 + (*str - 48);
		str++;
	}
	if ((mod * i) > 2147483647 || (mod * i) < -2147483648)
		return (0);
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
	char	*c;

	i = 0;
	a = NULL;
	if (ac < 2)
		handle_error(NULL);
	while (++i < ac)
	{
		if (!its_letters(av[i]))
			handle_error(&a);
		j = ft_atoi2(av[i]);
		c = ft_itoa(j);
		if (ft_strncmp(c, av[i], ft_strlen(av[i])))
		{
			free(c);
			handle_error(&a);
		}
		free(c);
		ft_add_back(&a, ft_stack_new(j));
	}
	return (a);
}

/* This function checks if the argument its a letter */
int	its_letters(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
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
