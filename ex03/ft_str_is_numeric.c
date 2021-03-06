/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yojung <yojung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 09:42:07 by yojung            #+#    #+#             */
/*   Updated: 2020/07/15 10:35:29 by yojung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_numeric(char *str)
{
	int		i;

	i = 0;
	while (str[i] != 0)
	{
		if (!('0' <= str[i] && str[i] <= '9'))
		{
			return (0);
		}
		i++;
	}
	return (1);
}
