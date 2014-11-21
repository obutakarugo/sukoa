#pragma once
#include "../Uncopyable.hpp"
#include "../resource/Resource.hpp"
#include "../../lib/appEnv.hpp"
#include <memory>

class CSceneManager;

//========================================
//�V�[���N���X(���N���X)
//========================================

class CScene : private Uncopyable{
public:
	CScene(const std::shared_ptr<AppEnv>app_env) :
		m_app_env(app_env),
		m_res(CResource::GetInstance()){}

	//�@�V�[���̎��
	enum class Type{
		TITLE,
		STAGE,
		RESULT,
		RULE,
		RANKING
	};

	virtual ~CScene() = default;

	virtual Type Update() = 0;
	virtual void Draw() = 0;


	//�@��ʂ̃T�C�Y
	static const int WIDTH = 1320;
	static const int HEIGHT = 720;

protected:
	std::shared_ptr<AppEnv>m_app_env;									//�@�A�v���C�x���g
	CResource& m_res;													//�@���\�[�X
	Type m_change_scene;												//�@�J�ڂ���V�[��
};