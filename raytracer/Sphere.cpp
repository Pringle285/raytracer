#include "Sphere.h"
#include "Ray.h"

glm::ivec3 Sphere::shadePixel(Ray ray, glm::vec3 intersectionPoint)
{
	glm::vec3 color = glm::vec3(1, 0, 0);
	
	

	return convertColor255(color);
}


glm::ivec3 Sphere::convertColor255(glm::vec3 color)
{
	glm::vec3 convertedCol = glm::vec3(color.x * 255, color.y * 255, color.z * 255);

	return convertedCol;
}

glm::vec3 Sphere::getSphereCentre()
{
	return sphereCentre;
}

float Sphere::getSphereRadius()
{
	return sphereRadius;
}

void Sphere::setSphereCentre(glm::vec3 settingCentre)
{
	sphereCentre = settingCentre;
}

void Sphere::setSphereRadius(float setRadius)
{
	sphereRadius = setRadius;
}

glm::vec3 Sphere::getBasicColor()
{
	return basicColorSetting;
}

void Sphere::setBasicColor(glm::vec3 color)
{
	basicColorSetting = color;
}