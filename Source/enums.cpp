#include "stdafx.h"

namespace AnimFlag {
	std::map<int, std::string> vFlagNames
	{
		{ AnimFlag::Normal, "Normal" },
		{ AnimFlag::Loop, "Loop" },
		{ AnimFlag::StayInLastFrame, "StayInLastFrame" },

		{ 8, "8" },
		{ 9, "9" },
		{ 10, "10" },

		{ AnimFlag::UpperBody, "UpperBody" },
		{ AnimFlag::UpperBodyLoop, "UpperBody Loop" },
		{ AnimFlag::UpperBodyStayInLastFrame, "UpperBody StayInLastFrame" },

		{ AnimFlag::SecondTask, "SecondTask" },
		{ AnimFlag::SecondTaskLoop, "SecondTask Loop" },
		{ AnimFlag::SecondTaskStayInLastFrame, "SecondTask StayInLastFrame" },

		{ 42, "42" },

		{ AnimFlag::UpperBodySecondTask, "UpperBody SecondTask" },
		{ AnimFlag::UpperBodySecondTaskLoop, "UpperBody SecondTask Loop" },
		{ AnimFlag::UpperBodySecondTaskStayInLastFrame, "UpperBody SecondTask StayInLastFrame" },


		{ 50, "50" },

		{ AnimFlag::AllowInteruption, "Allow Interuption" },

		{ 288, "288" },

		{ 512, "512" },

		{ 1024, "1024" },

		{ 262152, "262152" },
		{ 262153, "262152 Loop" },
		{ 262154, "262152 StayInLastFrame" },

		{ AnimFlag::DisableRootMotion, "DisableRootMotion" },
		{ AnimFlag::DisableRootMotionLoop, "DisableRootMotion Loop" },
		{ AnimFlag::DisableRootMotionStayInLastFrame, "DisableRootMotion StayInLastFrame" },

		{ AnimFlag::RagdollOnCollision, "RagdollOnCollision" },
		{ AnimFlag::RagdollOnCollisionLoop, "RagdollOnCollision Loop" },

		{ AnimFlag::UpperbodySecondTaskUnkUnk, "Upperbody SecondTask UnkUnk" },
		{ AnimFlag::UpperbodySecondTaskUnkUnkLoop, "Upperbody SecondTask UnkUnk Loop " },
		{ AnimFlag::UpperbodySecondTaskUnkUnkStayInLastFrame, "Upperbody SecondTask UnkUnk StayInLastFrame" },
	};
}