#pragma once
#include <SDL.h>
#include "MoveDirection.h"
struct Laser
{
	Laser(SDL_Rect pos, int movementSpeed, MoveDirection dir)
	{
		m_pos = pos;
		m_movementSpeed = movementSpeed;
		m_dir = dir;
	}

	SDL_Rect m_pos; //vị trí
	int m_movementSpeed = 0; //tốc độ
	MoveDirection m_dir; //hướng di chuyển
};