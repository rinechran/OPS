#pragma once
class VertexArray
{
public:
	VertexArray(const float* verts, unsigned int numVerts,
		const unsigned int* indices, unsigned int numIndices);
	~VertexArray();

	void SetActive();
private:
	// How many vertices in the Number buffer;
	unsigned int mNumVerts;
	//How mant Indices in the index buffer
	unsigned int mNumIndices;
	// OpenGL ID of the vertex buffer
	unsigned int mVertexBuffer;
	//OpenGL ID of the vertex buffer
	unsigned int mIndexBuffer;
	//OpenGL ID of the vertex array Object
	unsigned int mVertexArray;

};

