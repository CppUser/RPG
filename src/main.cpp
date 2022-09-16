#include <SFML/Graphics.hpp>
#include "Level/LevelParser.h"

#include "Hero.h"

int main()
{
	sf::Vector2i viewSize(800, 600);
	sf::VideoMode vm(viewSize.x, viewSize.y);
	// Create the main window
	sf::RenderWindow window(vm, "SFML window", sf::Style::Default);

	LevelParser levelData = LevelParser("Assets/Levels/Test.level");
	
	while (window.isOpen())
	{
		
		// Process events
		sf::Event event;
		while (window.pollEvent(event))
		{
			// Close window: exit
			if (event.type == sf::Event::Closed)
				window.close();

		}

		window.clear(sf::Color::Red);

		// Update the window
		window.display();

	}

	return EXIT_SUCCESS;
}




















//sf::Clock clock;

//Hero* m_Hero = new Hero("Assets/Character/CHARACTER_SPRITES/Blue/SingleCharacter.png");
//m_Hero->Spawn(sf::Vector2f(0, 420), 10);
//

///////////////Background//////////////////
//sf::Texture backgroundTex;
//sf::Sprite backgroundSprite;

////Load background Texture
//backgroundTex.loadFromFile("Assets/_11_background.png");
////Set and Attach Texture to Sprite
//backgroundSprite.setTexture(backgroundTex);

//float SCALE_X = (float)vm.width / (float)backgroundTex.getSize().x;
//float SCALE_Y = (float)vm.height / (float)backgroundTex.getSize().y;

//sf::Texture distSkyTex;
//sf::Sprite distSkySprite;

////Load background Texture
//distSkyTex.loadFromFile("Assets/_10_distant_clouds.png");
////Set and Attach Texture to Sprite
//distSkySprite.setTexture(distSkyTex);
//distSkySprite.scale(SCALE_X, SCALE_Y);
//

//sf::Texture distCloudsTex;
//sf::Sprite distCloudsSprite;

////Load background Texture
//distCloudsTex.loadFromFile("Assets/_09_distant_clouds1.png");
////Set and Attach Texture to Sprite
//distCloudsSprite.setTexture(distCloudsTex);
//distCloudsSprite.scale(SCALE_X, SCALE_Y);

//sf::Texture cloudsTex;
//sf::Sprite cloudsSprite;

////Load background Texture
//cloudsTex.loadFromFile("Assets/_08_clouds.png");
////Set and Attach Texture to Sprite
//cloudsSprite.setTexture(cloudsTex);
//cloudsSprite.scale(SCALE_X, SCALE_Y);

//sf::Texture hCloudTex;
//sf::Sprite hCloudSprite;

////Load background Texture
//hCloudTex.loadFromFile("Assets/_07_huge_clouds.png");
////Set and Attach Texture to Sprite
//hCloudSprite.setTexture(hCloudTex);
//hCloudSprite.scale(SCALE_X, SCALE_Y);

//sf::Texture hillTex;
//sf::Sprite hillSprite;

////Load background Texture
//hillTex.loadFromFile("Assets/_06_hill2.png");
////Set and Attach Texture to Sprite
//hillSprite.setTexture(hillTex);
//hillSprite.scale(SCALE_X, SCALE_Y);

//sf::Texture hill1Tex;
//sf::Sprite hill1Sprite;

////Load background Texture
//hill1Tex.loadFromFile("Assets/_05_hill1.png");
////Set and Attach Texture to Sprite
//hill1Sprite.setTexture(hill1Tex);
//hill1Sprite.scale(SCALE_X, SCALE_Y);

//sf::Texture bushesTex;
//sf::Sprite bushesSprite;

////Load background Texture
//bushesTex.loadFromFile("Assets/_04_bushes.png");
////Set and Attach Texture to Sprite
//bushesSprite.setTexture(bushesTex);
//bushesSprite.scale(SCALE_X, SCALE_Y);

//sf::Texture distTreesTex;
//sf::Sprite distTreesSprite;

////Load background Texture
//distTreesTex.loadFromFile("Assets/_03_distant_trees.png");
////Set and Attach Texture to Sprite
//distTreesSprite.setTexture(distTreesTex);
//distTreesSprite.scale(SCALE_X, SCALE_Y);

//sf::Texture treesTex;
//sf::Sprite treesSprite;

////Load background Texture
//treesTex.loadFromFile("Assets/_02_treesandbushes.png");
////Set and Attach Texture to Sprite
//treesSprite.setTexture(treesTex);
//treesSprite.scale(SCALE_X, SCALE_Y);

//sf::Texture groundTex;
//sf::Sprite groundSprite;

////Load background Texture
//groundTex.loadFromFile("Assets/_01_ground.png");
////Set and Attach Texture to Sprite
//groundSprite.setTexture(groundTex);
//groundSprite.scale(SCALE_X, SCALE_Y);
//

///////////////////////////////////////////

//sf::Texture characterTex;
//sf::Sprite characterSprite;

////Load background Texture
//characterTex.loadFromFile("Assets/Character/CHARACTER_SPRITES/Blue/SingleCharacter.png");
////Set and Attach Texture to Sprite
//characterSprite.setTexture(characterTex);
//characterSprite.setPosition(sf::Vector2f(viewSize.x / 2, viewSize.y - 150));
//characterSprite.setOrigin(characterTex.getSize().x / 2, characterTex.getSize().y / 2);

//sf::Vector2f characterPosition;
//bool characterMoving = false;

//// Start the game loop
//while (window.isOpen())
//{
//	sf::Time dt = clock.restart();

//	// Process events
//	sf::Event event;
//	while (window.pollEvent(event))
//	{
//		// Close window: exit
//		if (event.type == sf::Event::Closed)
//			window.close();

//		/*if (event.type == sf::Event::KeyPressed)
//		{
//			if (event.key.code == sf::Keyboard::Right)
//			{
//				characterMoving = true;
//			}
//		}
//		if (event.type == sf::Event::KeyReleased)
//		{
//			if (event.key.code == sf::Keyboard::Right)
//			{
//				characterMoving = false;
//			}
//		}*/

//		if (event.type == sf::Event::KeyPressed)
//		{
//			m_Hero->HandleInput(&event.key.code,true);
//		}
//		else
//		{
//			m_Hero->HandleInput(nullptr, false);
//		}
//		/*if (event.type == sf::Event::KeyReleased)
//		{
//			m_Hero->HandleInput(event.key.code, false);
//		}*/
//		
//		
//	}

//	/*if (characterMoving)
//	{
//		characterSprite.move(100.0f * dt.asSeconds(), 0);
//	}*/

//	
//	m_Hero->Update(dt.asSeconds());

//	// Clear screen
//	window.clear(sf::Color::Red);

//	window.draw(backgroundSprite);
//	window.draw(distSkySprite);
//	window.draw(distCloudsSprite);
//	window.draw(cloudsSprite);
//	window.draw(hCloudSprite);
//	window.draw(hillSprite);
//	window.draw(hill1Sprite);
//	window.draw(bushesSprite);
//	window.draw(treesSprite);
//	window.draw(groundSprite);
//	window.draw(m_Hero->GetSprite());
//	//window.draw(characterSprite);

//	/*window.draw(rectangle);
//	window.draw(circle);*/