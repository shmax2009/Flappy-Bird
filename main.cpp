#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
int main()
{
	srand(static_cast<unsigned int>(time(0)));
	const float FPS =60.0f;
	int x=100,y=150;
	int x1=700,y1=375,x2=838,y2=127;
	float spF=0;
	int x_p;
	int type=0;
	float spp=2.5;
	float rsm=0;
	auto score =0;
	bool is_new_game_time_start=false;
	RenderWindow window(VideoMode(700,504),"Flappy Bird");
	window.setFramerateLimit(FPS);

	Font font;
	font.loadFromFile("./score.ttf");
	Text text;
	text.setFont(font);
	text.setPosition(10,10);
	text.setFillColor(Color::Red);

	Texture hero_texture;
	hero_texture.loadFromFile("./duck.png");

	Texture backGround_Texture;
	backGround_Texture.loadFromFile("./ff.png");

	Texture pipe_texture;
	pipe_texture.loadFromFile("./Pipe.png");

	Sprite hero;
	Sprite background;
	Sprite background1;
	Sprite pipe;
	Sprite pipe1;

	pipe1.setTexture(pipe_texture);
	pipe.setTexture(pipe_texture);
	pipe1.setRotation(180);
	pipe1.setPosition(x2,y2);
	pipe.setPosition(x1,y1);

	background.setTexture(backGround_Texture);
	background.setPosition(0,0);
	background.setScale(2.5,3);
        background1.setTexture(backGround_Texture);
        background1.setPosition(700,0);
        background1.setScale(2.5,3);

	hero.setTexture(hero_texture);
	hero.setPosition(x,y);
	hero.setScale(0.4,0.4);

	rsm-=10;
	Event ev;
	while(window.isOpen())
	{
		while(window.pollEvent(ev))
		{
			if(ev.type == Event::Closed)
				window.close();
			if(ev.type == Event::KeyPressed)
			{
				if(ev.key.code==Keyboard::Space)
					spF=-7.5;
				
			}
			if(ev.type == Event::KeyReleased)
			{
				if(ev.key.code == Keyboard::R)
				{
					is_new_game_time_start=false;
					hero.setPosition(x,y);
					pipe1.setPosition(x2,y2);
				        pipe.setPosition(x1,y1);
					background.setPosition(0,0);
					background1.setPosition(700,0);

				}
			}

		}
		type=rand() % 3+1;
		if(type == 1)
		{
			y2=202-rsm;
			y1=440+rsm;
		}
		if(type == 2)
		{
			y2=127-rsm;
			y1=375+rsm;
		}
		if(type == 3)
		{
			y2=62-rsm;
			y1=300+rsm;
		}
		spF+=0.5;
		hero.move(0,spF);
		hero.setRotation(static_cast<int>(spF -2.5) % 90);
		pipe.move(spp*-1,0);
		pipe1.move(spp*-1,0);
		spp+=0,004;
		background.move(-0.4,0);
		background1.move(-0.4,0);
		if(background.getPosition().x <=-700)
			background.setPosition(700,0);
		if(background1.getPosition().x <=-700)
                        background1.setPosition(700,0);
		x_p=pipe1.getPosition().x;
		if(x_p<0)
		{
			pipe.setPosition(x1,y1);
			pipe1.setPosition(x2,y2);
			score++;
		}
		if((hero.getPosition().y<=0) or (hero.getPosition().y>=432) or (is_new_game_time_start) or((hero.getGlobalBounds().intersects(pipe.getGlobalBounds()) or (hero.getGlobalBounds().intersects(pipe1.getGlobalBounds())))))
					{
					score=0;
					spp=2.5;
					window.clear();
					background.setPosition(0,0);
					window.draw(background);
					is_new_game_time_start=true;
					window.display();
					
					}
					else
					{
					text.setString("Score "+to_string(score));
					window.clear();
					window.draw(background1);
					window.draw(background);
					window.draw(pipe);
					window.draw(pipe1);
					window.draw(hero);
					window.draw(text);
					window.display();
					}


	}

return 0;

}
