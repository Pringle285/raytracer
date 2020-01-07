#include "Camera.h"
#include "Ray.h"
#include <GLM/gtc/matrix_transform.hpp>
#include <iostream>

std::shared_ptr<Ray> Camera::returnRay(glm::ivec2 pixelPos)
{
	std::shared_ptr<Ray> ray = std::make_shared<Ray>();

	glm::vec4 nearPos;
	glm::vec4 farPos;

	//viewport of w, h, n, f = 640, 480, 1, 1000
	nearPos.x = (((2.0 * pixelPos.x) - (2.0 * 0)) / screenX) - 1.0;
	nearPos.y = (((2.0 * pixelPos.y) - (2.0 * 0)) / screenY) - 1.0;
	//nearPos.x = (2.0f * (float)pixelPos.x / (float)screenX) - 1.0f;
	//nearPos.y = (2.0f * (float)pixelPos.y / (float)screenY) - 1.0f;
	nearPos.z = -1.0;
	nearPos.w = 1.0;
	
	farPos.x = nearPos.x;
	farPos.y = nearPos.y;
	farPos.z = 1.0;
	farPos.w = 1.0;
	

	nearPos = inverseProjectionMat * nearPos;
	farPos = inverseProjectionMat * farPos;
	
	nearPos = nearPos / nearPos.w;
	farPos = farPos / farPos.w;

	nearPos = inverseViewMat * nearPos;
	farPos = inverseViewMat * farPos;

	ray->setNear(nearPos);
	ray->setFar(farPos);
	ray->setOrigin(glm::vec4(nearPos));
	ray->setDirection(glm::normalize(farPos - nearPos));

	return ray;
}

Camera::Camera()
{
	//constructor, don't want this generating every pass
	projectionMat = glm::perspective(glm::radians(45.0f), screenX / screenY, 0.1f, 100.0f);
	inverseProjectionMat = glm::inverse(projectionMat);
	
	viewMat = glm::mat4(1.0);
	inverseViewMat = glm::inverse(viewMat);


}
