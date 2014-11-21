#include "Result.hpp"


CResult::CResult(std::shared_ptr<AppEnv>app_env):
CScene(app_env)
{
	numbers_info[0] = std::make_shared<number>(0, Vec2f(0, 0), Vec2f(32, 64), Vec2f(16, 32), Vec2f(25, 32));
	numbers_info[1] = std::make_shared<number>(1, Vec2f(0, 0), Vec2f(32, 64), Vec2f(36, 32), Vec2f(22, 32));
	numbers_info[2] = std::make_shared<number>(2, Vec2f(0, 0), Vec2f(32, 64), Vec2f(56, 32), Vec2f(22, 32));
	numbers_info[3] = std::make_shared<number>(3, Vec2f(0, 0), Vec2f(32, 64), Vec2f(76, 32), Vec2f(22, 32));
	numbers_info[4] = std::make_shared<number>(4, Vec2f(0, 0), Vec2f(32, 64), Vec2f(96, 32), Vec2f(25, 32));
	numbers_info[5] = std::make_shared<number>(5, Vec2f(0, 0), Vec2f(32, 64), Vec2f(136, 32), Vec2f(24, 32));
	numbers_info[6] = std::make_shared<number>(6, Vec2f(0, 0), Vec2f(32, 64), Vec2f(156, 32), Vec2f(23, 32));
	numbers_info[7] = std::make_shared<number>(7, Vec2f(0, 0), Vec2f(32, 64), Vec2f(178, 32), Vec2f(23, 32));
	numbers_info[8] = std::make_shared<number>(8, Vec2f(0, 0), Vec2f(32, 64), Vec2f(198, 32), Vec2f(23, 32));
	numbers_info[9] = std::make_shared<number>(9, Vec2f(0, 0), Vec2f(32, 64), Vec2f(220, 32), Vec2f(25, 32));
	m_change_scene = Type::RESULT;
}


//�@�X�V
CScene::Type CResult::Update(){
	Control();
	return m_change_scene;
}

