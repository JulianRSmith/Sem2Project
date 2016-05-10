//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////// PYRAMIDASSET.H ////////////////////////////////////
///////////////////////////////////////////lr227//////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
#ifndef PYRAMIDASSET_H
#define PYRAMIDASSET_H

#include <vector>

#include <GL/gl.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>

#include "GameAsset.h"

class PyramidAsset : public GameAsset {
 public:
  PyramidAsset(glm::vec3, int, float, glm::vec3, glm::vec3);
  ~PyramidAsset();
  virtual void Draw(GLuint);
  void rotateX(float);
  float rf();
  glm::vec3 GetVec3();

  private:
  glm::vec3 position;
  GLuint element_buffer_length, color_buffer_length, vertex_buffer_length;
  GLuint vertex_buffer_token, color_buffer_token, element_buffer_token;
  void checkError(std::string file, int line);
  glm::mat4 translateMatrix;
  void UpdateBuffer(GLfloat);
};

#endif // PYRAMIDASSET_H
