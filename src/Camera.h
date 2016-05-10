#ifndef SRC_CAMERA_H_
#define SRC_CAMERA_H_

#include <glm/ext.hpp>
#include "common.h"

class Camera{

public:
	Camera();
	glm::mat4 UpdateCameraPosition(Input input_Direction, int mouseX, int mouseY);

private:

	float cameraPositionX;
	float cameraPositionY;
	float cameraPositionZ;
	glm::vec3 camPos;

	glm::vec3 direction;
	glm::vec3 xAxis;
	glm::vec3 yAxis;
        glm::vec3 ascend;

 	float hAngle;
 	float vAngle;
 
	float mouseDeltaX;
	float mouseDeltaY;

	float cameraMovementSpeed;


};


#endif

