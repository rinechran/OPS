#pragma once
class VertexArray
{
public:
	VertexArray(const float* verts, unsigned int numVerts,
		const unsigned int* indices, unsigned int numIndices);
	~VertexArray();

	void SetActive();
	unsigned int GetNumIndeces() const;
	unsigned int getNumVerts() const;
private:
	unsigned int mNumVerts;

	unsigned int mNumIndices;

	unsigned int mVertexBuffer;

	unsigned int mIndexBuffer;

	unsigned int mVertexArray;


};

