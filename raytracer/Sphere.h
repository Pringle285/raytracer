#include <GLM/glm.hpp>

class Ray;

class Sphere
{
private:
	glm::vec3 sphereCentre;
	float sphereRadius;
	glm::vec3 basicColorSetting; 


public:
	//takes the ray and intersection point, returns a color
	glm::ivec3 shadePixel(Ray ray, glm::vec3 intersectionPoint);

	glm::ivec3 convertColor255(glm::vec3 color);

	glm::vec3 getSphereCentre();
	float getSphereRadius();
	void setSphereCentre(glm::vec3 settingCentre);
	void setSphereRadius(float setRadius);
	glm::vec3 getBasicColor();
	void setBasicColor(glm::vec3 color);

};
