#pragma once
class GameObject;
class Pickable
{
public:
	virtual void affectOn(GameObject* changedObject) = 0;
};

