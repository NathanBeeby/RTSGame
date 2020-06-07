#include "PathWaypoints.h"



void PathWaypoints::initVariables()
{
}

void PathWaypoints::initWaypoints()
{
}

PathWaypoints::PathWaypoints()
{
	this->initVariables();
	this->initWaypoints();
}


PathWaypoints::~PathWaypoints()
{
}

const int PathWaypoints::getWayPointSize() const
{
	return this->waypoints.size();
}

void PathWaypoints::AddWayPoint(sf::Vector2i way)
{
	waypoints.push_back(way);
}

void PathWaypoints::DeleteWayPoint(int way)
{
	waypoints.erase(waypoints.begin() + way);
}

void PathWaypoints::DeleteAllWayPoints()
{
	for (int i = 0; i < waypoints.size(); i++) {
		waypoints.erase(waypoints.begin() + i);
	}
}
