/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle_detector.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modo <modo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 10:08:58 by exam              #+#    #+#             */
/*   Updated: 2019/09/03 16:43:18 by modo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int	cycle_detector(const t_list *lst)
{
	t_list		*slow;
	t_list		*fast;

	slow = (t_list *)lst;
	fast = (t_list *)lst->next;
	while (fast && fast->next)
	{
		if (fast == slow)
			return (1);
		slow = slow->next;
		fast = fast->next->next;
	}
	return (0);
}