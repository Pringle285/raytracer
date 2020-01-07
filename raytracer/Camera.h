#include <GLM/glm.hpp>
#include <memory>

class Ray;

class Camera
{
private:
	glm::mat4 viewMat;
	glm::mat4 inverseViewMat;
	glm::mat4 projectionMat;
	glm::mat4 inverseProjectionMat;

	float screenX = 640.0f;
	float screenY = 480.0f;


public:
	Camera();

	std::shared_ptr<Ray> returnRay(glm::ivec2 pixelPos);


};
