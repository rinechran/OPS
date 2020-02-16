#include <SOIL/SOIL.h>
#include <GL/glew.h>
#include <SDL/SDL.h>
#include "Texture.h"

Texture::Texture()
	:mTextureID(0)
	, mWidth(0)
	, mHeight(0)
{
}

Texture::~Texture()
{
}

bool Texture::Load(const std::string& fileName)
{
	int channels = 0;
	unsigned char* image = SOIL_load_image(fileName.c_str(),
		&mWidth, &mHeight, &channels, SOIL_LOAD_AUTO);


	return true;
}

void Texture::UnLoad()
{
	glDeleteTextures(1, &mTextureID);

}

void Texture::SetActive()
{
	glBindTexture(GL_TEXTURE_2D, mTextureID);

}
