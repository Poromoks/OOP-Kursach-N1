#pragma once
#include "Entity.h"

class Rabbit : public Entity // ������������ �� Entity (��������)
{
public:
	Rabbit() { m_name = 'T'; }; // �����������
	bool OnFrame(int x, int y)	override;
	void Move()					override;
	Entity* Reproduction()		override;
	bool Eat(char name)			override;
	bool IsDead()				override;

private: // ������������
	float		m_Hunger				= 1;
	const float	m_ReproductionChance	= 25;
};