#include "Wolf.h"

Wolf::Wolf(bool arrive) // перегруженный конструктор, который используется при создании нового волка на карте
{
	m_x = rand() % m_w + 1;
	m_y = m_h - 1;
}

bool Wolf::OnFrame(int x, int y)
{
	if (m_x == x && m_y == y)
	{
		std::cout << m_name;
		return true;
	}
	return false;
}

void Wolf::Move()
{
	int dx = (rand() % 2 ? 1 : -1);
	int dy = (rand() % 2 ? 1 : -1);

	if (m_Hunger < m_HungerRage)
	{
		dx *= 2;
		dy *= 2;
	}

	if (m_x + dx < m_w && m_x + dx > 0)
		m_x += dx;

	if (m_y + dy < m_h && m_y + dy > 0)
		m_y += dy;

	m_Hunger -= 0.2;
}

Entity* Wolf::Reproduction()
{
	if (m_EatenAmount >= m_NeedEat)
	{
		m_Hunger -= 0.4;
		m_EatenAmount = 0;
		return new Wolf;
	}

	return nullptr;
}

bool Wolf::Eat(char name)
{
	if (name == 'T')
	{
		m_Hunger += 0.2;
		m_EatenAmount += 1;
		return true;
	}

	return false;
}

bool Wolf::IsDead()
{
	return m_Hunger <= 0 || m_isEaten;
}