#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <string.h>

int	is_target(char c, char *target)
{
	int	i;

	i = -1;
	while (target[++i])
	{
		if (c == target[i])
			return (1);
	}
	return (0);
}

int	is_env(char *s, char *env)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (s[i] && s[i] != ' ' && !is_target(s[i], "'\"") && s[i] != '$')
		i++;
	while (env[j] && env[j] != '=')
		j++;
	while (s[k] && env[k] && s[k] == env[k] && (s[k] != ' ' || \
		!is_target(s[k], "'\"")))
		k++;
	if (env[k] == '=' && k == i)
		return (1);
	return (0);
}

char    *ft_getenv(char *s, char **env)
{
    int i;
    int p;

    i = -1;
    p = 0;
    while (s[p] && (s[p] != '"' || s[p] != '\'' || s[p] != '$' || s[p] != ' '))
        p++;
    printf("%d\n", p);
    while (env[++i])
        if (is_env(s, env[i]))
            return (strdup(env[i] + p + 1));
    return NULL;
}

int main(int a, char **b, char **env)
{
    char *enn = ft_getenv("PATH", env);
    printf("%s\n", enn);
	free(enn);
    return 0;
}