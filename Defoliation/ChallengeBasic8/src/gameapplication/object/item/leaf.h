#pragma once
#include "../Object.hpp"
#include "../../utility/CRandom.hpp"
#include "../../resource/Resource.hpp"

class leaf : public Object{
public:
	leaf(std::shared_ptr<AppEnv> app_env);
	~leaf();

	enum TYPE{
		ONE,
		TWO,
		DUO,
		RED
	};

	std::shared_ptr<Texture> leaf_tex;

	int Type;
	float angle;

	Vec2f ang_s;


	static int type;

	float radius = 50;

	std::shared_ptr<AppEnv> m_app_env;
	
	Vec2f m_pos;

	Vec2f set_point;
	//	�_�Ɖ~�̓����蔻��
	bool Check(Vec2f pos, Vec2f obj_pos, float  radius)
	{
		if ((pos.x() - obj_pos.x())*(pos.x() - obj_pos.x()) + (pos.y() - obj_pos.y()) * (pos.y() - obj_pos.y()) <= radius*radius)
		{
			return true;
		}
		else return false;
	}

	//	������p���Ĉʒu�����߂�
	Vec2f SetPoint(){
		float x = CRandom::Uniform(-500, 500);
		float y = CRandom::Uniform(-300, 300);

		return Vec2f(x, y);
	}

	void Draw();
	void Update();
	void Move(AppEnv& app_env);
	void LoadGraphics();

	CResource& m_res;
};

