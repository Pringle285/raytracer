#include "GeoIntersections.h"
#include "Ray.h"
#include <cmath>
#include <iostream>

glm::vec3 GeoIntersections::closestPointOnLine(std::shared_ptr<Ray> ray, glm::vec3 queryPoint)
{
	glm::vec3 closestPoint = 
		ray->getOrigin() + (glm::dot(queryPoint - ray->getOrigin(), ray->getDirection()) * ray->getDirection());


	return closestPoint;
}

std::shared_ptr<RaySphereDetails> GeoIntersections::raySphereIntersection(std::shared_ptr<Ray> ray, glm::vec3 sphereCentre, float sphereRadius)
{
	//if vector P-X (x being closestPointOnLine) is <= sphereRadius then intersection is true
	//else false and move on. 
	std::shared_ptr<RaySphereDetails> details = std::make_shared<RaySphereDetails>();
	glm::vec3 closestPoint = glm::vec3(closestPointOnLine(ray, sphereCentre));
	
	//check if start of ray is inside sphere, if it is then provide 0 intersections
	if (glm::distance(ray->getOrigin(), sphereCentre) < sphereRadius)
	{
		details->intersected = false;
		return details;
	}

	float d = glm::distance(sphereCentre, closestPoint);
	//std::cout << "distance then sphereRadius: " << d << "   " << sphereRadius << std::endl;
	if (d <= sphereRadius)
	{
		//need to perform a check here to ensure the intersection is not behind the rays origin!

		//intersects
		details->intersected = true;
		//as intersected is true we also now need the distance to the intersection
		//intersection point would be closestPoint - 1/2 the triangle length in circle defined as X
		//a + (((P - a) dot n) - X)n   <- first intersection point
		//x = length between intersection point and closestPointOnLine to subtract for intersect position
		float x = sqrt((pow(sphereRadius, 2) - pow(d, 2)));
		//below uses the closestPoint and subtracts x(scalar of distance between closestpoint and intersection point)
		//multiplied by the direction of the ray to get the vector of magnitude and direction 
		//closest point - this new vector gives the point at the edge of the circle which is first
		//intersected with by the ray
		glm::vec3 closeIntersectionPoint(closestPoint - (x * ray->getDirection()));
		
		//distance as a magnitude rather than vector
		float dist = (glm::dot(sphereCentre - ray->getOrigin(), ray->getDirection()) - x);

		details->distanceToHit = dist;
	}
	else
	{
		//doesn't intersect
		//set intersected to false and move on
		details->intersected = false;
	}


	return details; 

}
