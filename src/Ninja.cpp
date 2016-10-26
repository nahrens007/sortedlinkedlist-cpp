/*
 * Ninja.cpp
 *
 *  Created on: Oct 19, 2016
 *      Author: nahrens
 */

#include <iostream>
#include <iomanip>
#include "Ninja.h"

Ninja::Ninja() :
		name(), enemiesKilled(0)
{
	// empty constructor
}

Ninja::Ninja(const int enemiesKilled)
{
	// For enemies killed
	this->enemiesKilled = enemiesKilled;
}

Ninja::Ninja(const string &name) :
		enemiesKilled(0)
{
	this->name = name;
}
Ninja::Ninja(const int enemiesKilled, const string &name)
{
	// Enemies killed and name
	this->enemiesKilled = enemiesKilled;
	this->name = name;
}
Ninja::Ninja(const Ninja &otherNinja)
{
	// Copy constructor
	this->enemiesKilled = otherNinja.enemiesKilled;
	this->name = otherNinja.name;
}

void Ninja::setName(const string &name)
{
	this->name = name;
}
string Ninja::getName() const
{
	return this->name;
}
int Ninja::getEnemiesKilled() const
{
	return this->enemiesKilled;
}
void Ninja::killedEnemy()
{
	this->enemiesKilled++;
	// Indicate the Ninja has killed another enemy
	cout << this->name << " killed an anonymous enemy. Enemies killed: "
			<< this->enemiesKilled << endl;
}
void Ninja::killedEnemy(const Ninja &otherNinja)
{
	this->enemiesKilled++;
	cout << this->name << " killed " << otherNinja.name << ". Enemies killed: "
			<< this->enemiesKilled << endl;
}
void Ninja::die()
{
	// Indicate the Ninja has died
	cout << this->name << " has died. Enemies killed: " << this->enemiesKilled
			<< endl;
}

//Enable comparison (compare enemies killed)
bool Ninja::operator<(const Ninja &otherNinja) const
{
	if (this->enemiesKilled < otherNinja.enemiesKilled)
		return true;
	return false;
}

bool Ninja::operator<=(const Ninja &otherNinja) const
{
	if (this->enemiesKilled <= otherNinja.enemiesKilled)
		return true;
	return false;
}

bool Ninja::operator>(const Ninja &otherNinja) const
{
	if (this->enemiesKilled > otherNinja.enemiesKilled)
		return true;
	return false;
}
bool Ninja::operator>=(const Ninja &otherNinja) const
{
	if (this->enemiesKilled >= otherNinja.enemiesKilled)
		return true;
	return false;
}
bool Ninja::operator==(const Ninja &otherNinja) const
{
	if (this->enemiesKilled == otherNinja.enemiesKilled)
		return true;
	return false;
}
void Ninja::operator=(const Ninja &otherNinja)
{
	// Practically copy constructor
	this->enemiesKilled = otherNinja.enemiesKilled;
	this->name = otherNinja.name;
}

ostream &operator<<(ostream &output, const Ninja &ninja)
{
	output << ninja.name << " killed "
			<< ninja.enemiesKilled << " enemies..." << endl;
	return output;
}

istream &operator>>(istream &input, Ninja &ninja)
{
	input >> setw(4) >> ninja.name;
	return input;
}
