/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 18:33:34 by yyan-bin          #+#    #+#             */
/*   Updated: 2024/08/09 18:33:35 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_joinfree(char *s1, char *s2)
{
	char	*s;

	s = ft_strjoin(s1, s2);
	if (s1)
		free(s1);
	return (s);
}

//read .txt to string,if the string got '\n',return the string 
char	*readline(int fd, char *save)
{
	char	*temp;
	int		readd;

	if (!save)
		save = ft_calloc(1, 1);
	temp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	readd = 1;
	while (!ft_strchr(save, '\n') && readd > 0)
	{
		readd = read(fd, temp, BUFFER_SIZE);
		if (readd == -1)
		{
			free(temp);
			return (NULL);
		}
		temp[readd] = '\0';
		save = ft_joinfree(save, temp);
	}
	if (temp)
		free(temp);
	return (save);
}

//get the first '\n' and return the string
char	*cuting(char *save)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!save[i])
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	while (save[j] && save[j] != '\n')
	{
		line[j] = save[j];
		j++;
	}
	if (save[j] && save[j] == '\n')
		line[j] = '\n';
	return (line);
}

//cut first line '\n' and return remainder string
char	*afterline(char *save)
{
	char	*afline;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	afline = ft_calloc((ft_strlen(save) - i + 1), sizeof(char));
	while (save[++i])
		afline[j++] = save[i];
	free(save);
	return (afline);
}

//read--take first line--cut first line and save remainder
char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) < 0)
		return (NULL);
	save = readline(fd, save);
	if (!save)
		return (NULL);
	line = cuting(save);
	save = afterline(save);
	return (line);
}

/*
int main()
{
    int fd = open("test.txt", O_CREAT | O_RDWR, 0644);
    char    *s = (char *)malloc(sizeof(char) * 10);
    int readd = read(fd, s, 10);
    if (readd == 0)
    {
        char c = 'a';
        while (c <= 'z') {
            if (c == 'e' || c == 'l' || c == 's' || c == 'x')
                write(fd, "\n", 1);
            write(fd, &c, 1);
            c++;
        }
    }
    free(s);
    close(fd);

    fd = open("test.txt", O_RDWR);
    int i = 1;
    while (i)
    {
        char *line = get_next_line(fd);
        if (line)
            printf("main-%d:%s\n", i, line);
        else
        {
            printf("NULL\n");
            free(line);
            break ;
        }
        i++;
    }
    close(fd);
    return 0;
}
*/
