#include "Hero.h"



Hero::Hero(std::string texturePath)
{
	m_Texture.loadFromFile(texturePath);
	m_Sprite.setTexture(m_Texture);
}



void Hero::Update(float dt)
{
	if (m_HeroMovedLeft)
	{
		m_Position.x -= m_Speed * dt;
	}

	if (m_HeroMovedRight)
	{
		m_Position.x += m_Speed * dt;
	}

	m_Sprite.setPosition(m_Position);
}

void Hero::HandleInput(sf::Keyboard::Key* key, bool keyPressed)
{
	if (*key == sf::Keyboard::A && keyPressed)
	{
		m_HeroMovedLeft = true;
	}
	else
	{
		m_HeroMovedLeft = false;
	}

	if (*key == sf::Keyboard::D && keyPressed)
	{
		m_HeroMovedRight = true;
	}
	else
	{
		m_HeroMovedRight = false;
	}
}

