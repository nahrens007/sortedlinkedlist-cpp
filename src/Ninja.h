/*
 * Ninja.h
 *
 *  Created on: Oct 19, 2016
 *      Author: nahrens
 */

#ifndef NINJA_H_
#define NINJA_H_

using namespace std;

class Ninja
{
	friend ostream &operator<<(ostream &, const Ninja &);
	friend istream &operator>>(istream &, Ninja &);

public:
	Ninja();
	Ninja(const int); // For enemies killed
	Ninja(const string &); // for name
	Ninja(const int, const string &); // Enemies killed and name
	Ninja(const Ninja &); // Copy constructor

	void setName(const string &);
	string getName() const;
	int getEnemiesKilled() const;
	void killedEnemy(); // Indicate the Ninja has killed another enemy
	void killedEnemy(const Ninja &); // This Ninja killed another Ninja
	void die(); // Indicate the Ninja has died

	//Enable comparison (compare enemies killed as well as name)
	bool operator<(const Ninja &) const;
	bool operator<=(const Ninja &) const;
	bool operator>(const Ninja &) const;
	bool operator>=(const Ninja &) const;
	bool operator==(const Ninja &) const;
	void operator=(const Ninja &);
private:
	string name;
	int enemiesKilled;
};

#endif /* NINJA_H_ */
