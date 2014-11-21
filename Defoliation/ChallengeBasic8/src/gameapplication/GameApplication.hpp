#pragma once
#include "resource\Resource.hpp"
#include "scene\SceneManager.hpp"
#include "Uncopyable.hpp"
#include <memory>

//========================================
//�Q�[���A�v���P�[�V�����N���X
//========================================

class CGameApplication : private Uncopyable{
public:

	CGameApplication();


	//�@�X�V
	void Update();
private:

	std::shared_ptr<AppEnv>m_app_env;								//�@�A�v���C�x���g
	std::unique_ptr<CSceneManager>m_scene_manager;					//�@�V�[���}�l�[�W���[
	CResource& m_res;												//�@���\�[�X

	//�@�N������
	bool LaunchCondition();
};

