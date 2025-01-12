

#include "../../include/minishell.h"

void init(t_data *data, char **env)
{
    char *strnum;
    char *shlvl_str;
    int shell_level;

    data->cmd_exit_no = 0;
    strnum = env_val("SHLVL", env);

    if (strnum)
    {
        shell_level = ft_atoi(strnum) + 1;
        free(strnum);
        shlvl_str = ft_itoa(shell_level);
        update_env("SHLVL", shlvl_str);
        free(shlvl_str);
    }
    else
    {
        shlvl_str = ft_itoa(1);
        update_env("SHLVL", shlvl_str);
        free(shlvl_str);
    }
    data->input = NULL;
    data->new_input = NULL;
    data->list = NULL;
}


char *env_val(const char *key, char **env)
{
    char *env_key;
    char *env_value;
    int i = 0;

    while (env[i])
    {
        env_key = ft_substr(env[i], 0, ft_strchr(env[i], '=') - env[i]);
        if (strcmp(env_key, key) == 0)
        {
            free(env_key);
            env_value = ft_strdup(ft_strchr(env[i], '=') + 1);
            return env_value; // Dynamically allocated, ensure the caller frees this.
        }
        free(env_key);
        i++;
    }
    return NULL;
}



void    update_env(const char *key, const char *value)
{
    ft_printf("Updating environment variable %s to %s\n", key, value);
}
