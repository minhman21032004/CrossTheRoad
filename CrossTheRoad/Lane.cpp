#include "Lane.h"


Lane::Lane()
{
	position = 0;
	type = 0;
	status = false;
	speed = 0;
	delay = 0;
	background_Color = GREEN;
}

Lane::Lane(int pos, int laneType, int spd, int dly)
{
	type = laneType;
	position = pos;
	speed = spd;
	delay = dly;
	status = false;
	switch (type) {
	case GRASS:
		break;
	case HIGH_WAY:
		generate_HighwayMobs();
		status = true;
		break;
	case REV_HIGH_WAY:
		generate_HighwayMobs();
		status = true;
		break;
	case WATER:
		generate_WaterMobs();
		break;
	case RAIL_WAY:
		generate_TrainMobs();
		break;
	default:
		break;
	}
}

Lane::Lane(const Lane& other)
{
	position = other.position;
	type = other.type;
	status = other.status;
	speed = other.speed;
	clearList();
	for (int i = 0; i < other.mobsList.size(); i += 1)
	{
		mobsList.push_back(other.mobsList[i]);
	}

}

Lane& Lane::operator=(const Lane& other)
{
	if (this != &other)
	{
		this->position = other.position;
		this->type = other.type;
		this->status = other.status;
		this->speed = other.speed;
		this->delay = other.delay;
		this->clearList();
		for (int i = 0; i < other.mobsList.size(); i += 1)
		{
			this->mobsList.push_back(other.mobsList[i]);
		}
	}
	return *this;
}

Lane::~Lane()
{
	clearList();
}

void Lane::set_position(int pos)
{
	position = pos;
}

int Lane::get_position()
{
	return position;
}

void Lane::set_type(int tpe)
{
	type = tpe;
}

int Lane::get_type()
{
	return type;
}

void Lane::set_stat(bool stats)
{
	status = stats;
}

bool Lane::get_stat()
{
	return status;
}




int Lane::get_speed()
{
	return speed;
}

void Lane::set_speed(int spd)
{
	speed = spd;
	for (int i = 0; i < mobsList.size(); i++) mobsList[i]->set_speed(spd);
}

int Lane::get_delay()
{
	return delay;
}

void Lane::set_delay(int dly)
{
	delay = dly;
}

int Lane::get_backgroundCoLor() //dthien
{
	if (type == GRASS) return GREEN;
	else if (type == HIGH_WAY || type == REV_HIGH_WAY) return BLACK;
	else if (type == WATER) return BLUE;
	else return LIGHTBLUE;
}

void Lane::clearList()
{
	for (int i = mobsList.size() - 1; i >= 0; i -= 1)
	{
		if (mobsList[i] != nullptr)
			delete mobsList[i];
		mobsList.pop_back();
	}
}

void Lane::generate_HighwayMobs(int red, int blu, int truk, int gap)
{
	mobsList.clear();
	int temp = 0;
	if (red < 0) red = 0;
	if (blu < 0) blu = 0;
	if (truk < 0) truk = 0;

	vector<int> Temp;
	while (red-- != 0)
		Temp.push_back(RED_CAR);
	while (blu-- != 0)
		Temp.push_back(BLUE_CAR);
	while (truk-- != 0)
		Temp.push_back(TRUCK);
	random_device rd;
	shuffle(Temp.begin(), Temp.end(), default_random_engine(chrono::system_clock::now().time_since_epoch().count()));

	for (auto& it : Temp)
	{
		
		switch (it)
		{
		case RED_CAR:
			mobsList.push_back(new Mob(Point2D(temp += gap, position), RED_CAR, speed, delay)); break;
		case BLUE_CAR:
			mobsList.push_back(new Mob(Point2D(temp += gap, position), BLUE_CAR, speed, delay)); break;
		case TRUCK:
			mobsList.push_back(new Mob(Point2D(temp += gap, position), TRUCK, speed, delay)); break;
		default:break;
		}
	}
}

void Lane::generate_TrainMobs(int num, int gap, int posX)
{
	mobsList.clear();
	if (num > 0)
	{
		do
		{
			mobsList.push_back(new Mob(Point2D(posX, position), TRAIN, 0, 0));
			posX += gap;
		} while (num -= 1);
	}
	
}

void Lane::generate_WaterMobs(int num, int gap, int posX)
{
	mobsList.clear();
	if (num > 0)
	{
		do
		{
			mobsList.push_back(new Mob(Point2D(posX, position), DUCK_WEED, 0, 0));
			posX += gap;
		} while (num -= 1);
	}
}

void Lane::add_WaterMobs(int posX)
{
	mobsList.push_back(new Mob(Point2D(posX, position), DUCK_WEED, 0, 0));
}

void Lane::Draw()
{
	switch (type)
	{
	case GRASS:
		UserInterface::DrawSafeLane(0, get_position(), WHITE); break;
	case HIGH_WAY:
		UserInterface::DrawRoadLane(0, get_position(), WHITE); break;
	case REV_HIGH_WAY:
		UserInterface::DrawRoadLane(0, get_position(), WHITE); break;
	case WATER:
		UserInterface::DrawRiverLane(0, get_position(), WHITE); break;
	case RAIL_WAY:
		UserInterface::DrawTrainLane(0, get_position(), WHITE); break;
	}
	for (auto& it : mobsList)
		it->Draw_Right(1);
}

void Lane::run()
{
	trafficFlow += 1;
	if (status)
	{
		vector<thread> threadList;
		for (auto& it : mobsList)
		{
			switch (type)
			{
				case REV_HIGH_WAY:
				{
					threadList.push_back(thread(&Mob::move_left, &*(it)));
					break;
				}
				case HIGH_WAY:
				{
					threadList.push_back(thread(&Mob::move_right, &*(it)));
					break;
				}
			}
		}
		for (auto& it : threadList)
			Basic::joinThread(&it);
	}
	if (trafficFlow == speed)
	{
		status = false;
	}
	if (trafficFlow == pow(delay, 3))
	{
		status = true;
		trafficFlow = 0;
	}
}


vector<Mob*> Lane::get_mobsList()
{
	return mobsList;
}