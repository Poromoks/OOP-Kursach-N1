#pragma once
#include "Entity.h"

class Carrot : public Entity // наследование от Entity (сущности)
{
public:
	Carrot() { m_name = 'P'; }; // конструктор
	bool OnFrame(int x, int y)	override;
	void Move()					override;
	Entity* Reproduction()		override { return nullptr; };
	bool Eat(char name)			override;
	bool IsDead()				override;

private: // инкапсул€ци€
	int			m_CurrentCycle		= 0;
	const int	m_MaxCycle			= 5;
};