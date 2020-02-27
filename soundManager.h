#pragma once
#include"singletonBase.h"
#include"inc/fmod.hpp"
#pragma comment(lib,"lib/fmodex_vc.lib")
using namespace FMOD;

#define EXTRACHANNELBUFFER 5
#define SOUNDBUFFER 100

#define TOTALSOUNDBUFFER SOUNDBUFFER+ EXTRACHANNELBUFFER
class soundManager : public singletonBase<soundManager>
{
private:

	typedef map<string, Sound**>arrSounds;
	typedef map<string, Sound**>::iterator arrSoundIter;

	string songName[6];
	int currentNum = 0 ;

	System* m_system;		


	Sound** m_sound;		//����
	Channel** m_channel;		//ä��


	arrSounds m_totalSounds;



public:
	soundManager();
	~soundManager();

	HRESULT init();
	void release();
	void update();
	void render();
	//Ű��, ���� �̸�, BGM, LOOP
	void addSound(string keyName, string soundName, bool bgm = FALSE, bool loop = FALSE);

	//���� �÷���	(Ű��, ���� 0.0~1.0f)
	void play(string keyName, float volume = 1.0f);

	void stop(string keyName);
	void pause(string keyName);
	void resume(string keyName);

	//�÷��� ���̳�
	bool isPlaySound(string keyName);
	//�Ͻ� ���� ���̳�
	bool isPauseSound(string keyName);

	void setSongName() { songName[0] = "��Ʈ�κ��"; songName[1] = "�������"; songName[2] = "�������"; 
	songName[3] = "�������"; songName[4] = "ȸ������"; songName[5] = "��������";
	}

	int getCurrentNum() { return currentNum; }
	void setCurrentNum(int num) { currentNum = num; }
	string getCurrentSong() { return songName[currentNum]; }
};
