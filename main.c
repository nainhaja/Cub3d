/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nainhaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 18:17:29 by nainhaja          #+#    #+#             */
/*   Updated: 2020/03/09 18:17:47 by nainhaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "get_next_line.h"
#include "mlx.h"
#include <stdio.h>
#include <fcntl.h>
#include <math.h>
# define M_PI		3.14159265358979323846
#define RAD(x) (x * M_PI / 180)
#define K_UP 65362
#define K_DOWN 65364
#define K_LEFT 65361
#define K_RIGHT 65363
#define DEG(x) (x * 180 / M_PI)
typedef struct{
	float x;
	float y;
	float rotationangle;
	int walkdirection;
	int turndirection;
}Player;
Player P;
typedef struct{
	float x;
	float y;
	float xstep;
	float ystep;
	float distance;
}HV;
HV Horizontal,Vertical;
typedef struct{
	int x;
	int y;
	int *tex_data;
	void *img_ptr;
	int size_line;
	int endian;
	int bits;
	double ray_distanceV;
	double ray_distanceH;
	float wall_height;
	int textoffsetx;
	int textoffsety;
	double ray_distance;
	float hy;
	float vx;
	float hx;
	float vy;
	int start;
	int end;
}ImgPtr;
ImgPtr NO,SO,WE,EA,sprite;
int width,length;
float cloamari;// = 60 / width;
float xx = 0;
float yy = 0,px = 0,py = 0;
int width_max,length_max;
int bpp;
int *img_data;
int *tex_data;
int *tex_data2;
int size_line;
int endian;
int siz,endi,sizz,endii;
int *tx,*ty;
int p = 0,po = 0;
int a=0,h=0,k=0;
float cptt = 0;
char **b,**m;
int speed = 2;
int chadi,nizarr,salah;
int chadii,nizarrr,salahh;
void *mlx_ptr;
void *win_ptr;
void *img_ptr;
void *img_ptr2;
void *img_ptr3;
int guueer;
void			ft_putnbr(int a);
char			**ft_split(char const *s, char c);
int			ft_atoi(const char *str);

int z=1,o=0;
float s=0;
int ray_count;
float theta;
int guer=0;
int ft_checkv()
{
	 while(1)
	 {
		while(k <= a)
		{
			while(b[k][h] == '1' || b[k][h] == '0'|| b[k][h] == 'N' || b[k][h] == '2')
			{
				if(b[k][h] == '1' || b[k][h] == '2')
				{
					if((int)(Vertical.x - ((Vertical.xstep < 0) ? 64 : 0))/64 == h && (int)(Vertical.y)/64 == k)
					{
						if(b[k][h] == '2')
						{
							guer = 1;
							sprite.vy = (int)Vertical.y/64 * 64;
							sprite.vx = (int)Vertical.x/64 * 64;
							sprite.ray_distanceV = sqrtf(powf((P.y - Vertical.y),2) + powf((P.x - Vertical.x),2));
							//sprite.ray_distanceV = sqrtf(powf((P.y - Vertical.y),2) + powf((P.x - Vertical.x),2));
						}
							
						else
						{
							o = 1;
							break;
						}	
					} 
				}
				h++;
			}
			h = 0;      
			k++;
		}
		k = 0;
		h = 0;
		
		if(o == 1)
		{
			o = 0;
			return 0;
		}
		if((Vertical.y + Vertical.ystep)/64 > 0 && (Vertical.y + Vertical.ystep)/64 <= length_max)// && Vertical.x + Vertical.xstep > 0)
		{
			Vertical.x += Vertical.xstep;
			Vertical.y += Vertical.ystep;
		}
		else
		{
			if((Vertical.y + Vertical.ystep)/64 < 0)
			{
				Vertical.y = 0;
			}
			else if((Vertical.y + Vertical.ystep)/64 > length_max)
			{
				Vertical.y = (length_max+1)*64;
			}
			return 0;
		}
	 }
	 return 0;
}
int ft_checkh()
{
	while(1)
	 {
		while(k <= a)
		{
			while(b[k][h] == '1' || b[k][h] == '0'|| b[k][h] == 'N' || b[k][h] == '2')
			{
				if(b[k][h] == '1' || b[k][h] == '2')
				{ 
					if((int)(Horizontal.x)/64 == h && (int)(Horizontal.y - ((Horizontal.ystep < 0) ? 64 : 0))/64 == k)
					{
						if(b[k][h] == '2')
						{
							guueer = 1;
							sprite.hx = (int)Horizontal.x/64 * 64;
							sprite.hy = (int)Horizontal.y/64 * 64;
							sprite.ray_distanceH = sqrtf(powf((P.y - (Horizontal.y)),2) + powf((P.x - (Horizontal.x)),2));
						}	
						else
						{
							po = 2;
							break;
						}
						
					}
				}
				h++;
			}
			h = 0;      
			k++;
		}
		k = 0;
		h = 0;
		//printf("width %d\n",width_max);
		if(po == 2)
		{
			po = 0;
			return 0;
		}
		if((int)(Horizontal.y + Horizontal.ystep)/64 >= 0 && (int)(Horizontal.x + Horizontal.xstep)/64 >= 0 && (Horizontal.x + Horizontal.xstep)/64 <= width_max)
		{
			Horizontal.x += Horizontal.xstep;
			Horizontal.y += Horizontal.ystep;
			
		}else
		{
			if((Horizontal.x + Horizontal.xstep)/64 >= width_max)
			{
				Horizontal.x = width_max*64;
			}
				
			else if(Horizontal.x + Horizontal.xstep <= 0)
			{
				Horizontal.x = 0;
			}
			return 0;
		}		
		}
		return 0;
			
			
		
		
	 
	
}
void ft_raycast()
{
	if(sin(P.rotationangle) > 0)
	{
		Horizontal.y = (int)(P.y/64) * 64 + 64;
		Horizontal.ystep = 64 * 1;
	}
	else 
	{
		Horizontal.y = floor(P.y/64) * 64;
		Horizontal.ystep = 64 * -1;
	}
	if(cos(P.rotationangle) > 0)
	{
		Vertical.x = (int)(P.x)/64 * (64) + 64;
		Vertical.xstep = 64 * 1;
	}
	else 
	{
		Vertical.x = (int)(P.x)/64 * (64);
		Vertical.xstep = 64 * -1;
	}
	Horizontal.x = ((Horizontal.y - P.y + tan(P.rotationangle) * P.x) /tan(P.rotationangle));
	if(P.rotationangle == 0)
	{
		Horizontal.xstep = 0;
		Vertical.ystep = 0;
		Vertical.y = P.y - (P.x - Vertical.x);
	}
	else
	{
		Horizontal.xstep = Horizontal.ystep / tan(P.rotationangle);
		Vertical.ystep = (Vertical.xstep * tan(P.rotationangle));
		Vertical.y = P.y - (P.x - Vertical.x)*tan(P.rotationangle);
	}
	//Vertical.y = P.y - (P.x - Vertical.x)*tan(P.rotationangle);
	
	ft_checkh();
	ft_checkv();
}

void ft_pixel_put(int *img_data, int xt, int yt, int color)
{
	img_data[yt * width + xt] = color;
}

void ft_draw(void *mlx_ptr,void *win_ptr)
{
	int color = 0;
	int i=0,j=0,cpt=64,cpt1=64;
	while (k <= a)
	{
		while(b[k][h] == '1' || b[k][h] == '0'|| b[k][h] == 'N' || b[k][h] == '2')
		{
			if(b[k][h] == '0')
				color = 0xFFFFFF;
			else if(b[k][h] == '2')
			{
				color = 0xFFFFFF;
			}
				
			else if(b[k][h] == '1')
			{
				color = 0x6497b1;
			}
			else if(b[k][h] == 'N')
			{
				color = 0xFFFFFF;
				xx = (float)i;
				yy = (float)j;
			}
			while (i < cpt)
			{
				while(j < cpt1)
				{
					ft_pixel_put(img_data,i,j,color);
					j++;
				}
				j = j - 64;
				i++;
			}
			cpt = cpt + 64;
			h++;
		}
		i=0;
		j =j+64;
		cpt = 64;
		cpt1=cpt1+64;
		k++;
		h = 0;
	}
	k = 0;
	h = 0;
	mlx_put_image_to_window(mlx_ptr,win_ptr,img_ptr,0,0);
}

int key_press(int key)
{
	if(key == K_RIGHT)
		P.turndirection = 1;
	if(key == K_LEFT)
		P.turndirection = -1;
	if(key == K_UP)
		P.walkdirection = 1;
	if(key == K_DOWN)
		P.walkdirection = -1;
	//printf("%d \n",P.turndirection);
	return 0;
}
int key_release(int key)
{
	if(key == K_RIGHT)
		P.turndirection = 0;
	if(key == K_LEFT)
		P.turndirection = 0;
	if(key == K_UP)
		P.walkdirection = 0;
	if(key == K_DOWN)
		P.walkdirection = 0;
	return 0;   
}
int ft_checkneg(int chadi)
{
	if(chadi < 0)
		chadi = chadi * (-1);
	return chadi;
}
void DDA(int X0, int Y0, int X1, int Y1) 
{  
	int dx = X1 - X0; 
	int dy = Y1 - Y0; 
  
	int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy); 
  
	float Xinc = dx / (float) steps; 
	float Yinc = dy / (float) steps; 
  
	float X = X0; 
	float Y = Y0; 
	int i = 0;
	while(i < steps)
	{
		//mlx_pixel_put(mlx_ptr,win_ptr,X,Y,0xFF0000);
		ft_pixel_put(img_data,X,Y,0xFF0000);
		
		  // put pixel at (X,Y) 
		X += Xinc;           // increment in x at each step 
		Y += Yinc;           // increment in y at each step 
		//delay(100);          // for visualization of line- 
							 // generation step by step 
		i++;
	}
	
}

void	ft_draw_column(double rx, double ry, int Hvhit)
{
	double	ray_distance;
	double	wall_height;
	double	start;
	double	end;
	//double	step;
	//double	cstep;
	int		t_y = 0;
	ray_distance =  sqrtf(powf(px - rx, 2) + powf(py - ry, 2)); //cos(theta - P.rotationangle)
	//printf("%f --- %f\n",theta,P.rotationangle);
	wall_height = (64 / ray_distance) * ((width / 2) / tan(RAD(30))); 
	start = (length / 2) - (wall_height / 2) + 1;
	//step = 64 / wall_height; //replace 64 with image height
	if (start < 0)
		start = 0;
	end = (length / 2) + (wall_height / 2);
	/***** clear window for new frame *****/
	while (t_y < length)
		img_data[t_y++ * width + ray_count] = 0;
	/**********/
	int color;
	//printf("%d\n",ray_count);
	int textoffsetX;
	if(Hvhit == 1)
	{
		//ft_putnbr(Horizontal.x);
		//write(1,"\n",1);
		//printf("Horizental %d  %d \n ",(int)Horizontal.x,((int)Horizontal.x / 64));
		//color = 0xDCDCDC;
		textoffsetX = (int) Horizontal.x % 64;
	}
	else if(Hvhit == 2)
	{
		//color = 0xC0C0C0;
		textoffsetX = (int) Vertical.y % 64;
	}
	int mhah=start;
	while (mhah < end && mhah < length)
	{
		int distanceFromTop = mhah + (wall_height/2) - (length/2);
		int textoffsetY = distanceFromTop * (float)64/wall_height;
		unsigned int texelcolor;
		
		/*else
		{*/
			if(Hvhit == 1)
			{
				if(sin(P.rotationangle) > 0)
					texelcolor = NO.tex_data[(64*textoffsetY) + textoffsetX];
				else
					texelcolor = SO.tex_data[(64*textoffsetY) + textoffsetX];
			}
			else if(Hvhit == 2)
			{
				if(cos(P.rotationangle) > 0)
					texelcolor = EA.tex_data[(64*textoffsetY) + textoffsetX];
				else
				{
					texelcolor = WE.tex_data[(64*textoffsetY) + textoffsetX];
				}
			}	
		img_data[(int)mhah * width + ray_count] = texelcolor;

		mhah++;
	}
	
	//guer = 0;
	color = 0x696969;
	//int flooor = end;
	int ayoub = 0;
	while(ayoub < start)
	{
		
		img_data[(int)ayoub * width + ray_count] = 0x0000FF;
		ayoub++;

	}
	while(mhah < length)
	{
		img_data[(int)mhah * width + ray_count] = color;
		mhah++;
	}
}
void ft_draw_sprite_column()
{
	//double	ray_distance;
	double	wall_height;
	double	start;
	double	end;
	//double	step;
	//double	cstep;
	//int		t_y = 0;
	//int HVshit = sprite.ray_distanceH > sprite.ray_distanceV ? 1 : 2;

	//int color;
	//int textoffsetX;
	/*if(HVshit == 2)
	{
		wall_height = (64 / sprite.ray_distanceH) * ((width / 2) / tan(RAD(30))); 
		//textoffsetX = (int) sprite.hx % 64;
	}
	else
	{
		wall_height = (64 / sprite.ray_distanceV) * ((width / 2) / tan(RAD(30))); 
		//textoffsetX = (int) sprite.vy % 64;
	}*/
	wall_height = (64 / sprite.ray_distance) * ((width / 2) / tan(RAD(30))); 
	start = (length / 2) - (wall_height / 2) + 1;
	//step = 64 / wall_height; //replace 64 with image height
	if (start < 0)
		start = 0;
	end = (length / 2) + (wall_height / 2);
	/***** clear window for new frame *****/
	/*while (t_y < length)
		img_data[t_y++ * width + ray_count] = 0;*/
	int mhah=start;
	while (mhah < end && mhah < length)
	{
		/*int distanceFromTop = mhah + (wall_height/2) - (length/2);
		int textoffsetY = distanceFromTop * (float)64/wall_height;
		unsigned int texelcolor;*/
		
		/*else
		{*/
		//texelcolor = sprite.tex_data[(64*textoffsetY) + textoffsetX];
		//if(texelcolor != 0x000000)
			img_data[(int)mhah * width + ray_count] = 0x000000;

		mhah++;
	}
	//guer = 0;
}

