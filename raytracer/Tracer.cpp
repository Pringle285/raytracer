#include "Tracer.h"
#include "GeoIntersections.h"
#include <iostream>

glm::vec3 Tracer::traceRay(std::shared_ptr<Ray> ray)
{
	std::shared_ptr<GeoIntersections> geoInt = std::make_shared<GeoIntersections>();
	
	//adding some spheres to the vector
	std::shared_ptr<Sphere> sphere1 = std::make_shared<Sphere>();
	sphere1->setSphereRadius(2.0f);
	sphere1->setSphereCentre(glm::vec3(0, 0, -10.0f));
	sphere1->setBasicColor(glm::vec3(1, 0, 0));
	std::shared_ptr<Sphere> sphere2 = std::make_shared<Sphere>();
	sphere2->setSphereRadius(0.5f);
	sphere2->setSphereCentre(glm::vec3(0.8f,0, -5.0f));
	sphere2->setBasicColor(glm::vec3(0, 0, 1));
	sphereList.push_back(sphere1);
	sphereList.push_back(sphere2);

	//looping through list of spheres

	//need variable for distance here
	float lowestIntersectDist = 1000.0f;
	glm::vec3 color(0, 0, 0);
	color = glm::vec3(0, 1, 0);
	std::shared_ptr<Sphere> closestSphere;
	for (std::vector<std::shared_ptr<Sphere>>::iterator it = sphereList.begin(); it < sphereList.end(); it++)
	{
		
		std::shared_ptr<RaySphereDetails> det = geoInt->raySphereIntersection(ray, (*it)->getSphereCentre(), (*it)->getSphereRadius());
		if (det->intersected == true)
		{
			//record object with lowest intersect distance
			//in here record distance from ray origin to intersection point
			//if distance recorded is smaller than the distance stored by the variable above this loop then replace that with the new smallest distance
			
			if (det->distanceToHit < lowestIntersectDist)
			{
				lowestIntersectDist = det->distanceToHit;
				closestSphere = (*it);
			}
			
			//std::cout << lowestIntersectDist << std::endl;
			
			color = glm::vec3(0, 0, 1);

		}
		else
		{
			
		}


	}
	
	if (closestSphere != NULL)
	{
		return closestSphere->getBasicColor() * 255.0f;
	}
	else
	{
		return color * 255.0f;
	}
	
	
}
