#include "Ranking.hpp"
#include <fstream>


CRanking::CRanking(std::shared_ptr<AppEnv>app_env) :
CScene(app_env)
{
	for (auto& Score : score){
		Score = 0;
	}

	numbers_info[0] = number(0, Vec2f(0, 0), Vec2f(32, 64), Vec2f(16, 32), Vec2f(25, 32));
	numbers_info[1] = number(1, Vec2f(0, 0), Vec2f(32, 64), Vec2f(36, 32), Vec2f(22, 32));
	numbers_info[2] = number(2, Vec2f(0, 0), Vec2f(32, 64), Vec2f(56, 32), Vec2f(22, 32));
	numbers_info[3] = number(3, Vec2f(0, 0), Vec2f(32, 64), Vec2f(76, 32), Vec2f(22, 32));
	numbers_info[4] = number(4, Vec2f(0, 0), Vec2f(32, 64), Vec2f(96, 32), Vec2f(25, 32));
	numbers_info[5] = number(5, Vec2f(0, 0), Vec2f(32, 64), Vec2f(136, 32), Vec2f(24, 32));
	numbers_info[6] = number(6, Vec2f(0, 0), Vec2f(32, 64), Vec2f(156, 32), Vec2f(23, 32));
	numbers_info[7] = number(7, Vec2f(0, 0), Vec2f(32, 64), Vec2f(178, 32), Vec2f(23, 32));
	numbers_info[8] = number(8, Vec2f(0, 0), Vec2f(32, 64), Vec2f(198, 32), Vec2f(23, 32));
	numbers_info[9] = number(9, Vec2f(0, 0), Vec2f(32, 64), Vec2f(220, 32), Vec2f(25, 32));
	
	std::ifstream fstr("res/score.txt");
	if (fstr) {
		for (int i = 0; i < RANKING_NUM; ++i) {
			fstr >> score[i];
		}
	}
	def_score1 = score[0];
	def_score2 = score[1];
	def_score3 = score[2];
	def_score4 = score[3];
	m_change_scene = Type::RANKING;

}

//�@�X�V
CScene::Type CRanking::Update(){
	Control();
	return m_change_scene;
}

