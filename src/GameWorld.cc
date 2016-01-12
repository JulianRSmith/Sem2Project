#include "GameWorld.h"

GLfloat delay = 10000/60; // in milliseconds

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


void GameWorld::rotateX(float angle) {
  std::cout<<"passed : = " <<  angle << std::endl;
   glm::vec3 unit_x_axis(1.0,0,0);
   glm::mat4 id(1.0);  
   model_matrix = glm::rotate(model_matrix , delay *  angle , unit_x_axis );
   glEnable(GL_DEPTH_TEST);
   glDrawArrays(GL_TRIANGLES,0,36);
}

void GameWorld::rotateY(float angle) {
  std::cout<<"passed : = " <<  angle << std::endl;
   glm::vec3 unit_y_axis(0,1.0,0);
   glm::mat4 id(1.0);  
   model_matrix = glm::rotate(model_matrix , delay *  angle , unit_y_axis );
   glEnable(GL_DEPTH_TEST);
   glDrawArrays(GL_TRIANGLES,0,36);
}

void GameWorld::Draw() {

  glUniformMatrix4fv(0,1,GL_FALSE,glm::value_ptr(model_matrix));

 asset_manager->Draw();
 
}
