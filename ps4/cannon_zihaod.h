#pragma once

struct obstacle
{
	double x;
	double y;
	double w;
	double h;
	bool hit;
};

struct intCoords 
{
	double x;
	double y;
};

obstacle ProduceObstacle(void);

void DrawObstacle(obstacle Obstacle);

void UpdateTarget(obstacle &Target);

void UpdatePlayer(double playerX, double playerY, double angle);

void UpdateMissile(int &missileTime, double &missileX0, double &missileY0, double &missileX, double &missileY, double &velocity, double &angle);

bool CheckHit(double missileX, double missileY, obstacle point);
