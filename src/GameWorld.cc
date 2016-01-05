#include "GameWorld.h"

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

void GameWorld::Draw() {
  asset_manager->Draw();
}
