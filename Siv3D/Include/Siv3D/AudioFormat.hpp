﻿//-----------------------------------------------
//
//	This file is part of the Siv3D Engine.
//
//	Copyright (c) 2008-2017 Ryo Suzuki
//	Copyright (c) 2016-2017 OpenSiv3D Project
//
//	Licensed under the MIT License.
//
//-----------------------------------------------

# pragma once
# include "Fwd.hpp"
# include "Array.hpp"

namespace s3d
{
	/// <summary>
	/// 音声フォーマット
	/// </summary>
	enum class AudioFormat
	{
		/// <summary>
		/// 不明
		/// </summary>
		Unknown,

		/// <summary>
		/// WAVE
		/// </summary>
		WAVE,

		//mp3, ogg, opus, aac, ...

		/// <summary>
		/// 指定しない / データと拡張子から判断
		/// </summary>
		Unspecified = Unknown,
	};

	class IAudioFormat
	{
	public:

		virtual ~IAudioFormat() = default;

		virtual AudioFormat format() const = 0;

		virtual const Array<String>& possibleExtexsions() const = 0;

		virtual bool isHeader(const uint8(&bytes)[16]) const = 0;

		virtual Wave decode(IReader& reader) const = 0;

		//virtual bool encode(const Image& image, IWriter& writer) const = 0;

		//virtual bool save(const Image& image, const FilePath& path) const = 0;
	};

	namespace AudioProcessing
	{
		AudioFormat GetFormat(const FilePath& path);

		AudioFormat GetFormat(const IReader& reader);

		AudioFormat GetFormatFromFilePath(const FilePath& path);
	}
}
