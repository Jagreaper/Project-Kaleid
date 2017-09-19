#include "stdafx.hpp"
#include "Mesh.hpp"
#include "IndexBuffer.hpp"
#include "VertexBuffer.hpp"
#include "ShaderProgram.hpp"
#include "TextureBase.hpp"

using namespace Kaleid::Graphics;

Mesh::Mesh()
{
	this->_primitive_type = PrimitiveType::Triangles;
	glGenVertexArrays(1, &this->_vao_id);
}

void Mesh::Dispose()
{
	if (this->_vao_id != 0)
	{
		glDeleteVertexArrays(1, &this->_vao_id);
		this->_vao_id = 0;
	}
}

void Mesh::Compose()
{
	this->_b_vbo_length = 0;

	glBindVertexArray(this->_vao_id);
	for (int index = 0; index < this->_vbos.size(); index++)
	{
		VertexBuffer* vbo = this->_vbos[index];
		glBindBuffer(GL_ARRAY_BUFFER, vbo->GetId());

		if (vbo->GetLength() > this->_b_vbo_length)
			this->_b_vbo_length = vbo->GetLength();

		glEnableVertexAttribArray(index);
		glVertexAttribPointer(index, vbo->GetPointSize(), vbo->GetTypeInfo(), GL_FALSE, 0, NULL);
	}
	glBindVertexArray(0);
}

void Mesh::BindTextures(const std::vector<TextureBase*>* textures)
{
	if (textures != NULL)
	{
		for (unsigned int index = 0; index < textures->size(); index++)
		{
			glActiveTexture(GL_TEXTURE0 + index);
			glBindTexture(GL_TEXTURE_2D, textures->at(index)->GetId());
		}
	}
}

void Mesh::Render(const ShaderProgram* shader, const std::vector<TextureBase*>* textures, std::function<void()> arguments)
{
	if (shader == NULL || !this->HasVertexBuffers())
		throw std::runtime_error("Missing fields to render mesh");

	BindTextures(textures);

	glBindVertexArray(this->GetVertexArrayId());
	glUseProgram(shader->GetId());

	if (arguments != NULL)
		arguments();

	if (this->HasIndexBuffer())
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->GetIndexBuffer()->GetId());
		glDrawElements(this->_primitive_type, (GLsizei)this->GetIndexBuffer()->GetLength(), this->GetIndexBuffer()->GetTypeInfo(), NULL);
	}
	else
		glDrawArrays(this->_primitive_type, 0, (GLsizei)this->GetBestVboLength());
}

const unsigned int Mesh::GetVertexArrayId() const
{
	return this->_vao_id;
}

void Mesh::SetIndexBuffer(IndexBuffer* buffer)
{
	this->_ibo = buffer;
}

void Mesh::SetVertexBuffers(std::vector<VertexBuffer*>* buffers)
{
	this->_vbos.clear();
	for (int index = 0; index < buffers->size(); index++)
		this->_vbos.push_back(buffers->at(index));
}

const IndexBuffer* Mesh::GetIndexBuffer() const
{
	return this->_ibo;
}

const std::vector<VertexBuffer*>* Mesh::GetVertexBuffers() const
{
	return &this->_vbos;
}

const size_t Mesh::GetBestVboLength() const
{
	return this->_b_vbo_length;
}

bool Mesh::HasIndexBuffer() const
{
	return this->_ibo != NULL;
}

bool Mesh::HasVertexBuffers() const
{
	return this->_vbos.size() > 0;
}

void Mesh::SetPrimitiveType(const PrimitiveType type)
{
	this->_primitive_type = type;
}

PrimitiveType Mesh::GetPrimitiveType()
{
	return this->_primitive_type;
}