#pragma once
#include "../SceneManager.hpp"
#include <memory>

class CResult : public CScene{
public:
	CResult(std::shared_ptr<AppEnv>app_env);

	//　更新
	Type Update();

	//　描画
	void Draw();

private:

	struct number
	{
		number(int id, Vec2f& pos, Vec2f& size, Vec2f& texture_pos, Vec2f& texture_size):
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

	//数字を配列で用意
	std::shared_ptr<number> numbers_info[10];

	//スコア
	int score1 = 10009;
	int score2 = 10009;
	int score3 = 10009;
	int score4 = 3000;
	int score5 = 10009;
	int score6 = 10009;
	int score7 = 10009;
	int score8 = 0;
	int score11 = 10;
	int score22 = 20;
	int score33 = 30;
	int score44 = 40;
	int score55 = 50;
	int score66 = 60;
	int score77 = 70;


	//	プレイ前のスコアを記憶しておく
	int def_score1 = score1;
	int def_score2 = score2;
	int def_score3 = score3;
	int def_score4 = score4;
	int def_score5 = score5;
	int def_score6 = score6;
	int def_score7 = score7;
	int def_score8 = score8;
	int def_score11 = score11;
	int def_score22 = score22;
	int def_score33 = score33;
	int def_score44 = score44;
	int def_score55 = score55;
	int def_score66 = score66;
	int def_score77 = score77;

	//　操作
	void Control();

};

