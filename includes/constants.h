/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 08:19:36 by emadriga          #+#    #+#             */
/*   Updated: 2021/10/03 13:12:16 by emadriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANTS_H
# define CONSTANTS_H
# include "options.h"
# define FULL_ZEROS_STRING "00000000000000000000000000000000000000000000\
000000000000000"
# if IMAGE_BIG==0
#  define HEIGHT 25
#  define WIDTH 50
#  define MAXWIDTH 51
#  define MAXHEIGHT 50
# else
#  define HEIGHT 50
#  define WIDTH 100
#  define MAXWIDTH 25
#  define MAXHEIGHT 23
# endif
# if ENEMIES==0
#  define VALIDCELLS "01CEP"
# else
#  define VALIDCELLS "01CEPXxVvHh"
# endif

enum e_keycodes{
	A_KEY = 0,
	S_KEY,
	D_KEY,
	W_KEY = 13,
	ESC = 53,
	LEFT = 123,
	RIGHT,
	DOWN,
	UP
};
#endif
