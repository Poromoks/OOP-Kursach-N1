#include <ctime>
#include <list>
#include "Rabbit.h"
#include "Carrot.h"
#include "Wolf.h"

using namespace std;

int main()
{
	srand(time(0));

	list <Entity*> entities;
	
	for (int i = 0; i < 5; i++)
		entities.push_back(new Carrot);

	for (int i = 0; i < 1; i++)
		entities.push_back(new Rabbit);

	for (int i = 0; i < 10; i++)
		entities.push_back(new Wolf);

	int seasonCounter = 0;

	while (true)
	{
		int time = clock();

		int wolfCounter = 0;

		list <Entity*> childs;

		for (const auto& entity : entities) // полиморфизм
		{
			if (entity->GetName() == 'X') // массивы указателей на объекты (на самом деле это список)
				wolfCounter++;

			Entity* child = entity->Reproduction();

			if (child != nullptr)
				childs.push_back(child);

			entity->Move();

			for (const auto& eaten : entities) // полиморфизм
			{
				if ((entity != eaten) && (entity->GetPosition() == eaten->GetPosition()))
					if (entity->Eat(eaten->GetName()))
						eaten->SetEaten();
			}
		}

		if (wolfCounter < 5)
			entities.push_back(new Wolf(true));

		for (auto it = entities.begin(); it != entities.end();) // полиморфизм и итератор
		{
			if ((*it)->IsDead())
				it = entities.erase(it);
			else
				it++;
		}

		seasonCounter++;

		if (seasonCounter == 10)
		{
			for (int i = 0; i < 5; i++)
				entities.push_back(new Carrot);
			seasonCounter = 0;
		}

		for (int y = 0; y != 29; y++)
		{
			for (int x = 0; x != 119; x++)
			{
				bool isNotEmpty = false;
				for (const auto& entity : entities)
				{
					isNotEmpty |= entity->OnFrame(x, y);
					if (isNotEmpty)
						break;
				}
				if (!isNotEmpty)
					cout << " ";
			}
			cout << endl;
		}

		int l = 0;

		while (l < 1)
		{
			int tick = clock();
			l = (tick - time) / CLOCKS_PER_SEC;
		}

		for (const auto& child : childs)
			entities.push_back(child);

		system("cls");
	}

	return 0;
}