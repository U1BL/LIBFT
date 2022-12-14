/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mofaisal <mofaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 17:47:18 by mofaisal          #+#    #+#             */
/*   Updated: 2022/10/30 20:45:42 by mofaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	checker(char const *set, char c)
{
	int	j;

	j = 0;
	while (set[j] != '\0')
	{
		if (c == set[j])
			return (1);
		j++;
	}
	return (0);
}

static int	check_begining(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	count2;

	i = 0;
	j = 0;
	count2 = 0;
	while (s1[i] != '\0')
	{
		if (checker(set, s1[i]) == 1)
				count2++;
		else if (checker(set, s1[i]) == 0)
			return (count2);
		i++;
	}
	return (count2);
}

static int	check_end(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	count1;

	i = ft_strlen(s1) - 1;
	j = 0;
	count1 = 0;
	while (i > 0)
	{
		if (checker(set, s1[i]) == 1)
				count1++;
		else if (checker(set, s1[i]) == 0)
			return (count1);
		i--;
	}
	return (count1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		len;
	size_t	count;
	char	*new_string;

	if (!s1 || !set)
		return (NULL);
	count = check_end(s1, set) + check_begining(s1, set);
	if (count >= ft_strlen(s1))
		return (ft_strdup(""));
	len = ft_strlen(s1) - count;
	if (len == 0)
	{
		new_string = malloc(1);
		new_string[0] = '\0';
		return (new_string);
	}
	count = check_begining(s1, set);
	new_string = ft_substr(s1, count, len);
	if (!new_string)
		return (NULL);
	new_string[len] = '\0';
	return (new_string);
}

// int	main(void)
// {
// 	char ptr1[] = "  \t \t \n   \n\n\n\t";
// 	char ptr2[] = " \t";
// 	printf("%s", ft_strtrim(ptr1, ptr2));
// 	return (0);
// }