int ft_grr()
{
	double rx;
	double ry;

	px = P.x;
	py = P.y;
	double dis;
	Horizontal.distance = sqrtf(powf((py - Horizontal.y),2) + powf((px - Horizontal.x),2));
	Vertical.distance = sqrtf(powf((py - Vertical.y),2) + powf((px - Vertical.x),2));
	int HvHit = 0;
	if(Horizontal.distance < Vertical.distance)
	{
		dis = Horizontal.distance;
		rx = Horizontal.x;
		ry = Horizontal.y;
		HvHit = 1;
		//DDA(P.x,P.y,rx,ry);
		}
	else
	{
		rx = Vertical.x;
		ry = Vertical.y;
		dis = Vertical.distance;
		HvHit = 2;
		//DDA(P.x,P.y,rx,ry);
	}
	//int hvHits = 0;
	
	//ft_draw(mlx_ptr,win_ptr);
	ft_draw_column(rx, ry,HvHit);
	if(guer == 1 || guueer == 1)
	{
		/*if(guer == 1 && guueer == 1)
		{
		if(sprite.ray_distanceH < sprite.ray_distanceV)
		{
			sprite.ray_distance = sprite.ray_distanceH;
			hvHits = 1;
		}
			
		else
		{
			hvHits = 2;
			sprite.ray_distance = sprite.ray_distanceV;
		}
		}
		else
		{*/
			if(guer == 1)
			{
				if(cos(P.rotationangle) > 0)
				{
					sprite.x = sprite.vx;
					sprite.y = sprite.vy;
				}
				else
				{
					sprite.x = sprite.vx - 64;
					sprite.y = sprite.vy;
					
				}
				
				
				sprite.ray_distance = sprite.ray_distanceV;
			}
				
			else if (guueer == 1)
			{
				if(sin(P.rotationangle) > 0)
				{
					sprite.x = sprite.hx;
					sprite.y = sprite.hy;
				}
				else
				{
					sprite.x = sprite.hx;
					sprite.y = sprite.hy - 64;
					
				}
				
				sprite.ray_distance = sprite.ray_distanceH;
			}
				
		//}
		
		
		if(sprite.ray_distance < dis)
		{
			/*int toto = sprite.x;
			int benj = sprite.y;
			int tach = toto +64;
			int koka = benj + 64;
			while((toto) < tach)
			{
				while((benj) < koka)
				{
					ft_pixel_put(img_data,toto,benj,0x000000);
					benj++;
				}
				benj = benj - 64;
				toto++;
			}*/
			//ft_pixel_put(img_data,sprite.x + 32,sprite.y + 32,0x008000);
			sprite.ray_distance = sqrtf(powf((P.y - (sprite.y + 32)),2) + powf((P.x - (sprite.x + 32)),2));;
			ft_draw_sprite_column();
		}
			
	}
		guueer = 0;
	guer =0;
	
	return 0;
}





