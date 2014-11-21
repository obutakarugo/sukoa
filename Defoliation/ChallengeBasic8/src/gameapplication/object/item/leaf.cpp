#include "leaf.h"
#include "../../scene/Scene.h"

leaf::leaf(std::shared_ptr<AppEnv> app_env) :
m_app_env(app_env),
set_point(Vec2f(0,0)),
m_res(CResource::GetInstance())
{
	angle = float(CRandom::Uniform(0,50));
	Type = float(CRandom::Uniform(0,4));
	//switch (Type)
	//{
	//case TYPE::ONE:
	//	leaf_tex = m_res.m_defoliation_graph[0];
	//	break;
	//case TYPE::TWO:
	//	leaf_tex = m_res.m_defoliation_graph[1];
	//	break;
	//case TYPE::DUO:
	//	leaf_tex = m_res.m_defoliation_graph[2];
	//	break;
	//case TYPE::RED:
	//	leaf_tex = m_res.m_defoliation_graph[3];
	//	break;
	//}
	set_point = SetPoint(); 
	m_pos = Vec2f(CRandom::Uniform(-CScene::WIDTH / 2 + m_size.x(), CScene::WIDTH / 2 - m_size.x()),
		CRandom::Uniform(-CScene::HEIGHT / 2 + m_size.y(), CScene::HEIGHT / 2 - m_size.y() - 100));
	//m_pos = Vec2f(CRandom::Uniform(-500, 500), CRandom::Uniform(-300, 300));
}

leaf::~leaf()
{
}



void leaf::Draw(){

	switch (Type)
	{
	case TYPE::ONE:
		drawTextureBox(set_point.x(), set_point.y(), 100, 100,
			0, 0, 256, 256,
			*m_res.m_defoliation_graph[0],
			Color(1, 1, 1),
			angle,
			Vec2f(1, 1),
			Vec2f(50, 50));
		break;
	case TYPE::TWO:
		drawTextureBox(set_point.x(), set_point.y(), 100, 100,
			0, 0, 256, 256,
			*m_res.m_defoliation_graph[1],
			Color(1, 1, 1),
			angle,
			Vec2f(1, 1),
			Vec2f(50, 50));
		break;
	case TYPE::DUO:
		drawTextureBox(set_point.x(), set_point.y(), 100, 100,
			0, 0, 256, 256,
			*m_res.m_defoliation_graph[2],
			Color(1, 1, 1),
			angle,
			Vec2f(1, 1),
			Vec2f(50, 50));
		break;
	case TYPE::RED:
		drawTextureBox(set_point.x(), set_point.y(), 100, 100,
			0, 0, 256, 256,
			*m_res.m_defoliation_graph[3],
			Color(1, 1, 1),
			angle,
			Vec2f(1, 1),
			Vec2f(50, 50));
		break;
	}



		drawCircle(set_point.x(), set_point.y(), 50, 50, 100, 1, Color(1, 1, 1));
}

void leaf::Update(){
	if (Check(m_app_env->mousePosition(), set_point, radius)){
		if (m_app_env->isPushButton(Mouse::LEFT)){
			set_point = SetPoint();
			
		}
		else if (m_app_env->isPushButton(Mouse::RIGHT)){
			set_point = Vec2f(500, 500);
		}

	}
	ang_s.x() =  -50;
	ang_s.y() =  50;
}

void leaf::Move(AppEnv& app_env){

	//set_point.x() += float(app_env.random().fromFirstToLast(-10,10))*2-1;
	//set_point.y() -= float(app_env.random().fromZeroToLast(5)) * 2 - 1;
	set_point.y() -= 7;
}

void leaf::LoadGraphics()
{

	
}