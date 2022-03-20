/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 08:19:36 by emadriga          #+#    #+#             */
/*   Updated: 2021/10/03 13:11:50 by emadriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H
# include "options.h"
# define ERROR "Error\n\t%s\n"
# define ERROR_EXTENSIONMAP "Introduce valid map (.ber file)"
# if IMAGE_BIG==0
#  define ERROR_MAXDIMENSIONS "Map exceeds allowed dimension sizes 51x50"
# else
#  define ERROR_MAXDIMENSIONS "Map exceeds allowed dimension sizes 25x23"
# endif
# if ENEMIES==0
#  define ERROR_VALIDMAP "Map allowed characters '01CEP'\n\
\tMap has to be rectangular\n\
\tMap has to be closed\n\
\tMap has at least one start, one exit and one collectable"
# else
#  define ERROR_VALIDMAP "Map allowed characters '01CEPXxVvHh'\n\
\tMap has to be rectangular\n\
\tMap has to be closed\n\
\tMap has at least one start, one exit and one collectable"
# endif
#endif
