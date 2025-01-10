

// #include "../../include/minishell.h"

// void    init(t_data *data, char **env)
// {
//     char    *strnum;
//     int     shell_level;

//     //setup_env();
//     data->cmd_exit_no = 0;
//     strnum = env_val("SHLVL", env);

//     if (strnum)
//     {
//         shell_level = ft_atoi(strnum);
//         shell_level++;
//         update_env("SHLVL", ft_itoa(shell_level));
//     }
//     else
//     {
//         update_env("SHLVL", ft_itoa(1));
//     }
//     data->input = NULL;
//     data->new_input = NULL;
//     data->list = NULL;
// }

// char    *env_val(const char *key, char **env)
// {
//     char    *env_key;
//     char    *env_value;
//     int     i;

//     while (env[i])
//     {
//         env_key = ft_substr(env[i], 0, ft_strchr(env[i], '=') - env[i]);
//         env_value = ft_substr(env[i], ft_strchr(env[i], '=') - env[i] + 1, ft_strlen(env[i]) - ft_strlen(env_key) - 1);
        
//         if (strcmp(env_key, key) == 0)
//         {
//             free(env_key);
//             return (env_value);
//         }
//         free(env_key);
//         free(env_value);
//         i++;
//     }
//     return (NULL);
// }

// void    update_env(const char *key, const char *value)
// {
//     ft_printf("Updating environment variable %s to %s\n", key, value);
// }