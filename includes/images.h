/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 08:19:36 by emadriga          #+#    #+#             */
/*   Updated: 2022/09/05 14:04:09 by emadriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGES_H
# define IMAGES_H
# include "options.h"
# if IMAGE_BIG==0
#  define IMG_WALL "./img/small/Wall.png"
#  define IMG_ODD_TERRAIN "./img/small/Grass_Dark.png"
#  define IMG_PAIR_TERRAIN "./img/small/Grass_Light.png"
#  define IMG_SKY_TL "./img/small/CloudsTL.png"
#  define IMG_SKY_TR "./img/small/CloudsTR.png"
#  define IMG_SKY_BL "./img/small/CloudsBL.png"
#  define IMG_SKY_BR "./img/small/CloudsBR.png"
#  define IMG_SKY "./img/small/clouds.png"
#  define IMG_HOLE "./img/small/Hole.png"
#  define IMG_BLACK "./img/small/Black.png"
# else
#  define IMG_WALL "./img/big/Wall.png"
#  define IMG_ODD_TERRAIN "./img/big/Grass_Dark.png"
#  define IMG_PAIR_TERRAIN "./img/big/Grass_Light.png"
#  define IMG_SKY_TL "./img/big/CloudsTL.png"
#  define IMG_SKY_TR "./img/big/CloudsTR.png"
#  define IMG_SKY_BL "./img/big/CloudsBL.png"
#  define IMG_SKY_BR "./img/big/CloudsBR.png"
#  define IMG_SKY "./img/big/clouds.png"
#  define IMG_HOLE "./img/big/Hole.png"
#  define IMG_BLACK "./img/big/Black.png"
# endif
# if PERFORMANCE==0 && IMAGE_BIG==0
#  define IMG_RABBIT_D "./img/small/Rabbit_Down.png"
#  define IMG_RABBIT_L "./img/small/Rabbit_Left.png"
#  define IMG_RABBIT_R "./img/small/Rabbit_Right.png"
#  define IMG_RABBIT_U "./img/small/Rabbit_Up.png"
#  define IMG_RABBIT_KO "./img/small/Rabbit_Dead.png"
#  define IMG_CARROT "./img/small/Carrot.png"
#  define IMG_SPIKES_U "./img/small/Spikes_Active.png"
#  define IMG_SPIKES_D "./img/small/Spikes.png"
#  define IMG_FOX_U "./img/small/Fox_Up.png"
#  define IMG_FOX_D "./img/small/Fox_Down.png"
#  define IMG_RAT_L "./img/small/Mouse_Left.png"
#  define IMG_RAT_R "./img/small/Mouse_Right.png"
# elif PERFORMANCE==1 && IMAGE_BIG==0
#  define IMG_RABBIT_D "./img/small/Rabbit_Avatar.png"
#  define IMG_RABBIT_L "./img/small/Rabbit_Avatar.png"
#  define IMG_RABBIT_R "./img/small/Rabbit_Avatar.png"
#  define IMG_RABBIT_U "./img/small/Rabbit_Avatar.png"
#  define IMG_RABBIT_KO "./img/small/Rabbit_Avatar_Dead.png"
#  define IMG_CARROT "./img/small/CarrotP.png"
#  define IMG_SPIKES_U "./img/small/SpikesP.png"
#  define IMG_SPIKES_D "./img/small/SpikesP.png"
#  define IMG_FOX_U "./img/small/Fox_Avatar.png"
#  define IMG_FOX_D "./img/small/Fox_Avatar.png"
#  define IMG_RAT_L "./img/small/Mouse_Avatar.png"
#  define IMG_RAT_R "./img/small/Mouse_Avatar.png"
# elif PERFORMANCE==0 && IMAGE_BIG==1
#  define IMG_RABBIT_D "./img/big/Rabbit_Down.png"
#  define IMG_RABBIT_L "./img/big/Rabbit_Left.png"
#  define IMG_RABBIT_R "./img/big/Rabbit_Right.png"
#  define IMG_RABBIT_U "./img/big/Rabbit_Up.png"
#  define IMG_RABBIT_KO "./img/big/Rabbit_Dead.png"
#  define IMG_CARROT "./img/big/Carrot.png"
#  define IMG_SPIKES_U "./img/big/Spikes_Active.png"
#  define IMG_SPIKES_D "./img/big/Spikes.png"
#  define IMG_FOX_U "./img/big/Fox_Up.png"
#  define IMG_FOX_D "./img/big/Fox_Down.png"
#  define IMG_RAT_L "./img/big/Mouse_Left.png"
#  define IMG_RAT_R "./img/big/Mouse_Right.png"
# else
#  define IMG_RABBIT_D "./img/big/Rabbit_Avatar.png"
#  define IMG_RABBIT_L "./img/big/Rabbit_Avatar.png"
#  define IMG_RABBIT_R "./img/big/Rabbit_Avatar.png"
#  define IMG_RABBIT_U "./img/big/Rabbit_Avatar.png"
#  define IMG_RABBIT_KO "./img/big/Rabbit_Avatar_Dead.png"
#  define IMG_CARROT "./img/big/CarrotP.png"
#  define IMG_SPIKES_U "./img/big/SpikesP.png"
#  define IMG_SPIKES_D "./img/big/SpikesP.png"
#  define IMG_FOX_U "./img/big/Fox_Avatar.png"
#  define IMG_FOX_D "./img/big/Fox_Avatar.png"
#  define IMG_RAT_L "./img/big/Mouse_Avatar.png"
#  define IMG_RAT_R "./img/big/Mouse_Avatar.png"
# endif
#endif
