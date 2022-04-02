/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 13:11:51 by mmizuno           #+#    #+#             */
/*   Updated: 2022/04/02 13:18:28 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex.h"

static void
deallocate_memory(char **memory)
{
	int		i;

	i = -1;
	while (memory[++i])
		free(memory[i]);
	free(memory);
}

char
*join_pathname(char *path, char *name)
{
	char	*pathname;
	size_t	len1;
	size_t	len2;
	int		i;

	if (!path || !name)
		return (NULL);
	len1 = ft_strlen(path);
	len2 = ft_strlen(name);
	pathname = (char *)malloc(sizeof(char) * (len1 + len2 + 2));
	if (!pathname)
		return (NULL);
	pathname[len1] = '/';
	pathname[len1 + 1 + len2] = '\0';
	i = -1;
	while (path[++i])
		pathname[i] = path[i];
	i = -1;
	while (name[++i])
		pathname[len1 + 1 + i] = name[i];
	return (pathname);
}

char
*find_pathname(char **envp, char *command)
{
	char	**paths;
	char	*pathname;
	int		i;

	i = 0;
	while (ft_strnstr(envp[i], "PATH=", 5) == 0)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	if (!paths)
		exit_pipex(EXIT_FAILURE);
	i = 0;
	while (paths[i])
	{
		pathname = join_pathname(paths[i], command);
		if (!pathname)
			exit_pipex(EXIT_FAILURE);
		if (access(pathname, F_OK) == 0)
			return (pathname);
		free(pathname);
		i++;
	}
	deallocate_memory(paths);
	return (NULL);
}

void
exec_command(char **envp, char *command)
{
	char	*pathname;
	char	**argv;

	argv = ft_split(command, ' ');
	if (!argv)
		exit_pipex(EXIT_FAILURE);
	pathname = find_pathname(envp, argv[0]);
	if (!pathname)
		exit_pipex(EXIT_FAILURE);
	execve(pathname, argv, envp);
	// execve("/usr/bin/wc", argv, envp);
	deallocate_memory(argv);
}
