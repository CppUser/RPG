#include "Actor.h"

void Actor::Spawn(sf::Vector2f position, float gravity)
{
	m_Position.x = position.x;
	m_Position.y = position.y;

	m_Gravity = gravity;

	m_Sprite.setPosition(m_Position);
}

sf::Vector2f Actor::GetCenter()
{
	return sf::Vector2f(m_Position.x + m_Sprite.getGlobalBounds().width / 2, 
		m_Position.y + m_Sprite.getGlobalBounds().height / 2);
}
