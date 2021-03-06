/**
 * \class  Tank
 * \file   Tank.h
 * \author Daniel Holmes & Jonathan Gerrand
 * \date   2 September 2014
 * \brief  Child class for all tank objects
 */


#ifndef TANK_H_
#define TANK_H_

//Forward declarations

//Includes
#include "Movable.h"
#include "Collidable.h"
#include "Trackable.h"
#include "Structures.h"


class Tank: virtual public Movable, virtual public Collidable, public Trackable
{
public:

    ///Default Tank object constructor
    Tank(sf::Vector2f position, float rotation, entity_type tankOwner);
    ///Provided ownership
    virtual const entity_type& getType() const;
    ///Allow the object to be rendered
    virtual void draw();
    ///Forward movement for a tank entity
    virtual void moveForward();
    ///Backward movement for a tank entity
	virtual void moveBackward();
    ///Left rotation for a tank entity
	virtual void rotateLeft();
    ///Right rotation for a tank entity
	virtual void rotateRight();
    ///Provide the bounding box for the tank entity
	virtual const sf::FloatRect& getBoundingBox() const;
    ///Instruct the tank entity that it cannot move
	virtual void setBlocked();
	///Instruct the tank entity that it can move
	virtual void setUnblocked();
    ///Instruct the tank entity that it has collided with another object
	virtual void setCollided();
	///Determine the blocked state of the tank entity
	virtual const bool isBlocked();
    ///Boolean state of the tank entity's life
	virtual bool const isDeleted();
	///Get the current co-ordinates of Trackable object
    virtual const sf::Vector2f& getPosition();
    ///Get the current orientation of Trackable object
    virtual const float getOrientation();
    ///Retrieve the Tank Position
    virtual const sf::Vector2f& getDrawPosition();
    ///Recieve the Tank rotation
    virtual const float getDrawRotation();
	///Tank object destructor
    virtual ~Tank();

private:

    ///Movability of the Tank entity: 1 for blocked, 0 for free
    bool _blockedStatus;
    ///Collision state of the Tank Entity: 1 for collided, 0 for not
    bool _collidedStatus;
    ///The angle of rotation for the Tank entity
    float _rotation;
    ///SFML co-ordinate system for the Tank
    sf::Sprite _tank;
    ///Enumeration type defining the tank
    entity_type _type;
};

#endif // TANK_H_
