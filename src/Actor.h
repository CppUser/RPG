#pragma once
#include <SFML/Graphics.hpp>

class Actor
{
public:
	Actor() = default;
	virtual ~Actor() = default;

	void Spawn(sf::Vector2f position, float gravity);
	virtual void Update(float dt) = 0;
	virtual void HandleInput(sf::Keyboard::Key* key,bool keyPressed) = 0;

	sf::FloatRect GetPosition() { return m_Sprite.getGlobalBounds(); }
	sf::Vector2f GetCenter();
	virtual sf::Sprite GetSprite() { return m_Sprite; }
protected:
	sf::Texture m_Texture;
	sf::Sprite m_Sprite;
	sf::Vector2f m_Position;
	float m_Gravity;
	float m_Speed = 200;
};

