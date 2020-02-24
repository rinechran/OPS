#include <GL/glew.h>
#include "VertexArray.h"
VertexArray::VertexArray(const float* verte, unsigned int numVerts, const unsigned int* indices, unsigned int numIndices)

{

}

VertexArray::~VertexArray()
{

}

void VertexArray::SetActive()
{
}

unsigned int VertexArray::GetNumIndeces() const {
	return mNumIndices;
}

unsigned int VertexArray::getNumVerts() const {
	return mNumVerts;
}
