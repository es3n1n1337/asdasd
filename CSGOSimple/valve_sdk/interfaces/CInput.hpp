#pragma once

#include "../Misc/CUserCmd.hpp"

#define MULTIPLAYER_BACKUP 150

class bf_write;
class bf_read;

class CInput
{
	void*               pvftable;                     //0x00
public:
	inline CUserCmd* GetUserCmd(int sequence_number);
	inline CVerifiedUserCmd* GetVerifiedCmd(int sequence_number);

	char pad_0x00[0x8];
	bool                m_fTrackIRAvailable;            //0x04
	bool                m_fMouseInitialized;            //0x05
	bool                m_fMouseActive;                 //0x06
	bool                m_fJoystickAdvancedInit;        //0x07
	char                pad_0x08[0x2C];                 //0x08
	void*               m_pKeys;                        //0x34
	char                pad_0x38[0x6C];                 //0x38
	bool                m_fCameraInterceptingMouse;     //0x9C
	bool                m_fCameraInThirdPerson;         //0x9D
	bool                m_fCameraMovingWithMouse;       //0x9E
	Vector              m_vecCameraOffset;              //0xA0
	bool                m_fCameraDistanceMove;          //0xAC
	int                 m_nCameraOldX;                  //0xB0
	int                 m_nCameraOldY;                  //0xB4
	int                 m_nCameraX;                     //0xB8
	int                 m_nCameraY;                     //0xBC
	bool                m_CameraIsOrthographic;         //0xC0
	QAngle              m_angPreviousViewAngles;        //0xC4
	QAngle              m_angPreviousViewAnglesTilt;    //0xD0
	float               m_flLastForwardMove;            //0xDC
	int                 m_nClearInputState;             //0xE0
	CUserCmd*           m_pCommands;                    //0xEC
	CVerifiedUserCmd*   m_pVerifiedCommands;            //0xF0


};
class IInputSystem
{
public:
	void EnableInput(bool bEnable)
	{
		using vfunc = void(__thiscall*)(IInputSystem*, bool);
		CallVFunction<vfunc>(this, 11)(this, bEnable);
	}
	// Thats everything we need, you can find the whole interface easly
};
CUserCmd* CInput::GetUserCmd(int sequence_number)
{
	return &m_pCommands[sequence_number % MULTIPLAYER_BACKUP];
}

CVerifiedUserCmd* CInput::GetVerifiedCmd(int sequence_number)
{
	return &m_pVerifiedCommands[sequence_number % MULTIPLAYER_BACKUP];
}

