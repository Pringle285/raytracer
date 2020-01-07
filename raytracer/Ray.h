#include <GLM/glm.hpp>

class Ray
{
private:
	glm::vec3 origin;
	glm::vec3 direction;
	
	//normalised device coords, needs 4 componenets for mat4 calculations
	//4th component is w which always = 1 to ensure no changes to final mat4 row during calculations
	//near 0,0 pixel = (x=-1, y=1, z=-1, w=1)
	glm::vec4 near;
	glm::vec4 far;


public:
	glm::vec3 getOrigin();
	glm::vec3 getDirection();

	glm::vec4 getNear();
	glm::vec4 getFar();


	void setOrigin(glm::vec3 setterOrigin);
	void setDirection(glm::vec3 setterDirection);

	void setNear(glm::vec4 setterNear);
	void setFar(glm::vec4 setterFar);


};

