/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray0.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaadi <isaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 12:20:45 by isaadi            #+#    #+#             */
/*   Updated: 2020/01/29 21:24:57 by isaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include "include/m_header.h"

extern t_mlx g_x;

void	set_imgx(int x)
{
	if (!x)
	{
		IMGX = IMG[IN].x * fmod(IN == SO || IN == NO ? RXI : RYI, CS) / CS;
		IMGX = IN == WE || IN == SO ? IMG[IN].x - IMGX : IMGX;
		IMGX += pnret(IMG[IN].x - IMGX, 0, -1, 1);
	}
	else
		set_imgx_0(RT);
}

void	draw_column(void)
{
	TRDS = sqrt(pow(PX - RXI, 2) + pow(PY - RYI, 2)) / CS;
	RDS = cos(PT - RT) * TRDS;
	WH = (1 / RDS) * ((W / 2) / tan(RAD(60) / 2));
	STRT = (H / 2) - (WH / 2) + 1 + OFS;
	STEP = IMG[IN].y / WH;
	STRT = STRT < 0 ? 0 : STRT;
	END = (H / 2) + (WH / 2);
	if (IN != SP)
		set_imgx(0);
	else
		set_imgx(1);
	while (STRT - OFS < END && STRT >= 0 && STRT < H * 2)
	{
		CSTEP = ((STRT - OFS + WH / 2) - H / 2) * STEP;
		AFRAME[STRT * W + NR] = check_opacity(IMG[IN].pixel[CSTEP][IMGX]) ?
		shade(IMG[IN].pixel[CSTEP][IMGX], TRDS) : AFRAME[STRT * W + NR];
		STRT++;
	}
}

void	vray_hit(int x)
{
	t_vc	i;
	t_vec	os;

	os.x = pnret(DVX, 0.1, 0, -0.1);
	while (VXI > 0 && VXI / CS < MAPX && VYI > 0 && VYI / CS < MAPY)
	{
		i.x = VXI / CS;
		i.y = VYI / CS;
		if (MAP(i.x + os.x, i.y) == x)
		{
			INV = pnret(os.x, EA, 0, WE);
			break ;
		}
		VXI += DVX;
		VYI += DVY;
	}
}

void	hray_hit(int x)
{
	t_vc	i;
	t_vec	os;

	os.y = pnret(DHY, 0.1, 0, -0.1);
	while (HXI > 0 && HXI / CS < MAPX && HYI > 0 && HYI / CS < MAPY)
	{
		i.x = HXI / CS;
		i.y = HYI / CS;
		if (MAP(i.x, i.y + os.y) == x)
		{
			INH = pnret(os.y, SO, 0, NO);
			break ;
		}
		HXI += DHX;
		HYI += DHY;
	}
}

void	init_ray(void)
{
	HYI = floor(PY / CS + (sin(RT) > 0 ? 1 : 0)) * CS;
	HXI = (HYI - PY + tan(RT) * PX) / tan(RT);
	VXI = floor(PX / CS + (cos(RT) > 0 ? 1 : 0)) * CS;
	VYI = tan(RT) * (VXI - PX) + PY;
	DHY = CS * pnret(sin(RT), 1, 0, -1);
	DHX = tan(RT) ? DHY / tan(RT) : 0;
	DVX = CS * pnret(cos(RT), 1, 0, -1);
	DVY = DVX * tan(RT);
}
*/