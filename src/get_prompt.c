/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_prompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 13:25:42 by adjoly            #+#    #+#             */
/*   Updated: 2024/04/30 13:27:03 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*char	*get_hostname(void)
{
	char	*hostname;
	char	*tmp;
	int		host_file;

	//host_file = open();
	tmp = hostname;
	while (*tmp)
		tmp++;
	return
}*/

char	*get_prompt(void)
{
	char	**prompt;
	char	*ret = NULL;
	char	*home;
	char	**tmp;

	prompt = malloc(1000);
	prompt[0] = getenv("USER");
	prompt[1] = "@";
	//prompt[2] = get_hostname();
	home = getenv("HOME");
	prompt[3] = getenv("PWD");
	prompt[4] = ">";
	//ret = ft_calloc(1000, sizeof(char));

	if (!ft_strncmp(prompt[3], home, ft_strlen(home)))
		prompt[3] += ft_strlen(home);
	tmp = prompt;
	while (*tmp)
	{
		ft_strlcat(ret, *tmp, ft_strlen(ret) + ft_strlen(*tmp) + 1);
		tmp++;
	}
	free(prompt);
	return (ret);
}


