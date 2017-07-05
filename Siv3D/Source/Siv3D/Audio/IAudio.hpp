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
# include <Siv3D/Fwd.hpp>
# include <Siv3D/Audio.hpp>

namespace s3d
{
	class ISiv3DAudio
	{
	public:

		static ISiv3DAudio* Create();

		virtual ~ISiv3DAudio() = default;

		virtual bool init() = 0;

		virtual bool hasAudioDevice() const = 0;

		virtual Audio::IDType create(Wave&& wave) = 0;

		virtual void release(Audio::IDType handleID) = 0;

		virtual bool play(Audio::IDType handleID, const SecondsF& fadeinDuration) = 0;

		virtual void pause(Audio::IDType handleID, const SecondsF& fadeoutDuration) = 0;

		virtual void stop(Audio::IDType handleID, const SecondsF& fadeoutDuration) = 0;

		virtual uint64 samplesPlayed(Audio::IDType handleID) = 0;

		virtual uint64 streamPosSample(Audio::IDType handleID) = 0;

		virtual bool updateFade() = 0;

		virtual void fadeMasterVolume() = 0;
	};
}