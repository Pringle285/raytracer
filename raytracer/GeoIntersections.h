#include <GLM/glm.hpp>
#include <memory>

class Ray;

struct RaySphereDetails
{
	bool intersected;
	float distanceToHit;
};


class GeoIntersections
{
private:



public:
	glm::vec3 closestPointOnLine(std::shared_ptr<Ray> ray, glm::vec3 queryPoint);
	std::shared_ptr<RaySphereDetails> raySphereIntersection(std::shared_ptr<Ray> ray, glm::vec3 sphereCentre, float sphereRadius);


};
