#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
class PathWaypoints
{
private:
	// Private Variables
	sf::Vector2i waypoint;

	// Initialization
	void initVariables();
	void initWaypoints();
public:
	// Constructor / Destructor
	PathWaypoints();
	virtual ~PathWaypoints();

	// Public Variables
	std::vector<sf::Vector2i> waypoints;

	// Accessprs
	const int getWayPointSize() const;

	// Public Functions
	void AddWayPoint(sf::Vector2i way);
	void DeleteWayPoint(int way);
	void DeleteAllWayPoints();
};

