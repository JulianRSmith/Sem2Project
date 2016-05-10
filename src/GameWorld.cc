#include "GameWorld.h"
#include "common.h"

      /////////////////////////////////////////////////////////////////////
      /// VOXEL ARRAY /////////////////////////////////////////////////////
      /// If the coordinate equals 1, a cube is created /////////////// ///
      /////////////////////////////////////////////////////////////////////
using namespace std;
GameWorld::GameWorld (ApplicationMode mode) : asset_manager (make_shared<GameAssetManager>(mode)){
  
  int X,Y;
  int Z = -1;
  int worldX = 11;
  int worldY = 11;
  
  int world[worldX][worldY] = {
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
  
 for( X=0; X<worldX; X++){
   for (Y=0; Y<worldY; Y++){
    if( world[Y][X] == 1){  
     asset_manager->AddAsset(make_shared<CubeAsset>((X)-(worldX/2.0f), -4.00f,(Z*Y)));
      asset_manager->AddAsset(make_shared<CubeAsset>((X)-(worldX/2.0f), 0.00f,(Z*Y)));
    }
   }
 }
}

void GameWorld::Draw() {
  asset_manager->Draw();
}

void GameWorld::UpdateCameraPosition(Input input_direction, int mouseX, int mouseY){
  asset_manager->UpdateCameraPosition(input_direction,  mouseX,  mouseY);
}
