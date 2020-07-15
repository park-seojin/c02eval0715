/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yojung <yojung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 10:22:50 by yojung            #+#    #+#             */
/*   Updated: 2020/07/15 10:40:59 by yojung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	int		i;
	int		sz;

	i = 0;
	sz = (int)size;
	while (i < sz - 1 && src[i] != 0)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	while (src[i] != 0)
	{
		i++;
	}
	return (i);
}
