#include "Player.h"

mutex Playermtx;

Player::Player()
{
	playerBox = new Hitbox();
	type = 1;
	v_speed = 0;
	h_speed = 0;
	
}

Player::Player(Point2D pos, int newType, int newHspd, int newVspd, int newDelay)
{
	if (newType < PEROT || newType > BUG)
		*this = Player();
	else
	{
		type = newType;
		h_speed = newHspd;
		v_speed = newVspd;
		playerBox = new Hitbox(pos, PlayerWidth[type], PlayerHeight[type], 1, 1, 0);
		delay = newDelay;
		
	}


}

Player::~Player()
{
	if (playerBox != nullptr)
		delete playerBox;
}

void Player::generateAtrb(int newHspeed, int newVspeed, int newDelay)
{
	h_speed = newHspeed;
	v_speed = newVspeed;
	delay = newDelay;
}

void Player::set_position(int px, int py)
{
	playerBox->setUpLeft(Point2D(px, py));
}

Point2D Player::get_position()
{
	return playerBox->getUpLeft();
}

void Player::set_status(bool status)
{
	status = status;
}

int Player::get_delay()
{
	return delay;
}

void Player::set_type(short type)
{
	type = type;
}

short Player::get_type()
{
	return type;
}

void Player::set_height(int height)
{
	playerBox->setHeight(height);
}

int Player::get_height()
{
	return playerBox->getHeight();
}

void Player::set_width(int width)
{
	playerBox->setWidth(width);
}

int Player::get_width()
{
	return playerBox->getWidth();
}

void Player::set_size(int width, int height)
{
	set_width(width);
	set_height(height);
}

void Player::set_Vspeed(int vspeed)
{
	v_speed = vspeed;
}

int Player::get_Vspeed()
{
	return v_speed;
}

void Player::set_Hspeed(int hspeed)
{
	h_speed = hspeed;
}

int Player::get_Hspeed()
{
	return h_speed;
}

void Player::set_speed(int vspeed, int hspeed)
{
	set_Vspeed(vspeed);
	set_Hspeed(hspeed);
}

bool Player::get_impact()
{
	return playerBox->getColli();
}

void Player::set_impact(bool imp)
{
	playerBox->setColli(imp);
}

void Player::move_left(Lane* currentLane) //dthien
{
	int background_Color = currentLane->get_backgroundCoLor();
	int spd = h_speed;
	do
	{
		
			Draw(false, background_Color);
			int temp = get_position().getX() - 1;
			switch (currentLane->get_type())
			{
				case RAIL_WAY:
				{
					for (auto& it : currentLane->get_mobsList())
					{
						if (temp > it->get_position().getX() - 1 && temp < it->get_position().getX() + 40)
							temp += 1;
					}
					break;
				}

				case WATER:
				{
					for (auto& it : currentLane->get_mobsList())
						it->Draw_Right(1);
					break;
				}
				default: break;
			}
			set_position(temp > 1 ? temp : 1, get_position().getY());
			Draw(true, background_Color);
	} while (spd--);

}

void Player::move_right(Lane* currentLane) //dthien
{
	int background_Color = currentLane->get_backgroundCoLor();
	int spd = h_speed;
	do
	{
		
			Draw(false, background_Color);
			int temp = get_position().getX() + 1;
			
			switch (currentLane->get_type())
			{
				case RAIL_WAY:
				{
					for (auto& it : currentLane->get_mobsList())
					{
						if (temp > it->get_position().getX() - 1 && temp < it->get_position().getX() + 40)
							temp -= 1;
					}
					break;
				}
				case WATER:
				{
					for (auto& it : currentLane->get_mobsList())
						it->Draw_Right(1);
					break;
				}
				default: break;
			}
			set_position(temp < CONSOLE_WIDTH - 4 ? temp : CONSOLE_WIDTH - 4, get_position().getY());
			Draw(true, background_Color);
	} while (spd--);

}

void Player::move_up(vector<Lane*> lanelist) //dthien
{
	int spd = v_speed;
	while (spd--)
	{
		
			int lane = get_position().getY();
			int down = lane / 4 + 1;
			if (down >= lanelist.size()) down = lanelist.size() - 1;
			int up = lane / 4 - 1;
			if (up < 0) up = 0;
			Draw(false, lanelist[lane / 4]->get_backgroundCoLor());
			int temp = get_position().getY() - 4;

			if (lanelist[up]->get_type() == RAIL_WAY)
			{
				for (auto& it : lanelist[up]->get_mobsList())
				{
					if (get_position().getX() > it->get_position().getX() - 1 && get_position().getX() < it->get_position().getX() + 40)
						temp += 4;
				}
			}

			if (lanelist[lane / 4]->get_type() == WATER)
			{
				for (auto& it : lanelist[lane / 4]->get_mobsList())
					it->Draw_Right(1);
			}
			set_position(get_position().getX(), temp > 1 ? temp : 1);
			Draw(true, lanelist[up]->get_backgroundCoLor());
	}
}

void Player::move_down(vector<Lane*> lanelist) //dthien
{
	int spd = v_speed;
	while (spd--)
	{
		
			int lane = get_position().getY();
			int down = lane / 4 + 1;
			if (down >= lanelist.size()) down = lanelist.size() - 1;
			int up = lane / 4 - 1;
			if (up < 0) up = 0;
			Draw(false, lanelist[lane / 4]->get_backgroundCoLor());
			int temp = get_position().getY() + 4;
			if (lanelist[down]->get_type() == RAIL_WAY)
			{
				for (auto& it : lanelist[down]->get_mobsList())
				{
					if (get_position().getX() > it->get_position().getX() - 1 && get_position().getX() < it->get_position().getX() + 40)
						temp -= 4;
				}
			}

			if (lanelist[lane/4]->get_type() == WATER)
			{
				for (auto& it : lanelist[lane/4]->get_mobsList())
					it->Draw_Right(1);
			}
			set_position(get_position().getX(), temp < CONSOLE_HEIGHT - 1 ? temp : CONSOLE_HEIGHT - 1);
			Draw(true, lanelist[down]->get_backgroundCoLor());

	}
}

void Player::Draw(bool mode, int background_Color) //dthien
{
	switch (type)
	{
	case PEROT:
		UserInterface::DrawParrot(get_position().getX(), get_position().getY(), mode, background_Color); break;
	case PENGUIN:
		UserInterface::DrawPenguin(get_position().getX(), get_position().getY(), mode, background_Color); break;
	case CHICK:
		UserInterface::DrawChicken(get_position().getX(), get_position().getY(), mode, background_Color); break;
	case BEE:
		UserInterface::DrawBee(get_position().getX(), get_position().getY(), mode, background_Color); break;
	case DOGO:
		UserInterface::DrawDog(get_position().getX(), get_position().getY(), mode, background_Color); break;
	case BUG:
		UserInterface::DrawBug(get_position().getX(), get_position().getY(), mode, background_Color); break;
	default:break;
	}
}

Hitbox* Player::getHbox()
{
	return playerBox;
}




