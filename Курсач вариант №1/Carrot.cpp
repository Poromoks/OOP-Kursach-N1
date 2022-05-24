#include "Carrot.h"

bool Carrot::OnFrame(int x, int y)
{
	if (m_x == x && m_y == y)
	{
		std::cout << m_name;
		return true;
	}
	return false;
}

void Carrot::Move()
{
	m_CurrentCycle += 1;
}

bool Carrot::Eat(char name)
{
	return false;
}

bool Carrot::IsDead()
{
	return m_CurrentCycle >= m_MaxCycle || m_isEaten;
}