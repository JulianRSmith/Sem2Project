#include "GameWorld.h"

      /////////////////////////////////////////////////////////////////////
      /// VOXEL ARRAY /////////////////////////////////////////////////////
      /// If the coordinate equals 1, a cube is created /////////////// ///
      /////////////////////////////////////////////////////////////////////

GameWorld::GameWorld (ApplicationMode mode) {
  int pointA,pointB;
  int worldSpace = 11;
  int world[worldSpace][worldSpace] = {
    { 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1 } ,
    { 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0 } ,
    { 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1 } ,
    { 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0 } ,
    { 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0 } ,
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } ,
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } ,
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } ,
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } ,
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } ,
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
  };
  asset_manager = std::make_shared<GameAssetManager>(mode);
  for (pointA=0; pointA<worldSpace; pointA++)
  { for (pointB=0; pointB<worldSpace; pointB++)
    { if (world[pointB][pointA] == 1)
        { 
	  asset_manager->AddAsset(std::make_shared<CubeAsset>(pointA,-pointB));
        }
    }
  }
}

      /////////////////////////////////////////////////////////////////////
      /// ROTATE X ////////////////////////////////////////////////////////
      /// Function to rotate  the object along the X Axis /////////////////
      /////////////////////////////////////////////////////////////////////

void GameWorld::rotateX(float angle) {
   glm::vec3 unit_x_axis(1.0,0,0);
   glm::mat4 id(1.0);  
   model_matrix = glm::rotate(model_matrix , angle / 100 , unit_x_axis );
   glEnable(GL_DEPTH_TEST);
   glDrawArrays(GL_TRIANGLES,0,36);
}

      /////////////////////////////////////////////////////////////////////
      /// ROTATE Y ////////////////////////////////////////////////////////
      /// Function to rotate the object along the Y Axis //////////////////
      /////////////////////////////////////////////////////////////////////

void GameWorld::rotateY(float angle) {
   glm::vec3 unit_y_axis(0,1.0,0);
   glm::mat4 id(1.0);  
   model_matrix = glm::rotate(model_matrix , angle / 100 , unit_y_axis );
   glEnable(GL_DEPTH_TEST);
   glDrawArrays(GL_TRIANGLES,0,36);
}

      /////////////////////////////////////////////////////////////////////
      /// MOVE Z  /////////////////////////////////////////////////////////
      /// Function to rotate the object along the Z Axis //////////////////
      /////////////////////////////////////////////////////////////////////


void GameWorld::moveZ(float angle) {
   glm::vec3 unit_z_axis(0,0,1.0);
   glm::mat4 id(1.0);  
   model_matrix = glm::rotate(model_matrix , angle / 100 , unit_z_axis );
   glEnable(GL_DEPTH_TEST);
   glDrawArrays(GL_TRIANGLES,0,36);
}

      /////////////////////////////////////////////////////////////////////
      /// MOVE UP  ////////////////////////////////////////////////////////
      /// Function to rotate the object along both the X &  Y Axis ////////
      /////////////////////////////////////////////////////////////////////

void GameWorld::moveUp(float angle) {
   glm::vec3 unit_z_axis(1.0,1.0,0);
   glm::mat4 id(1.0);  
   model_matrix = glm::rotate(model_matrix , angle / 100 , unit_z_axis );
   glEnable(GL_DEPTH_TEST);
   glDrawArrays(GL_TRIANGLES,0,36);
}

void GameWorld::Draw() {

      /////////////////////////////////////////////////////////////////////
      /// SEND CHANGES TO SHADER  /////////////////////////////////////////
      /// The following line sends the chnage in axis to the shader  //////
      /////////////////////////////////////////////////////////////////////

  glUniformMatrix4fv(0,1,GL_FALSE,glm::value_ptr(model_matrix));

      /////////////////////////////////////////////////////////////////////
      /// DRAW OBJECT  ////////////////////////////////////////////////////
      /// The following line draws the object on the screen ///////////////
      /////////////////////////////////////////////////////////////////////
  
 asset_manager->Draw();
 
}