int		update()
{
	mlx_hook(win_ptr,2,0,key_press,0);
	mlx_hook(win_ptr,3,0,key_release,0);
	//int toto = 0;
	//ft_draw(mlx_ptr,win_ptr);
	P.rotationangle -= P.turndirection * cloamari*(M_PI / 18) * 8;
	if (P.rotationangle < 0)
		P.rotationangle = 2 * M_PI + P.rotationangle;
	P.rotationangle = fmod(P.rotationangle, 2 * M_PI);
	P.x += ((cos(P.rotationangle)) * 4 * P.walkdirection);
	P.y += ((sin(P.rotationangle)) * 4 * P.walkdirection);
	//ft_putnbr(P.walkdirection);
	while(k <= a)
	{
		while(b[k][h] == '1' || b[k][h] == '0'|| b[k][h] == 'N' || b[k][h] == '2')
		{
			if(b[k][h] == '1')
			{
				if((int)P.x/64 == h && (int)P.y/64 == k)
				{
					P.x -= (cos(P.rotationangle)) * 4 * P.walkdirection;
					P.y -= (sin(P.rotationangle)) * 4 * P.walkdirection;
				}
			}
			h++;
		}
		h = 0;      
		k++;
	}
	k = 0;
	h = 0;
	p=20;
	s = -30;
	z = 1;
	ray_count = 0;
	theta = P.rotationangle;
	P.rotationangle -= RAD(30);
	while(s < 30) 
	{
		P.rotationangle +=  cloamari *(M_PI / 180);
		ft_raycast();
		p = 0;
		ft_grr();
		p = 0;
		ray_count++;
		s += cloamari;
	}
	//printf("%d \n",ray_count);
	mlx_put_image_to_window(mlx_ptr,win_ptr,img_ptr,0,0);
	P.rotationangle = theta;
	return 0;
}

