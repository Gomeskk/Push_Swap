/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_back.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joafaust <joafaust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 11:52:36 by joafaust          #+#    #+#             */
/*   Updated: 2024/11/30 19:29:32 by joafaust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

/* Function to add a new node to the stack from back side */
void	ft_add_back(t_stack **stack, t_stack *stack_new)
{
	if (!stack_new)
		handle_error(stack);
	if (!stack)
		return ;
	if (!*stack)
		*stack = stack_new;
	else
		(lstlast(*stack))->next = stack_new;
}
