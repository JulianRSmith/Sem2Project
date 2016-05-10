//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////// MAIN.CC ///////////////////////////////////////
////////////////////////////////////////////jrs38/////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
// Followed the tutorial on OpenGl-Tutorial.org:                                        //
// http://www.opengl-tutorial.org/beginners-tutorials/tutorial-6-keyboard-and-mouse     //
//////////////////////////////////////////////////////////////////////////////////////////

#include "Camera.h"
#include <glm/ext.hpp>

Camera::Camera(){

          //                ( X  ,  Y  ,    Z  )
 	  camPos = glm::vec3(0.0f, 0.0f, -18.0f);
	  //                   (X,Y,Z)
	  direction = glm::vec3(0,0,0);
	  //               (X,Y,Z)
	  xAxis = glm::vec3(0,0,0);
	  //               (X,Y,Z)
	  yAxis = glm::vec3(0,0,0);

	  hAngle = 0;
	  vAngle = 0;

	  // Calculates the change in mouse position
          mouseDeltaX = 1;
	  mouseDeltaY = 1;

	  // The movement speed of the camera
	  cameraSpeed = 0.10;
}

glm::mat4 Camera::UpdateCameraPosition(Input input_Direction, int mouseX, int mouseY){

 
	mouseDeltaX = -mouseX;
	mouseDeltaY = -mouseY;

	hAngle += 0.01 * mouseDeltaX;
	
//////////////////////////////////////////////////////////////////////////////////////
// RESTRICT VIEW  ////////////////////////////////////////////////////////////////////
	if((vAngle + (0.01 * mouseDeltaY)) < 1 && (vAngle + (0.01 * mouseDeltaY)) > -1 ){
	  vAngle += 0.01 * mouseDeltaY;
        }
//////////////////////////////////////////////////////////////////////////////////////	

 
	direction = glm::vec3(cos(vAngle) * sin(hAngle),sin(vAngle),cos(vAngle) * cos(hAngle));
	xAxis = glm::vec3(sin(hAngle - 3.14/2.0f),0,cos(hAngle - 3.14/2.0f));
	yAxis = glm::cross(xAxis, direction);




//////////////////////////////////////////////////////////////////////////////////////
// CALCULATES THE POSITION OF THE CAMERA DEPENDING ON THE INPUT OF THE USER //////////
//////////////////////////////////////////////////////////////////////////////////////
 	if(input_Direction == UP){

	        camPos += glm::vec3(cos(vAngle) * sin(hAngle), 0,cos(vAngle) * cos(hAngle))* cameraSpeed;

	}else if(input_Direction == DOWN){

	        camPos -= glm::vec3(cos(vAngle) * sin(hAngle),0,cos(vAngle) * cos(hAngle))* cameraSpeed;

	}else if(input_Direction == LEFT){

	        camPos -= xAxis * cameraSpeed;

	}else if(input_Direction == RIGHT){

	        camPos += xAxis * cameraSpeed;
	}

	  return glm::lookAt(camPos, camPos + direction,yAxis);
 }


