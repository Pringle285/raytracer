#include <GLM/glm.hpp>
#include <memory>
#include <vector>
#include "Sphere.h"

class Ray;
class Sphere;

class Tracer
{
private:
	std::vector<std::shared_ptr<Sphere>> sphereList;


public:
	//takes a ray and returns a vec3 color
	glm::vec3 traceRay(std::shared_ptr<Ray> ray);


};