//�@�`��
void CRanking::Draw(){
	//�w�i
	drawTextureBox(-WIDTH / 2, -HEIGHT / 2, WIDTH, HEIGHT,
		0, 0, 1024, 512,
		*m_res.stage_graph,
		Color(1, 1, 1));

	//1�ʃX�R�A
	int one_points1 = def_score1 / 1 % 10;
	int ten_points1 = def_score1 / 10 % 10;
	int hundred_points1 = def_score1 / 100 % 10;
	int thousand_points1 = def_score1 / 1000 % 10;
	int ten_thousand_points1 = def_score1 / 10000;
	//�P�ʕϓ��X�R�A
	for (int i = 0; i < 10; i++){
		if (one_points1 == numbers_info[i].id){
			drawTextureBox(-50, 180, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), *m_res.number, Color(1, 1, 1));
		}
		if (ten_points1 == numbers_info[i].id){
			drawTextureBox(-75, 180, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), *m_res.number, Color(1, 1, 1));
		}
		if (hundred_points1 == numbers_info[i].id){
			drawTextureBox(-100, 180, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), *m_res.number, Color(1, 1, 1));
		}
		if (thousand_points1 == numbers_info[i].id){
			drawTextureBox(-125, 180, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), *m_res.number, Color(1, 1, 1));
		}
		if (ten_thousand_points1 == numbers_info[i].id){
			drawTextureBox(-150, 180, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), *m_res.number, Color(1, 1, 1));
		}
	}
	//�Q�ʌ��X�R�A
	int one_points2 = def_score2 / 1 % 10;
	int ten_points2 = def_score2 / 10 % 10;
	int hundred_points2 = def_score2 / 100 % 10;
	int thousand_points2 = def_score2 / 1000 % 10;
	int ten_thousand_points2 = def_score2 / 10000;
	//�Q�ʕϓ��X�R�A
	for (int i = 0; i < 10; i++){
		if (one_points2 == numbers_info[i].id){
			drawTextureBox(-50, 50, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), *m_res.number, Color(1, 1, 1));
		}
		if (ten_points2 == numbers_info[i].id){
			drawTextureBox(-75, 50, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), *m_res.number, Color(1, 1, 1));
		}
		if (hundred_points2 == numbers_info[i].id){
			drawTextureBox(-100, 50, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), *m_res.number, Color(1, 1, 1));
		}
		if (thousand_points2 == numbers_info[i].id){
			drawTextureBox(-125, 50, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), *m_res.number, Color(1, 1, 1));
		}
		if (ten_thousand_points2 == numbers_info[i].id){
			drawTextureBox(-150, 50, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), *m_res.number, Color(1, 1, 1));
		}
	}
	//�R�ʌ��X�R�A
	int one_points3 = def_score3 / 1 % 10;
	int ten_points3 = def_score3 / 10 % 10;
	int hundred_points3 = def_score3 / 100 % 10;
	int thousand_points3 = def_score3 / 1000 % 10;
	int ten_thousand_points3 = def_score3 / 10000;
	//�R�ʕϓ��X�R�A
	for (int i = 0; i < 10; i++){
		if (one_points3 == numbers_info[i].id){
			drawTextureBox(-50, -80, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), *m_res.number, Color(1, 1, 1));
		}
		if (ten_points3 == numbers_info[i].id){
			drawTextureBox(-75, -80, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), *m_res.number, Color(1, 1, 1));
		}
		if (hundred_points3 == numbers_info[i].id){
			drawTextureBox(-100, -80, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), *m_res.number, Color(1, 1, 1));
		}
		if (thousand_points3 == numbers_info[i].id){
			drawTextureBox(-125, -80, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), *m_res.number, Color(1, 1, 1));
		}
		if (ten_thousand_points3 == numbers_info[i].id){
			drawTextureBox(-150, -80, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), *m_res.number, Color(1, 1, 1));
		}
	}
	//�M���̌��X�R�A
	int one_points4 = def_score4 / 1 % 10;
	int ten_points4 = def_score4 / 10 % 10;
	int hundred_points4 = def_score4 / 100 % 10;
	int thousand_points4 = def_score4 / 1000 % 10;
	int ten_thousand_points4 = def_score4 / 10000;
	//�M���̕ϓ��X�R�A
	for (int i = 0; i < 10; i++){
		if (one_points4 == numbers_info[i].id){
			drawTextureBox(-50, -210, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), *m_res.number, Color(1, 1, 1));
		}
		if (ten_points4 == numbers_info[i].id){
			drawTextureBox(-75, -210, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), *m_res.number, Color(1, 1, 1));
		}
		if (hundred_points4 == numbers_info[i].id){
			drawTextureBox(-100, -210, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), *m_res.number, Color(1, 1, 1));
		}
		if (thousand_points4 == numbers_info[i].id){
			drawTextureBox(-125, -210, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), *m_res.number, Color(1, 1, 1));
		}
		if (ten_thousand_points4 == numbers_info[i].id){
			drawTextureBox(-150, -210, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), *m_res.number, Color(1, 1, 1));
		}
	}
	//�P��
	drawTextureBox(-400, 160, 128, 64, 0, 0, 128, 64,
		*m_res.first,
		Color(1, 1, 1));
	//�Q��
	drawTextureBox(-400, 30, 128, 64, 0, 0, 128, 64,
		*m_res.second,
		Color(1, 1, 1));
	//�R��
	drawTextureBox(-400, -100, 128, 64, 0, 0, 128, 64,
		*m_res.third,
		Color(1, 1, 1));
	//�M���̃X�R�A
	drawTextureBox(-450, -230, 256, 64, 0, 0, 256, 64,
		*m_res.your_score,
		Color(1, 1, 1));






}

//�@����
void CRanking::Control(){
	if (m_app_env->isPushKey(GLFW_KEY_ENTER)){
		m_change_scene = Type::TITLE;
	}
}