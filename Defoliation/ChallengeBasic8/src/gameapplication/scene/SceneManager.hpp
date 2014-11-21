#pragma once
#include "../Uncopyable.hpp"
#include "../utility/Font.hpp"
#include "Scene.h"
#include "SceneFactory.h"
#include "../../lib/appEnv.hpp"
#include <memory>
#include <unordered_map>
#include <functional>

//========================================
//�V�[���}�l�[�W���[�N���X
//========================================

class CSceneManager :private Uncopyable{

public:
	CSceneManager(const std::shared_ptr<AppEnv>app_env);

	void Update();															//�@�X�V

private:

	std::unique_ptr<CSceneFactory>m_factory;
	std::unique_ptr<CScene> m_scene;										//�@�V�[�������锠
	CScene::Type m_now_scene;												//�@���݂̃V�[��
	CScene::Type m_old_scene;												//�@�J�ڂ���O�̃V�[��
	std::shared_ptr<AppEnv>m_app_env;										//�@�A�v���C�x���g
	int m_alpha;															//�@�A���t�@�l

	//�@�`��
	void Draw();

	// �J�ڏ���
	void Transition();

	//�@�t�F�[�h�C��
	void FadeIn();

	//�@�t�F�[�h�A�E�g
	void FadeOut();

	//�@�N������
	bool LaunchCondition();

	//�@�V�[���̏I������
	void Finalize();
};