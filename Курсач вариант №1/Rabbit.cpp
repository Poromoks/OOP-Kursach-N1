#include "Rabbit.h"

bool Rabbit::OnFrame(int x, int y)
{
	if (m_x == x && m_y == y)
	{
		std::cout << m_name;
		return true;
	}
	return false;
}

void Rabbit::Move()
{
	int dx = m_x + (rand() % 2 ? 1 : -1);
	int dy = m_y + (rand() % 2 ? 1 : -1);

	if (dx < m_w && dx > 0)
		m_x = dx;

	if (dy < m_h && dy > 0)
		m_y = dy;

	m_Hunger -= 0.2;
}

Entity* Rabbit::Reproduction()
{
	if (rand() % 100 + 1 >= m_ReproductionChance)
	{
		m_Hunger -= 0.4;
		return new Rabbit;
	}

	return nullptr;
}

bool Rabbit::Eat(char name)
{
	if (name == 'P')
	{
		m_Hunger += 0.2;
		return true;
	}

	return false;
}

bool Rabbit::IsDead()
{
	return m_Hunger <= 0 || m_isEaten;
}