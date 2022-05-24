#pragma once
#include "Entity.h"

class Wolf : public Entity // ������������ �� Entity (��������)
{
public:
	Wolf() { m_name = 'X'; }; // �����������
	Wolf(bool arrive); // ������������� �����������, ������� ������������ ��� �������� ������ ����� �� �����
	bool OnFrame(int x, int y)	override;
	void Move()					override;
	Entity* Reproduction()		override;
	bool Eat(char name)			override;
	bool IsDead()				override;

private: // ������������
	float		m_Hunger		= 1;
	const float	m_HungerRage	= 0.5;
	const int	m_MinAmount		= 5;
	const int	m_NeedEat		= 2;
	int			m_EatenAmount	= 0;
};