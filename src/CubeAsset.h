#ifndef CUBEASSET_H
#define CUBEASSET_H

#include <vector>

#include <GL/gl.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>

#include "GameAsset.h"

class CubeAsset : public GameAsset {
 public:
  CubeAsset(glm::vec3, int, float, glm::vec3, glm::vec3);
  ~CubeAsset();
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

#endif // CUBEASSET_H
