/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 08:19:36 by emadriga          #+#    #+#             */
/*   Updated: 2021/10/03 13:11:39 by emadriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGES_H
# define IMAGES_H
# include "options.h"
# if IMAGE_BIG==0
#  define WALL "./img/small/Wall.xpm"
#  define ODD "./img/small/Grass_Dark.xpm"
#  define PAIR "./img/small/Grass_Light.xpm"
#  define SKY_TL "./img/small/CloudsTL.xpm"
#  define SKY_TR "./img/small/CloudsTR.xpm"
#  define SKY_BL "./img/small/CloudsBL.xpm"
#  define SKY_BR "./img/small/CloudsBR.xpm"
#  define HOLE "./img/small/Hole.xpm"
#  define BLACK "./img/small/Black.xpm"
# else
#  define WALL "./img/big/Wall.xpm"
#  define ODD "./img/big/Grass_Dark.xpm"
#  define PAIR "./img/big/Grass_Light.xpm"
#  define SKY_TL "./img/big/CloudsTL.xpm"
#  define SKY_TR "./img/big/CloudsTR.xpm"
#  define SKY_BL "./img/big/CloudsBL.xpm"
#  define SKY_BR "./img/big/CloudsBR.xpm"
#  define HOLE "./img/big/Hole.xpm"
#  define BLACK "./img/big/Black.xpm"
# endif
# if PERFORMANCE==0 && IMAGE_BIG==0
#  define RABBIT_D "./img/small/Rabbit_Down.xpm"
#  define RABBIT_L "./img/small/Rabbit_Left.xpm"
#  define RABBIT_R "./img/small/Rabbit_Right.xpm"
#  define RABBIT_U "./img/small/Rabbit_Up.xpm"
#  define RABBIT_KO "./img/small/Rabbit_Dead.xpm"
#  define CARROT "./img/small/Carrot.xpm"
#  define SPIKES_U "./img/small/Spikes_Active.xpm"
#  define SPIKES_D "./img/small/Spikes.xpm"
#  define FOX_U "./img/small/Fox_Up.xpm"
#  define FOX_D "./img/small/Fox_Down.xpm"
#  define RAT_L "./img/small/Mouse_Left.xpm"
#  define RAT_R "./img/small/Mouse_Right.xpm"
# elif PERFORMANCE==1 && IMAGE_BIG==0
#  define RABBIT_D "./img/small/Rabbit_Avatar.xpm"
#  define RABBIT_L "./img/small/Rabbit_Avatar.xpm"
#  define RABBIT_R "./img/small/Rabbit_Avatar.xpm"
#  define RABBIT_U "./img/small/Rabbit_Avatar.xpm"
#  define RABBIT_KO "./img/small/Rabbit_Avatar_Dead.xpm"
#  define CARROT "./img/small/CarrotP.xpm"
#  define SPIKES_U "./img/small/SpikesP.xpm"
#  define SPIKES_D "./img/small/SpikesP.xpm"
#  define FOX_U "./img/small/Fox_Avatar.xpm"
#  define FOX_D "./img/small/Fox_Avatar.xpm"
#  define RAT_L "./img/small/Mouse_Avatar.xpm"
#  define RAT_R "./img/small/Mouse_Avatar.xpm"
# elif PERFORMANCE==0 && IMAGE_BIG==1
#  define RABBIT_D "./img/big/Rabbit_Down.xpm"
#  define RABBIT_L "./img/big/Rabbit_Left.xpm"
#  define RABBIT_R "./img/big/Rabbit_Right.xpm"
#  define RABBIT_U "./img/big/Rabbit_Up.xpm"
#  define RABBIT_KO "./img/big/Rabbit_Dead.xpm"
#  define CARROT "./img/big/Carrot.xpm"
#  define SPIKES_U "./img/big/Spikes_Active.xpm"
#  define SPIKES_D "./img/big/Spikes.xpm"
#  define FOX_U "./img/big/Fox_Up.xpm"
#  define FOX_D "./img/big/Fox_Down.xpm"
#  define RAT_L "./img/big/Mouse_Left.xpm"
#  define RAT_R "./img/big/Mouse_Right.xpm"
# else
#  define RABBIT_D "./img/big/Rabbit_Avatar.xpm"
#  define RABBIT_L "./img/big/Rabbit_Avatar.xpm"
#  define RABBIT_R "./img/big/Rabbit_Avatar.xpm"
#  define RABBIT_U "./img/big/Rabbit_Avatar.xpm"
#  define RABBIT_KO "./img/big/Rabbit_Avatar_Dead.xpm"
#  define CARROT "./img/big/CarrotP.xpm"
#  define SPIKES_U "./img/big/SpikesP.xpm"
#  define SPIKES_D "./img/big/SpikesP.xpm"
#  define FOX_U "./img/big/Fox_Avatar.xpm"
#  define FOX_D "./img/big/Fox_Avatar.xpm"
#  define RAT_L "./img/big/Mouse_Avatar.xpm"
#  define RAT_R "./img/big/Mouse_Avatar.xpm"
# endif
#endif