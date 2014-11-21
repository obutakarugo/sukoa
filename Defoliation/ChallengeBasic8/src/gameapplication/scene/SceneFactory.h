#pragma once
#include "Scene.h"
#include <unordered_map>

//========================================
//�V�[���t�@�N�g���[�N���X
//========================================

class CSceneFactory{
public:
	CSceneFactory(std::shared_ptr<AppEnv>app_env);

	//�@�V�[�����擾
	std::unique_ptr<CScene> GetScene(CScene::Type type);

private:
	std::unordered_map<CScene::Type, std::function<void()>>m_scene_create_list;			//�@�V�[���������X�g
	std::unique_ptr<CScene> m_scene;													//�@�V�[���̔�
};