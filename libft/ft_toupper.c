/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mofaisal <mofaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 14:59:11 by mofaisal          #+#    #+#             */
/*   Updated: 2022/10/02 15:05:55 by mofaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_toupper(int c)
{
	if(c >= 'a' && c <= 'z')
		c -= 32;
		return (c);
}