#include "Ray.h"


glm::vec3 Ray::getOrigin()
{
	return origin;
}

glm::vec3 Ray::getDirection()
{
	return direction;
}

glm::vec4 Ray::getNear()
{
	return near;
}

glm::vec4 Ray::getFar()
{
	return far;
}

void Ray::setOrigin(glm::vec3 setterOrigin)
{
	origin = setterOrigin;
}

void Ray::setDirection(glm::vec3 setterDirection)
{
	direction = setterDirection;
}

void Ray::setNear(glm::vec4 setterNear)
{
	near = setterNear;
}

void Ray::setFar(glm::vec4 setterFar)
{
	far = setterFar;
}