int    ft_stock(char **stock,char *t,int c)
{
	int mi = 0;
	int mj = 0;
	int ab=0;
	   stock= ft_split(t,' ');
	   b[a] = malloc(sizeof(char) * 30);
		while(stock[mj]!= NULL)
		{
			while (stock[mj][mi] != '\0')
			{
				b[a][ab] = stock[mj][mi];
				if(b[a][ab] == 'N')
				{
					xx = ab;
					yy = a;
				}
				mi++;
				ab++;
			}
			mj++;
			mi = 0;
		}
		width_max = ab+1;
		b[a][ab] = '\0';
		
		int toto=0;
		if(a == 0)
		{
			while(b[a][toto] == '1')
			{
				toto++;
			}
			if(toto != ab)
			{
				
				return 1;
			}
				
		}
		mj = 0;
	   ab = 0;
		if(c == 0)
			a++;
		return 0;
}
int ft_stockDetails(char **Det,char *t)
{
	int mj=0;
	//int mi=0;
	int cpt=0;
	Det= ft_split(t,' ');
	while(Det[mj]!= NULL)
	{
		//while (cpt < 3)
		//{
			m[cpt] = Det[mj];
			/*if(b[a][ab] == 'N')
			{
				xx = ab;
				yy = a;
			}*/
			cpt++;
			//mi++;
			mj++;
			
		/*}
		mj++;
		mi = 0;*/
	}
	if(cpt != 3)
				return 1;
	return 0;
}
int main()
{
	char *t; 
	b = malloc(sizeof(char**) * 15);
	m = malloc(sizeof(char**) * 3);
	char **stock;
	char **stockk;
	//width = 1920;
	//length = 1080;
	
	int fd1 = open("text.txt", O_RDONLY);
	
	//int color = 0;
	
	
	while (get_next_line(fd1,&t))
	{
		if(t[0] != '\0' )
		{
			if(t[0] == 'R')
			{
				if(ft_stockDetails(stockk,t) == 1)
					{
						printf("error");
						return 0;
					}
				width = ft_atoi(m[1]);
				length = ft_atoi(m[2]);
				cloamari = 60 / (float)width;
				
			}
			else if(ft_stock(stock,t,0) == 1)
				{
				printf("ERROR ");
				return 0;
				}
		}
		
	}
	printf("%d %d",width,length);
	//int jj;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr,width,length,"mlx 42");
	img_ptr =  mlx_new_image(mlx_ptr,width,length);
	img_data = (int*)mlx_get_data_addr(img_ptr,&bpp,&size_line,&endian);
	NO.img_ptr = mlx_xpm_file_to_image(mlx_ptr, "greystone.xpm",&NO.x,&NO.y);
	SO.img_ptr = mlx_xpm_file_to_image(mlx_ptr, "colorstone.xpm",&SO.x,&SO.y);
	NO.tex_data = (int*)mlx_get_data_addr(NO.img_ptr,&NO.bits,&NO.size_line,&NO.endian);
	SO.tex_data = (int*)mlx_get_data_addr(SO.img_ptr,&SO.bits,&SO.size_line,&SO.endian);
	WE.img_ptr = mlx_xpm_file_to_image(mlx_ptr, "mossy.xpm",&WE.x,&WE.y);
	EA.img_ptr = mlx_xpm_file_to_image(mlx_ptr, "eagle.xpm",&EA.x,&EA.y);
	WE.tex_data = (int*)mlx_get_data_addr(WE.img_ptr,&WE.bits,&WE.size_line,&WE.endian);
	EA.tex_data = (int*)mlx_get_data_addr(EA.img_ptr,&EA.bits,&EA.size_line,&EA.endian);
	sprite.img_ptr = mlx_xpm_file_to_image(mlx_ptr, "barrel.xpm",&sprite.x,&sprite.y);
	sprite.tex_data = (int*)mlx_get_data_addr(sprite.img_ptr,&sprite.bits,&sprite.size_line,&sprite.endian);
	
	ft_stock(stock,t,1);
	length_max = a+1;
	P.rotationangle =   M_PI / 2;
	P.x = xx * 64;
	P.y = yy * 64;
	//ft_draw(mlx_ptr,win_ptr);
	//mlx_key_hook(win_ptr,key_press,(void*)0);
	mlx_loop_hook(mlx_ptr,update,(void*)0);
	mlx_loop(mlx_ptr);
   
}