//�@�`��
void CResult::Draw(){
	//�w�i
	drawTextureBox(-WIDTH / 2, -HEIGHT / 2, WIDTH, HEIGHT,
		0, 0, 1024, 512,
		*m_res.stage_graph,
		Color(1, 1, 1));


	//���^�b�v���X�R�A
	int one_points1 = def_score1 / 1 % 10;
	int ten_points1 = def_score1 / 10 % 10;
	int hundred_points1 = def_score1 / 100 % 10;
	int thousand_points1 = def_score1 / 1000 % 10;
	int ten_thousand_points1 = def_score1 / 10000;
	//���^�b�v�ϓ��X�R�A
	for (int i = 0; i < 10; i++){
		if (one_points1 == numbers_info[i]->id){
			drawTextureBox(450, 250, 32, 32, numbers_info[i]->texture_pos.x(), numbers_info[i]->texture_pos.y(), numbers_info[i]->texture_size.x(), numbers_info[i]->texture_size.y(), *m_res.number, Color(1, 1, 1));
		}
		if (ten_points1 == numbers_info[i]->id){
			drawTextureBox(425, 250, 32, 32, numbers_info[i]->texture_pos.x(), numbers_info[i]->texture_pos.y(), numbers_info[i]->texture_size.x(), numbers_info[i]->texture_size.y(), *m_res.number, Color(1, 1, 1));
		}
		if (hundred_points1 == numbers_info[i]->id){
			drawTextureBox(400, 250, 32, 32, numbers_info[i]->texture_pos.x(), numbers_info[i]->texture_pos.y(), numbers_info[i]->texture_size.x(), numbers_info[i]->texture_size.y(), *m_res.number, Color(1, 1, 1));
		}
		if (thousand_points1 == numbers_info[i]->id){
			drawTextureBox(375, 250, 32, 32, numbers_info[i]->texture_pos.x(), numbers_info[i]->texture_pos.y(), numbers_info[i]->texture_size.x(), numbers_info[i]->texture_size.y(), *m_res.number, Color(1, 1, 1));
		}
		if (ten_thousand_points1 == numbers_info[i]->id){
			drawTextureBox(350, 250, 32, 32, numbers_info[i]->texture_pos.x(), numbers_info[i]->texture_pos.y(), numbers_info[i]->texture_size.x(), numbers_info[i]->texture_size.y(), *m_res.number, Color(1, 1, 1));
		}
	}
	//���X���C�v���X�R�A
	int one_points2 = def_score2 / 1 % 10;
	int ten_points2 = def_score2 / 10 % 10;
	int hundred_points2 = def_score2 / 100 % 10;
	int thousand_points2 = def_score2 / 1000 % 10;
	int ten_thousand_points2 = def_score2 / 10000;
	//���X���C�v�ϓ��X�R�A
	for (int i = 0; i < 10; i++){
		if (one_points2 == numbers_info[i]->id){
			drawTextureBox(450, 200, 32, 32, numbers_info[i]->texture_pos.x(), numbers_info[i]->texture_pos.y(), numbers_info[i]->texture_size.x(), numbers_info[i]->texture_size.y(), *m_res.number, Color(1, 1, 1));
		}
		if (ten_points2 == numbers_info[i]->id){
			drawTextureBox(425, 200, 32, 32, numbers_info[i]->texture_pos.x(), numbers_info[i]->texture_pos.y(), numbers_info[i]->texture_size.x(), numbers_info[i]->texture_size.y(), *m_res.number, Color(1, 1, 1));
		}
		if (hundred_points2 == numbers_info[i]->id){
			drawTextureBox(400, 200, 32, 32, numbers_info[i]->texture_pos.x(), numbers_info[i]->texture_pos.y(), numbers_info[i]->texture_size.x(), numbers_info[i]->texture_size.y(), *m_res.number, Color(1, 1, 1));
		}
		if (thousand_points2 == numbers_info[i]->id){
			drawTextureBox(375, 200, 32, 32, numbers_info[i]->texture_pos.x(), numbers_info[i]->texture_pos.y(), numbers_info[i]->texture_size.x(), numbers_info[i]->texture_size.y(), *m_res.number, Color(1, 1, 1));
		}
		if (ten_thousand_points2 == numbers_info[i]->id){
			drawTextureBox(350, 200, 32, 32, numbers_info[i]->texture_pos.x(), numbers_info[i]->texture_pos.y(), numbers_info[i]->texture_size.x(), numbers_info[i]->texture_size.y(), *m_res.number, Color(1, 1, 1));
		}
	}
	//�ђ��^�b�v���X�R�A
	int one_points3 = def_score3 / 1 % 10;
	int ten_points3 = def_score3 / 10 % 10;
	int hundred_points3 = def_score3 / 100 % 10;
	int thousand_points3 = def_score3 / 1000 % 10;
	int ten_thousand_points3 = def_score3 / 10000;
	//�ђ��^�b�v�ϓ��X�R�A
	for (int i = 0; i < 10; i++){
		if (one_points3 == numbers_info[i]->id){
			drawTextureBox(450, 110, 32, 32, numbers_info[i]->texture_pos.x(), numbers_info[i]->texture_pos.y(), numbers_info[i]->texture_size.x(), numbers_info[i]->texture_size.y(), *m_res.number, Color(1, 1, 1));
		}
		if (ten_points3 == numbers_info[i]->id){
			drawTextureBox(425, 110, 32, 32, numbers_info[i]->texture_pos.x(), numbers_info[i]->texture_pos.y(), numbers_info[i]->texture_size.x(), numbers_info[i]->texture_size.y(), *m_res.number, Color(1, 1, 1));
		}
		if (hundred_points3 == numbers_info[i]->id){
			drawTextureBox(400, 110, 32, 32, numbers_info[i]->texture_pos.x(), numbers_info[i]->texture_pos.y(), numbers_info[i]->texture_size.x(), numbers_info[i]->texture_size.y(), *m_res.number, Color(1, 1, 1));
		}
		if (thousand_points3 == numbers_info[i]->id){
			drawTextureBox(375, 110, 32, 32, numbers_info[i]->texture_pos.x(), numbers_info[i]->texture_pos.y(), numbers_info[i]->texture_size.x(), numbers_info[i]->texture_size.y(), *m_res.number, Color(1, 1, 1));
		}
		if (ten_thousand_points3 == numbers_info[i]->id){
			drawTextureBox(350, 110, 32, 32, numbers_info[i]->texture_pos.x(), numbers_info[i]->texture_pos.y(), numbers_info[i]->texture_size.x(), numbers_info[i]->texture_size.y(), *m_res.number, Color(1, 1, 1));
		}
	}
	//�ђ��X���C�v���X�R�A
	int one_points4 = def_score4 / 1 % 10;
	int ten_points4 = def_score4 / 10 % 10;
	int hundred_points4 = def_score4 / 100 % 10;
	int thousand_points4 = def_score4 / 1000 % 10;
	int ten_thousand_points4 = def_score4 / 10000;
	//�ђ��X���C�v�ϓ��X�R�A
	for (int i = 0; i < 10; i++){
		if (one_points4 == numbers_info[i]->id){
			drawTextureBox(450, 60, 32, 32, numbers_info[i]->texture_pos.x(), numbers_info[i]->texture_pos.y(), numbers_info[i]->texture_size.x(), numbers_info[i]->texture_size.y(), *m_res.number, Color(1, 1, 1));
		}
		if (ten_points4 == numbers_info[i]->id){
			drawTextureBox(425, 60, 32, 32, numbers_info[i]->texture_pos.x(), numbers_info[i]->texture_pos.y(), numbers_info[i]->texture_size.x(), numbers_info[i]->texture_size.y(), *m_res.number, Color(1, 1, 1));
		}
		if (hundred_points4 == numbers_info[i]->id){
			drawTextureBox(400, 60, 32, 32, numbers_info[i]->texture_pos.x(), numbers_info[i]->texture_pos.y(), numbers_info[i]->texture_size.x(), numbers_info[i]->texture_size.y(), *m_res.number, Color(1, 1, 1));
		}
		if (thousand_points4 == numbers_info[i]->id){
			drawTextureBox(375, 60, 32, 32, numbers_info[i]->texture_pos.x(), numbers_info[i]->texture_pos.y(), numbers_info[i]->texture_size.x(), numbers_info[i]->texture_size.y(), *m_res.number, Color(1, 1, 1));
		}
		if (ten_thousand_points4 == numbers_info[i]->id){
			drawTextureBox(350, 60, 32, 32, numbers_info[i]->texture_pos.x(), numbers_info[i]->texture_pos.y(), numbers_info[i]->texture_size.x(), numbers_info[i]->texture_size.y(), *m_res.number, Color(1, 1, 1));
		}
	}
	//�_�^�b�v���X�R�A
	int one_points5 = def_score5 / 1 % 10;
	int ten_points5 = def_score5 / 10 % 10;
	int hundred_points5 = def_score5 / 100 % 10;
	int thousand_points5 = def_score5 / 1000 % 10;
	int ten_thousand_points5 = def_score5 / 10000;
	//�_�^�b�v�ϓ��X�R�A
	for (int i = 0; i < 10; i++){
		if (one_points5 == numbers_info[i]->id){
			drawTextureBox(450, -50, 32, 32, numbers_info[i]->texture_pos.x(), numbers_info[i]->texture_pos.y(), numbers_info[i]->texture_size.x(), numbers_info[i]->texture_size.y(), *m_res.number, Color(1, 1, 1));
		}
		if (ten_points5 == numbers_info[i]->id){
			drawTextureBox(425, -50, 32, 32, numbers_info[i]->texture_pos.x(), numbers_info[i]->texture_pos.y(), numbers_info[i]->texture_size.x(), numbers_info[i]->texture_size.y(), *m_res.number, Color(1, 1, 1));
		}
		if (hundred_points5 == numbers_info[i]->id){
			drawTextureBox(400, -50, 32, 32, numbers_info[i]->texture_pos.x(), numbers_info[i]->texture_pos.y(), numbers_info[i]->texture_size.x(), numbers_info[i]->texture_size.y(), *m_res.number, Color(1, 1, 1));
		}
		if (thousand_points5 == numbers_info[i]->id){
			drawTextureBox(375, -50, 32, 32, numbers_info[i]->texture_pos.x(), numbers_info[i]->texture_pos.y(), numbers_info[i]->texture_size.x(), numbers_info[i]->texture_size.y(), *m_res.number, Color(1, 1, 1));
		}
		if (ten_thousand_points5 == numbers_info[i]->id){
			drawTextureBox(350, -50, 32, 32, numbers_info[i]->texture_pos.x(), numbers_info[i]->texture_pos.y(), numbers_info[i]->texture_size.x(), numbers_info[i]->texture_size.y(), *m_res.number, Color(1, 1, 1));
		}
	}
	//�_�X���C�v���X�R�A
	int one_points6 = def_score6 / 1 % 10;
	int ten_points6 = def_score6 / 10 % 10;
	int hundred_points6 = def_score6 / 100 % 10;
	int thousand_points6 = def_score6 / 1000 % 10;
	int ten_thousand_points6 = def_score6 / 10000;
	//�_�X���C�v�ϓ��X�R�A
	for (int i = 0; i < 10; i++){
		if (one_points6 == numbers_info[i]->id){
			drawTextureBox(450, -100, 32, 32, numbers_info[i]->texture_pos.x(), numbers_info[i]->texture_pos.y(), numbers_info[i]->texture_size.x(), numbers_info[i]->texture_size.y(), *m_res.number, Color(1, 1, 1));
		}
		if (ten_points6 == numbers_info[i]->id){
			drawTextureBox(425, -100, 32, 32, numbers_info[i]->texture_pos.x(), numbers_info[i]->texture_pos.y(), numbers_info[i]->texture_size.x(), numbers_info[i]->texture_size.y(), *m_res.number, Color(1, 1, 1));
		}
		if (hundred_points6 == numbers_info[i]->id){
			drawTextureBox(400, -100, 32, 32, numbers_info[i]->texture_pos.x(), numbers_info[i]->texture_pos.y(), numbers_info[i]->texture_size.x(), numbers_info[i]->texture_size.y(), *m_res.number, Color(1, 1, 1));
		}
		if (thousand_points6 == numbers_info[i]->id){
			drawTextureBox(375, -100, 32, 32, numbers_info[i]->texture_pos.x(), numbers_info[i]->texture_pos.y(), numbers_info[i]->texture_size.x(), numbers_info[i]->texture_size.y(), *m_res.number, Color(1, 1, 1));
		}
		if (ten_thousand_points6 == numbers_info[i]->id){
			drawTextureBox(350, -100, 32, 32, numbers_info[i]->texture_pos.x(), numbers_info[i]->texture_pos.y(), numbers_info[i]->texture_size.x(), numbers_info[i]->texture_size.y(), *m_res.number, Color(1, 1, 1));
		}
	}
	//combo�{�[�i�X���X�R�A
	int one_points7 = def_score7 / 1 % 10;
	int ten_points7 = def_score7 / 10 % 10;
	int hundred_points7 = def_score7 / 100 % 10;
	int thousand_points7 = def_score7 / 1000 % 10;
	int ten_thousand_points7 = def_score7 / 10000;
	//�_�X���C�v�ϓ��X�R�A
	for (int i = 0; i < 10; i++){
		if (one_points7 == numbers_info[i]->id){
			drawTextureBox(450, -180, 32, 32, numbers_info[i]->texture_pos.x(), numbers_info[i]->texture_pos.y(), numbers_info[i]->texture_size.x(), numbers_info[i]->texture_size.y(), *m_res.number, Color(1, 1, 1));
		}
		if (ten_points7 == numbers_info[i]->id){
			drawTextureBox(425, -180, 32, 32, numbers_info[i]->texture_pos.x(), numbers_info[i]->texture_pos.y(), numbers_info[i]->texture_size.x(), numbers_info[i]->texture_size.y(), *m_res.number, Color(1, 1, 1));
		}
		if (hundred_points7 == numbers_info[i]->id){
			drawTextureBox(400, -180, 32, 32, numbers_info[i]->texture_pos.x(), numbers_info[i]->texture_pos.y(), numbers_info[i]->texture_size.x(), numbers_info[i]->texture_size.y(), *m_res.number, Color(1, 1, 1));
		}
		if (thousand_points7 == numbers_info[i]->id){
			drawTextureBox(375, -180, 32, 32, numbers_info[i]->texture_pos.x(), numbers_info[i]->texture_pos.y(), numbers_info[i]->texture_size.x(), numbers_info[i]->texture_size.y(), *m_res.number, Color(1, 1, 1));
		}
		if (ten_thousand_points7 == numbers_info[i]->id){
			drawTextureBox(350, -180, 32, 32, numbers_info[i]->texture_pos.x(), numbers_info[i]->texture_pos.y(), numbers_info[i]->texture_size.x(), numbers_info[i]->texture_size.y(), *m_res.number, Color(1, 1, 1));
		}
	}
	//���^�b�v����
	int one_points11 = def_score11 / 1 % 10;
	int ten_points11 = def_score11 / 10 % 10;
	//���^�b�v�ϓ���
	for (int i = 0; i < 10; i++){
		if (one_points11 == numbers_info[i]->id){
			drawTextureBox(125, 245, 32, 32, numbers_info[i]->texture_pos.x(), numbers_info[i]->texture_pos.y(), numbers_info[i]->texture_size.x(), numbers_info[i]->texture_size.y(), *m_res.number, Color(1, 1, 1));
		}
		if (ten_points11 == numbers_info[i]->id){
			drawTextureBox(100, 245, 32, 32, numbers_info[i]->texture_pos.x(), numbers_info[i]->texture_pos.y(), numbers_info[i]->texture_size.x(), numbers_info[i]->texture_size.y(), *m_res.number, Color(1, 1, 1));
		}
	}
	//���X���C�v����
	int one_points22 = def_score22 / 1 % 10;
	int ten_points22 = def_score22 / 10 % 10;
	//���X���C�v�ϓ���
	for (int i = 0; i < 10; i++){
		if (one_points22 == numbers_info[i]->id){
			drawTextureBox(125, 195, 32, 32, numbers_info[i]->texture_pos.x(), numbers_info[i]->texture_pos.y(), numbers_info[i]->texture_size.x(), numbers_info[i]->texture_size.y(), *m_res.number, Color(1, 1, 1));
		}
		if (ten_points22 == numbers_info[i]->id){
			drawTextureBox(100, 195, 32, 32, numbers_info[i]->texture_pos.x(), numbers_info[i]->texture_pos.y(), numbers_info[i]->texture_size.x(), numbers_info[i]->texture_size.y(), *m_res.number, Color(1, 1, 1));
		}
	}
	//���^�b�v����
	int one_points33 = def_score33 / 1 % 10;
	int ten_points33 = def_score33 / 10 % 10;
	//���^�b�v�ϓ���
	for (int i = 0; i < 10; i++){
		if (one_points33 == numbers_info[i]->id){
			drawTextureBox(125, 105, 32, 32, numbers_info[i]->texture_pos.x(), numbers_info[i]->texture_pos.y(), numbers_info[i]->texture_size.x(), numbers_info[i]->texture_size.y(), *m_res.number, Color(1, 1, 1));
		}
		if (ten_points33 == numbers_info[i]->id){
			drawTextureBox(100, 105, 32, 32, numbers_info[i]->texture_pos.x(), numbers_info[i]->texture_pos.y(), numbers_info[i]->texture_size.x(), numbers_info[i]->texture_size.y(), *m_res.number, Color(1, 1, 1));
		}
	}
	//���X���C�v����
	int one_points44 = def_score44 / 1 % 10;
	int ten_points44 = def_score44 / 10 % 10;
	//���X���C�v�ϓ���
	for (int i = 0; i < 10; i++){
		if (one_points44 == numbers_info[i]->id){
			drawTextureBox(125, 55, 32, 32, numbers_info[i]->texture_pos.x(), numbers_info[i]->texture_pos.y(), numbers_info[i]->texture_size.x(), numbers_info[i]->texture_size.y(), *m_res.number, Color(1, 1, 1));
		}
		if (ten_points44 == numbers_info[i]->id){
			drawTextureBox(100, 55, 32, 32, numbers_info[i]->texture_pos.x(), numbers_info[i]->texture_pos.y(), numbers_info[i]->texture_size.x(), numbers_info[i]->texture_size.y(), *m_res.number, Color(1, 1, 1));
		}
	}
	//�_�^�b�v����
	int one_points55 = def_score55 / 1 % 10;
	int ten_points55 = def_score55 / 10 % 10;
	//�_�^�b�v�ϓ���
	for (int i = 0; i < 10; i++){
		if (one_points55 == numbers_info[i]->id){
			drawTextureBox(125, -55, 32, 32, numbers_info[i]->texture_pos.x(), numbers_info[i]->texture_pos.y(), numbers_info[i]->texture_size.x(), numbers_info[i]->texture_size.y(), *m_res.number, Color(1, 1, 1));
		}
		if (ten_points55 == numbers_info[i]->id){
			drawTextureBox(100, -55, 32, 32, numbers_info[i]->texture_pos.x(), numbers_info[i]->texture_pos.y(), numbers_info[i]->texture_size.x(), numbers_info[i]->texture_size.y(), *m_res.number, Color(1, 1, 1));
		}
	}
	//�_�X���C�v����
	int one_points66 = def_score66 / 1 % 10;
	int ten_points66 = def_score66 / 10 % 10;
	//�_�X���C�v�ϓ���
	for (int i = 0; i < 10; i++){
		if (one_points66 == numbers_info[i]->id){
			drawTextureBox(125, -105, 32, 32, numbers_info[i]->texture_pos.x(), numbers_info[i]->texture_pos.y(), numbers_info[i]->texture_size.x(), numbers_info[i]->texture_size.y(), *m_res.number, Color(1, 1, 1));
		}
		if (ten_points66 == numbers_info[i]->id){
			drawTextureBox(100, -105, 32, 32, numbers_info[i]->texture_pos.x(), numbers_info[i]->texture_pos.y(), numbers_info[i]->texture_size.x(), numbers_info[i]->texture_size.y(), *m_res.number, Color(1, 1, 1));
		}
	}
	//combo�{�[�i�X����
	int one_points77 = def_score77 / 1 % 10;
	int ten_points77 = def_score77 / 10 % 10;
	//combo�{�[�i�X�ϓ���
	for (int i = 0; i < 10; i++){
		if (one_points77 == numbers_info[i]->id){
			drawTextureBox(125, -180, 32, 32, numbers_info[i]->texture_pos.x(), numbers_info[i]->texture_pos.y(), numbers_info[i]->texture_size.x(), numbers_info[i]->texture_size.y(), *m_res.number, Color(1, 1, 1));
		}
		if (ten_points77 == numbers_info[i]->id){
			drawTextureBox(100, -180, 32, 32, numbers_info[i]->texture_pos.x(), numbers_info[i]->texture_pos.y(), numbers_info[i]->texture_size.x(), numbers_info[i]->texture_size.y(), *m_res.number, Color(1, 1, 1));
		}
	}
	//���U���g�X�R�A���v��
	score8 = score1 + score2 + score3 + score4 + score5 + score6 + score7;

	int one_points8 = score8 / 1 % 10;
	int ten_points8 = score8 / 10 % 10;
	int hundred_points8 = score8 / 100 % 10;
	int thousand_points8 = score8 / 1000 % 10;
	int ten_thousand_points8 = score8 / 10000 % 10;

	//���U���g�X�R�A���v���l
	for (int i = 0; i < 10; i++){
		if (one_points8 == numbers_info[i]->id){
			drawTextureBox(450, -270, 32, 32, numbers_info[i]->texture_pos.x(), numbers_info[i]->texture_pos.y(), numbers_info[i]->texture_size.x(), numbers_info[i]->texture_size.y(), *m_res.number, Color(1, 1, 1));
		}
		if (ten_points8 == numbers_info[i]->id){
			drawTextureBox(425, -270, 32, 32, numbers_info[i]->texture_pos.x(), numbers_info[i]->texture_pos.y(), numbers_info[i]->texture_size.x(), numbers_info[i]->texture_size.y(), *m_res.number, Color(1, 1, 1));
		}
		if (hundred_points8 == numbers_info[i]->id){
			drawTextureBox(400, -270, 32, 32, numbers_info[i]->texture_pos.x(), numbers_info[i]->texture_pos.y(), numbers_info[i]->texture_size.x(), numbers_info[i]->texture_size.y(), *m_res.number, Color(1, 1, 1));
		}
		if (thousand_points8 == numbers_info[i]->id){
			drawTextureBox(375, -270, 32, 32, numbers_info[i]->texture_pos.x(), numbers_info[i]->texture_pos.y(), numbers_info[i]->texture_size.x(), numbers_info[i]->texture_size.y(), *m_res.number, Color(1, 1, 1));
		}
		if (ten_thousand_points8 == numbers_info[i]->id){
			drawTextureBox(350, -270, 32, 32, numbers_info[i]->texture_pos.x(), numbers_info[i]->texture_pos.y(), numbers_info[i]->texture_size.x(), numbers_info[i]->texture_size.y(), *m_res.number, Color(1, 1, 1));
		}
	}

	//��
	drawTextureBox(-450, 180, 128, 128,
		0, 0, 256, 256,
		*m_res.sweet_potato, Color(1, 1, 1));
	//���^�b�v���X���C�v
	drawTextureBox(-250, 170, 128, 128,
		0, 0, 256, 256,
		*m_res.tap_swipe, Color(1, 1, 1));
	//���^�b�v�{�P�O�O�O
	drawTextureBox(-130, 230, 128, 64,
		0, 0, 128, 64,
		*m_res.thousand, Color(1, 1, 1));
	//���X���C�v�{�T�O�O
	drawTextureBox(-115, 180, 128, 64,
		0, 0, 128, 64,
		*m_res.five_hundred, Color(1, 1, 1));
	// ���^�b�v�~
	drawTextureBox(50, 230, 64, 64,
		0, 0, 64, 64,
		*m_res.kakeru, Color(1, 1, 1));
	// ���X���C�v�~
	drawTextureBox(50, 180, 64, 64,
		0, 0, 64, 64,
		*m_res.kakeru, Color(1, 1, 1));
	//���^�b�v��
	drawTextureBox(200, 240, 64, 64,
		0, 0, 64, 64,
		*m_res.iko_ru, Color(1, 1, 1));
	//���X���C�v��
	drawTextureBox(200, 190, 64, 64,
		0, 0, 64, 64,
		*m_res.iko_ru, Color(1, 1, 1));
	//��
	drawTextureBox(-450, 30, 128, 128,
		0, 0, 256, 256,
		*m_res.mushi, Color(1, 1, 1));
	//���^�b�v���X���C�v
	drawTextureBox(-250, 30, 128, 128,
		0, 0, 256, 256,
		*m_res.tap_swipe, Color(1, 1, 1));
	//���^�b�v�{�T�O�O
	drawTextureBox(-115, 90, 128, 64,
		0, 0, 128, 64,
		*m_res.five_hundred, Color(1, 1, 1));
	//���X���C�v�[�T�O�O
	drawTextureBox(-115, 40, 128, 64,
		0, 0, 128, 64,
		*m_res.five_hundred, Color(1, 1, 1));
	//���X���C�v�[
	drawTextureBox(-120, 45, 64, 64,
		0, 0, 64, 64,
		*m_res.mainasu, Color(1, 1, 1));
	// ���^�b�v�~
	drawTextureBox(50, 90, 64, 64,
		0, 0, 64, 64,
		*m_res.kakeru, Color(1, 1, 1));
	// ���X���C�v�~
	drawTextureBox(50, 40, 64, 64,
		0, 0, 64, 64,
		*m_res.kakeru, Color(1, 1, 1));
	//���^�b�v��
	drawTextureBox(200, 100, 64, 64,
		0, 0, 64, 64,
		*m_res.iko_ru, Color(1, 1, 1));
	//���X���C�v��
	drawTextureBox(200, 50, 64, 64,
		0, 0, 64, 64,
		*m_res.iko_ru, Color(1, 1, 1));
	//�_
	drawTextureBox(-450, -120, 128, 128,
		0, 0, 256, 256,
		*m_res.holyghost, Color(1, 1, 1));
	//�_�^�b�v���X���C�v
	drawTextureBox(-250, -130, 128, 128,
		0, 0, 256, 256,
		*m_res.tap_swipe, Color(1, 1, 1));
	//�_�^�b�v�{�P�O�O�O
	drawTextureBox(-130, -70, 128, 64,
		0, 0, 128, 64,
		*m_res.thousand, Color(1, 1, 1));
	// �_�X���C�v�[�T�O�O
	drawTextureBox(-115, -120, 128, 64,
		0, 0, 128, 64,
		*m_res.five_hundred, Color(1, 1, 1));
	// �_�X���C�v�[
	drawTextureBox(-120, -115, 64, 64,
		0, 0, 64, 64,
		*m_res.mainasu, Color(1, 1, 1));
	// �_�^�b�v�~
	drawTextureBox(50, -70, 64, 64,
		0, 0, 64, 64,
		*m_res.kakeru, Color(1, 1, 1));
	// �_�X���C�v�~
	drawTextureBox(50, -120, 64, 64,
		0, 0, 64, 64,
		*m_res.kakeru, Color(1, 1, 1));
	//�_�^�b�v��
	drawTextureBox(200, -60, 64, 64,
		0, 0, 64, 64,
		*m_res.iko_ru, Color(1, 1, 1));
	//�_�X���C�v��
	drawTextureBox(200, -110, 64, 64,
		0, 0, 64, 64,
		*m_res.iko_ru, Color(1, 1, 1));
	//combo�{�[�i�X
	drawTextureBox(-500, -200, 256, 64,
		0, 0, 512, 128,
		*m_res.combo, Color(1, 1, 1));
	// combo�{�[�i�X�~
	drawTextureBox(50, -195, 64, 64,
		0, 0, 64, 64,
		*m_res.kakeru, Color(1, 1, 1));
	//combo�{�[�i�X��
	drawTextureBox(200, -185, 64, 64,
		0, 0, 64, 64,
		*m_res.iko_ru, Color(1, 1, 1));
	//���U���g�X�R�A
	drawTextureBox(-50, -290, 256, 64,
		0, 0, 512, 128,
		*m_res.resultscore, Color(1, 1, 1));
	//���U���g�X�R�A��
	drawTextureBox(200, -280, 64, 64,
		0, 0, 64, 64,
		*m_res.iko_ru, Color(1, 1, 1));
	//���U���g���̐�
	drawLine(-530, -210, 500, -210, 4, Color(0, 0, 0));

}

//�@����
void CResult::Control(){
	if (m_app_env->isPushKey(GLFW_KEY_ENTER)){
		m_change_scene = Type::TITLE;
	}
}