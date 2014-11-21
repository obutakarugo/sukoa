#pragma once
#include "../SceneManager.hpp"
#include <memory>

// �����L���O����enum�Œ�`
enum { RANKING_NUM = 4 };

class CRanking : public CScene{
public:
	CRanking(std::shared_ptr<AppEnv>app_env);

	struct number
	{
		number() = default;
		number(int id, Vec2f& pos, Vec2f& size, Vec2f& texture_pos, Vec2f& texture_size) :
			id(id),
			pos(pos),
			size(size),
			texture_pos(texture_pos),
			texture_size(texture_size){}

		int id;
		Vec2f pos;
		Vec2f size;
		Vec2f texture_pos;
		Vec2f texture_size;

	};

	number numbers_info[10];

	// �����l�́u0�v
	int score[RANKING_NUM + 1];
	//�X�R�A
	int score1 = 40000;
	int score2 = 30000;
	int score3 = 20000;
	int score4 = 10000;

	//�v���C�O�̃X�R�A�L��
	int def_score1;
	int def_score2;
	int def_score3;
	int def_score4;

	//�@�X�V
	Type Update();

	//�@�`��
	void Draw();
private:
	float angle = 0.0;


	//�@����
	void Control();

};

