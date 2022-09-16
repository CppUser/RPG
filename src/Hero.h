#include "Actor.h"


class Hero : public Actor
{
public:
	Hero(std::string texturePath);
	virtual ~Hero() {}
	

	virtual void Update(float dt) override;
	virtual void HandleInput(sf::Keyboard::Key* key,bool keyPressed) override;

protected:
	bool m_HeroMovedLeft;
	bool m_HeroMovedRight;
};