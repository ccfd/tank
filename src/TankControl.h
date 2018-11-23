#pragma once

#include <vector>
#include "Globals.h"

class LiveTank;

struct Pixel {
	double distance;
	double angle;
	tag_t tag;
};

class Sights : public std::vector< Pixel > {
public:
	static const int resolution;
	static const double alpha;
	Sights();
};

class TankControl
{
	friend LiveTank;
	bool canShootGun, canShootCannon;
	bool wannaShootGun, wannaShootCannon;
	int cannonAmmunition, gunAmmunition;
	double left, right, turn, lift;
	double headAngle, cannonAngle,azimuth;
	double hp;
public:
	static const int resolution;
	static const double alpha;
	TankControl();
	void Init();
	bool CanShootGun();
	void ShootGun();
	bool CanShootCannon();
	void ShootCannon();
	void SetEngines(double, double, double, double);
	double GetAzimuth();
	double GetHeadAngle();
	double GetCannonAngle();
	int GetCannonAmmunition();
	int GetGunAmmunition();
	double GetHP();
	~TankControl();
	Sights sights;
};
