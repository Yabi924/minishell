/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwan-ab- wwan-ab-@student.42kl.edu.my      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 20:49:37 by wwan-ab-          #+#    #+#             */
/*   Updated: 2025/01/08 20:49:39 by wwan-ab-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UILTINS_H
# define BUILTINS_H

# include "minishell.h"
/*
    Builtins.

    Files involve:
    1) ft_cd.c = Change directory.
    2) ft_echo.c = Used to print output.
    3) ft_env.c
    4) ft_exit.c = Used to terminate the current shell session or the script.
    5) ft_export.c = It allows you to create or modify the environment variables.
    6) ft_pwd.c = When executed, it shows the current working directory.
    7) ft_unset.c = It is used to unset variables and functions which were defined previously.
*/
int ft_pwd(void);
int ft_echo(char *arg[]);
int ft_export(char *argv[], t_minishell *env);
int ft_unset(char *argv[], t_minishell *data);
int ft_cd(char *argv[], t_minishell *data);
int ft_env(char *argv[], t_minishell *data);
int ft_exit(char *argv[], t_minishell *data);

#endif
