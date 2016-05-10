//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////// BOUNDINGBOX.CC ////////////////////////////////////
///////////////////////////////////////////jrs38//////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
#include "BoundingBox.h"

// Generate Bounding Boxes
BoundingBox::BoundingBox(glm::vec3 position, int type, float scale , glm::vec3 rotation, glm::vec3 speed)
{
	this->position = position;
        this->rotation = rotation;
	this->type = type;
	this->scale = scale;
	this->speed = speed;
}


// Generate animations
// 1 = Move Object
// 2 = Rotate Object
// 3 = Scale Object
glm::mat4 BoundingBox::GetModelTransformation()
{
    if (this->type == 1)
	{
		this->Translate(glm::vec3(0.01f, 0.0f, 0.0f));
	}
    else if (this->type == 2)
	{
		this->Rotate(glm::vec3(0.01f, 0.1f, 0.1f));
	}
    else if(this->type == 3)
	{
		this->Scale(0.01f);
	}


    
        glm::mat4 scale_matrix = glm::scale(glm::vec3(scale, scale, scale));
	glm::mat4 translate_matrix = glm::translate(glm::mat4(), glm::vec3(this->position.x, this->position.y, this->position.z));

	model_matrix = translate_matrix * scale_matrix;
        model_matrix = glm::rotate(model_matrix, rotation.x, glm::vec3(1, 0, 0));
	model_matrix = glm::rotate(model_matrix, rotation.y, glm::vec3(0, 1, 0));
        model_matrix = glm::rotate(model_matrix, rotation.z, glm::vec3(0, 0, 1));

	return model_matrix;
}

//////////////////////////////////////////////////////////////////////////////////////////
//TRANSLATE FUNCTION /////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
void BoundingBox::Translate(glm::vec3 position_to)
{
	glm::vec3 new_position;
       	new_position = this->position + position_to;
	this->position = new_position;
}

//////////////////////////////////////////////////////////////////////////////////////////
//SCALE FUNCTION /////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
void BoundingBox::Scale(float scale_to)
{
	float new_scale;
	if(this->scale > 5.0f)
	{
		new_scale = 1.0f;
	}
	else
	{
		new_scale = this->scale + scale_to;
	}

	this->scale = new_scale;
}
//////////////////////////////////////////////////////////////////////////////////////////
//ROTATE FUNCTION ////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
void BoundingBox::Rotate(glm::vec3 rotate_to)
{
	glm::vec3 new_rotation;
	if(this->rotation.x > 2.0f && this->rotation.y > 2.0f && this->rotation.z > 2.0f)
	{
		new_rotation = glm::vec3(0,0,0);
	}
	else
	{
		new_rotation = this->rotation + rotate_to;
	}

	this->rotation = new_rotation;
}

//////////////////////////////////////////////////////////////////////////////////////////
//GETS THE VEC3 FOR THE BOUNDING BOX /////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
glm::vec3 BoundingBox::GetVec3()
{
	return position;
}

//////////////////////////////////////////////////////////////////////////////////////////
//GETS THE MAXIMUM AND MINIMUM BOUNDING BOX VALUES ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
glm::vec3 BoundingBox::GetMaxAndMin(int type)
{
    glm::vec3 bounds;

    if (type == 1)
    {
    // The maximum bounding box
    bounds = this->position += glm::vec3(0.8f,0.8f,0.8f);

    }
    else if (type == 2)
    {
    // The minimum bounding box
     bounds = this->position += glm::vec3(-0.8f,-0.8f,-0.8f);
    }
	return bounds;
}

void BoundingBox::CheckCollision(glm::vec3 bounding_box1_max, glm::vec3 bounding_box1_min, glm::vec3 bounding_box2_max, glm::vec3 bounding_box2_min)
{
    //Asks whether or not Box1's maximum bounding box is greater than Box2's minimum,  and also that  Box1's minimum is less than Box2's maximum
    if (bounding_box1_max.x > bounding_box2_min.x && bounding_box1_min.x < bounding_box2_max.x &&
        bounding_box1_max.y > bounding_box2_min.y && bounding_box1_min.y < bounding_box2_max.y &&
        bounding_box1_max.z > bounding_box2_min.z && bounding_box1_min.z < bounding_box2_max.z)
        {
	  std::cout << "Collision | You Hit Something!" << std::endl; // Message to console to demonstrate that the user has hit a bounding box
            glm::vec3 reverse_speed = this->speed;
            reverse_speed = reverse_speed + reverse_speed;
            this->speed -= reverse_speed;
        }
}
