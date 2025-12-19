#pragma once

#include "GTAmath.h"
#include "GTAentity.h"

#include "SpoonerTaskSequence.h"

#include <string>
#include <vector>

typedef unsigned char UINT8;
typedef int INT, ScrHandle;

namespace Spooner
{
	class SpoonerEntity
	{
	public:
		struct Animation_t { std::string dict, name; };
		struct Attachment_t { bool isAttached; int boneIndex; Vector31 offset, rotation; };

		GTAentity Handle;
		EntityType Type;
		std::string HashName;
		bool Dynamic;
		//bool Door;
		SpoonerEntity::Animation_t LastAnimation;
		SpoonerEntity::Attachment_t AttachmentArgs;
		UINT8 TextureVariation;
		bool IsStill;
		//Hash RelationshipHash;
		SpoonerTaskSequence TaskSequence;

		std::string TypeName();

		SpoonerEntity();
		//const SpoonerEntity& operator = (const SpoonerEntity& right)
		SpoonerEntity(const SpoonerEntity& right);

		friend bool operator == (const SpoonerEntity& left, const SpoonerEntity& right);
		friend bool operator != (const SpoonerEntity& left, const SpoonerEntity& right);
		friend bool operator == (const SpoonerEntity& left, const GTAentity& right);
		friend bool operator != (const SpoonerEntity& left, const GTAentity& right);

	};

	class SpoonerEntityWithInitHandle
	{
	public:
		SpoonerEntity e;
		ScrHandle initHandle;
		ScrHandle attachedToHandle;
	};


	extern SpoonerEntity SelectedEntity;
	extern std::vector<SpoonerEntity> SelectedSpoonGroup;
}



