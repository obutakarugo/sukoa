#include "Rule.hpp"


CRule::CRule(std::shared_ptr<AppEnv>app_env):
CScene(app_env),
m_font(std::make_unique<Font>(90))
{
	m_change_scene = Type::RULE;
}

//�@�X�V
CScene::Type CRule::Update(){
	Control();
	return m_change_scene;
}

//�@�`��
void CRule::Draw(){
	m_font->DrawCenter(L"���[�����", 0, 200, Color(1, 1, 1));
}

//�@����
void CRule::Control(){
	if (m_app_env->isPushKey(GLFW_KEY_ENTER)){
		m_change_scene = Type::TITLE;
	}
}