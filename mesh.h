#pragma once

#include <glm/glm.hpp>
#include <gl/glew.h>

#include <vector>

class Vertex
{
public:
	Vertex(const glm::vec3& pos, const glm::vec2& texCoord)
	{
		this->pos = pos;
		this->texCoord = texCoord;
	}

	inline glm::vec3* GetPos() { return &pos; }
	inline glm::vec2* GetTexCoord() { return &texCoord; }
protected:
private:
	glm::vec3 pos;
	glm::vec2 texCoord;
};

class Mesh
{
public:
	Mesh();

	void Init(Vertex* vertices, unsigned int numVertices);
	void Draw();

	std::vector<glm::vec3> GetPos() { return _pos; }

	~Mesh();
protected:
private:
	enum
	{
		POSITION_VB,
		TEXCOORD_VB,

		NUM_BUFFERS
	};

	std::vector<glm::vec3> _pos;
	
	GLuint _vertexArrayObject;
	GLuint _vertexArrayBuffers[NUM_BUFFERS];
	unsigned int _drawCount;
};

