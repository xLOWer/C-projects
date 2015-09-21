#include <iostream>
#include <windows.h>
#include <tchar.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

class SnakeGame {
	
	public: class sPos{
		double x, y;
		
		public: int getX(){return (int)x;}
		public: void setX(double _X){x = _X;}
		
		public: int getY(){return (int)y;}
		public: void setY(double _Y){y = _Y;}
	};
	
	sPos head;
	sPos eat;
	
	static const int UP = 0, RIGHT = 1, BOT = 2, LEFT = 3;
	
	int size, speed, snake[50][50], direction;
	//snake** - eat=2, snake=1, empty=0
	
	SnakeGame(){}
	~SnakeGame();
	
	public: void move(int);
	
	public: void setPosRand(void){
		
	}
	
	public: int getDirection(void){return direction;}
	public: void setDirection(int _direction){direction = _direction;}
	
	public: int getSnake(void){return **snake;}
	public: void setSnake(int **_snake){**snake = **_snake;}
	
	public: int getSize(void){return size;}
	public: void setSize(int _size){size = _size;}
	
	public: int getSpeed(void){return speed;}
	public: void setSpeed(int _speed){speed = _speed;}
	
};
