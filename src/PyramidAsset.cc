//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////// PYRAMIDASSET.CC ////////////////////////////////////
///////////////////////////////////////////lr227//////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
#include "PyramidAsset.h"

      /////////////////////////////////////////////////////////////////////
      /// PYRAMID COORDINATES /////////////////////////////////////////////
      /// Collection of code which tells the system where to place each ///
      /// corner of the triangle in 3D space, e.g ( X axis, Y axis, Z /////
      /// axis) ///////////////////////////////////////////////////////////
      /////////////////////////////////////////////////////////////////////

PyramidAsset::PyramidAsset(glm::vec3 p,int type, float scale, glm::vec3 rotation, glm::vec3 speed) : GameAsset(p , type, scale, rotation, speed) {
  // model coordinates, origin at centre.
  GLfloat vertex_buffer [] {
    -0.5f + position.x, -0.5f + position.y, -0.5f + position.z //0
   ,-0.5f + position.x,  0.5f + position.y, -0.5f + position.z //1
   ,0.5f + position.x,-0.5f + position.y,-0.5f + position.z //2
   ,0.5f + position.x, 0.5f + position.y,-0.5f + position.z //3
   ,0.0f + position.x, 0.0f + position.y,0.5f + position.z //4
  };

      /////////////////////////////////////////////////////////////////
      /// PYRAMID BUFFER //// /////////////////////////////////////////
      /// Here the numbers represent each corner //////////////////////
      /// of the pyramid. In the case of a pyramid there //////////////
      /// are 5 in total, but the range here is 0 to 4 ////////////////
      /////////////////////////////////////////////////////////////////

  
  element_buffer_length = 18;
  GLuint element_buffer []  {
       0, 1, 3
       ,0, 2, 3
       ,0, 1, 4
       ,0, 2, 4
       ,1, 3, 4
        ,2, 3, 4
  };

  // Transfer buffers to the GPU
  //

  // create buffer
  glGenBuffers(1, &vertex_buffer_token);

  // immediately bind the buffer and transfer the data
  glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer_token);
  glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 18, vertex_buffer, GL_STATIC_DRAW);

  glGenBuffers(1, &element_buffer_token);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, element_buffer_token);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * element_buffer_length, element_buffer, GL_STATIC_DRAW);
}

PyramidAsset::~PyramidAsset() {
}

#ifdef DEBUG
#define checkGLError() checkError(__FILE__, __LINE__)
#else
// define symbol to be nothing
#define checkGLError()
#endif


/*void checkError(std::string file, int line) {
  GLenum gl_error = glGetError();
  if(GL_NO_ERROR != gl_error) {
    std::cerr << "GL error in " << file << " at line " << line << " error: " << gl_error << std::endl;
    exit(-1);
  }
  }*/

void PyramidAsset::Draw(GLuint program_token) {
  
  if(!glIsProgram(program_token)) {
    std::cerr << "Drawing Pyramid with invalid program" << std::endl;
    return;
  }
  
  GLint validation_ok;
  glValidateProgram(program_token);
  glGetProgramiv(program_token, GL_VALIDATE_STATUS, &validation_ok);
  if(!validation_ok) {
    GLint maxLength = 0;
    glGetProgramiv(program_token, GL_INFO_LOG_LENGTH, &maxLength);

    //The maxLength includes the NULL character
    std::vector<char> errorLog(maxLength);
    glGetProgramInfoLog(program_token, maxLength, &maxLength, &errorLog[0]);

    std::cerr << "Invalid program " << program_token << " with error code " << validation_ok << std::endl;
    for(auto c: errorLog) {
      std::cerr << c;
    }
    exit(-1);
  }


      ////////////////////////////////////////////////////////////////////
      // GET GL LOCATIONS / //////////////////////////////////////////////
      // Creates new GLuint variables which returns an integer that //////
      // represents the location of a specific unifrom & attribute ///////
      // variables within a program object ///////////////////////////////
      ////////////////////////////////////////////////////////////////////


  GLuint position_attrib = glGetAttribLocation(program_token, "position");
  checkGLError();

  GLuint model_uniform  = glGetUniformLocation(program_token, "model");
  checkGLError();

  glUseProgram(program_token);
  checkGLError();

      

  // use the previously transferred buffer as the vertex array.  This way
  // we transfer the buffer once -- at construction -- not on every frame.
  glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer_token);
  glVertexAttribPointer(
                        position_attrib,               /* attribute */
                        3,                             /* size */
                        GL_FLOAT,                      /* type */
                        GL_FALSE,                      /* normalized? */
                        0,                             /* stride */
                        (void*)0                       /* array buffer offset */
                        );
  glEnableVertexAttribArray(position_attrib);

  checkGLError();

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, element_buffer_token);
  glDrawElements(
                 GL_TRIANGLES,
                 element_buffer_length,
                 GL_UNSIGNED_INT,
                 (GLvoid*) 0
                 );

  checkGLError();
  


  glDisableVertexAttribArray(position_attrib);
}
