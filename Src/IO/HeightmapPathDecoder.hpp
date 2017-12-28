#pragma once

#include "stdafx.hpp"
#include "DecoderBase.hpp"
#include "ModelStreamDecoder.hpp"
#include <istream>

API_BEGIN
namespace Kaleid::Game
{
	class Model;
}

namespace Kaleid::IO
{
	class KALEID_IO_API HeightmapPathDecoder : public ModelPathDecoder
	{
	public:
		bool TryDecode(const char* source, Kaleid::Game::Model* output, ModelDecoderParams& arg);
	};
}
API_END