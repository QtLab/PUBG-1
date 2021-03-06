#pragma once
#ifndef OBJ_H

#include <vector>
#include <glm\glm.hpp>
#include "Light.h"
//todo model, obb manager class
class Model {
public:
	bool nothing;
};
class OBB {
public:
	bool nothing;
};

class OBJ{
public:
	//path for loading model
	OBJ(glm::vec4 &location, std::string &path, bool anim);
	virtual ~OBJ();
	virtual void Draw(Light &l, glm::mat4x4 &view);
protected:
	//x,y,z,w
	glm::vec4 loc; 
	std::vector<Model*> model;
	OBB obb;
	bool isAnim;
};

class MovableOBJ: public OBJ {
public:
	MovableOBJ(glm::vec4 &direction, float speed, glm::vec4 &location, std::string &path, bool anim);
	virtual ~MovableOBJ();
	void Translate(glm::mat4x4 &mat);
	void Scale(glm::mat4x4 &mat);
	void Rotate(glm::mat4x4 &mat);
	bool DetectCollision(OBJ &obj);
	//keep or remove it
	void SetState();	
	bool GetState() const;
	// traverse all obj, detect collisions and update state and location
	virtual void Update();
	virtual void Draw(Light &l, glm::mat4x4 &view);
protected:
	//x,y,z,0
	glm::vec4 dir;
	float speed;
	//should be kept or removed from its manager
	bool isLived;	
};

class Bullet : public MovableOBJ {
public:
	Bullet(glm::vec4 &direction, float speed, glm::vec4 &location, std::string &path, bool anim);
	~Bullet();
};

class NPC : public MovableOBJ {
public:
	NPC(glm::vec4 &direction, float speed, glm::vec4 &location, std::string &path, bool anim);
	~NPC();
	void Run();
	void Stop();
	void SetDirection();
};

#endif // !OBJ_H



