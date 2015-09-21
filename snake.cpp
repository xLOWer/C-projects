#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <math.h>

#include "additionals.h"

class SnakeGame 
{
	static const int UP = 0, RIGHT = 1, BOT = 2, LEFT = 3;
	static int xMaxSize, yMaxSize;
	
	class eat
	{
		int x, y;
		
		void NewPos()
		{
			this->x = rand()%xMaxSize;
			this->y = rand()%yMaxSize;
			//for()
		}
	};
	
	class snake
	{
		double speed;
		static int size, mem[1024][2];
		
		class head
		{
			int x, y, direction;
		};
		
		class part
		{
			int x, y;
		};
		
		void smove(int dir)
			{
				switch(dir)
				{
					case UP:	this->head.y--; break;
					case BOT: 	this->head.y++; break;
					case RIGHT: this->head.x++; break;
					case LEFT: 	this->head.x--; break;
					default: break;
				}
				if(this->head.x == SnakeGame.eat.x && this->head.y == SnakeGame.eat.y)
				{
					this->size++;
				}
				mem[size][0] = this->head.x;
				mem[size][1] = this->head.y;
			}
	};
	
	/*SnakeGame()//constructor
	{	
		this->snake.size = 0;
		this->snake.speed = 1;
		this->snake.head.direction = rand()%4;
		this->snake.head.x = rand()%xMaxSize;
		this->snake.head.y = rand()%yMaxSize;
		this->eat.NewPos();
	}*/
	/*~SnakeGame()//destructor
	{
	}	*/
};
