#pragma once
#include "Entity.h"

class Wolf : public Entity // наследование от Entity (сущности)
{
public:
	Wolf() { m_name = 'X'; }; // конструктор
	Wolf(bool arrive); // перегруженный конструктор, который используется при создании нового волка на карте
	bool OnFrame(int x, int y)	override;
	void Move()					override;
	Entity* Reproduction()		override;
	bool Eat(char name)			override;
	bool IsDead()				override;

private: // инкапсуляция
	float		m_Hunger		= 1;
	const float	m_HungerRage	= 0.5;
	const int	m_MinAmount		= 5;
	const int	m_NeedEat		= 2;
	int			m_EatenAmount	= 0;
};