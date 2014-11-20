#include "lib/defines.hpp"
#include "lib/appEnv.hpp"


// アプリのウインドウサイズ
enum Window {
  WIDTH  = 1320,
  HEIGHT = 720
};


// 
// メインプログラム
// 
int main() {
  // アプリウインドウの準備
  AppEnv app_env(Window::WIDTH, Window::HEIGHT,
                 false, false);
  //数字の情報を構造体で定義
  struct Object{
	  int hp;
	  Vec2f pos;
	  Vec2f size;
  };

  Object player;
  Object enemy[21];


  struct number
  {
	  int id;
	  Vec2f pos;
	  Vec2f size;
	  Vec2f texture_pos;
	  Vec2f texture_size;

  };

  //数字を配列で用意
  number numbers_info[10] = {
	  { 0, Vec2f(0, 0), Vec2f(32, 64), Vec2f(16, 32), Vec2f(25, 32) },
	  { 1, Vec2f(0, 0), Vec2f(32, 64), Vec2f(36, 32), Vec2f(22, 32) },
	  { 2, Vec2f(0, 0), Vec2f(32, 64), Vec2f(56, 32), Vec2f(22, 32) },
	  { 3, Vec2f(0, 0), Vec2f(32, 64), Vec2f(76, 32), Vec2f(22, 32) },
	  { 4, Vec2f(0, 0), Vec2f(32, 64), Vec2f(96, 32), Vec2f(25, 32) },
	  { 5, Vec2f(0, 0), Vec2f(32, 64), Vec2f(136, 32), Vec2f(24, 32) },
	  { 6, Vec2f(0, 0), Vec2f(32, 64), Vec2f(156, 32), Vec2f(23, 32) },
	  { 7, Vec2f(0, 0), Vec2f(32, 64), Vec2f(178, 32), Vec2f(23, 32) },
	  { 8, Vec2f(0, 0), Vec2f(32, 64), Vec2f(198, 32), Vec2f(23, 32) },
	  { 9, Vec2f(0, 0), Vec2f(32, 64), Vec2f(220, 32), Vec2f(25, 32) },

  };
  //　初期化
  void Init();

  //　更新
  void Update();

  //　描画
  void Draw();

 // void Drawnumber(int,int,int);

  Texture stage_graph("res/stage_graph.png");
  Texture mushi("res/mushi.png");
  Texture number("res/number.png");
  Texture holyghost("res/holyghost.png");
  Texture sweet_potato("res/sweet_potato.png");
  Texture combo("res/combo.png");
  Texture tap_swipe("res/tap_swipe.png");
  Texture resultscore("res/resultscore.png");
  Texture iko_ru("res/iko_ru.png");
  Texture kakeru("res/kakeru.png");
  Texture thousand("res/thousand.png");
  Texture five_hundred("res/five_hundred.png");

 // int onepoint_x = 0;
 // int onepoint_y = 0;
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
  /*
  int digit_score[5];
  digit_score[0] = 8;
  digit_score[1] = 6;
  digit_score[2] = 5;
  digit_score[3] = 2;
  digit_score[4] = 1;
  */
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


  while (1) {
    // アプリウインドウが閉じられたらプログラムを終了
    if (!app_env.isOpen()) return 0;
    
    // 描画準備
    app_env.setupDraw();

	//背景
	drawTextureBox(-WIDTH / 2, -HEIGHT / 2, WIDTH, HEIGHT,
		0, 0, 1024, 512,
		stage_graph,
		Color(1, 1, 1));


	//芋タップ元スコア
	int one_points1 = def_score1 / 1 % 10;
	int ten_points1 = def_score1 / 10 % 10;
	int hundred_points1 = def_score1 / 100 % 10;
	int thousand_points1 = def_score1 / 1000 % 10;
	int ten_thousand_points1 = def_score1 / 10000;
	//芋タップ変動スコア
	for (int i = 0; i < 10; i++){
		if (one_points1 == numbers_info[i].id){
			drawTextureBox(450, 250, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(),number,Color(1,1,1));
		}
		if (ten_points1 == numbers_info[i].id){
			drawTextureBox(425, 250, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), number, Color(1, 1, 1));
		}
		if (hundred_points1 == numbers_info[i].id){
			drawTextureBox(400, 250, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), number, Color(1, 1, 1));
		}
		if (thousand_points1 == numbers_info[i].id){
			drawTextureBox(375, 250, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), number, Color(1, 1, 1));
		}
		if (ten_thousand_points1 == numbers_info[i].id){
			drawTextureBox(350, 250, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), number, Color(1, 1, 1));
		}
	}
	//芋スワイプ元スコア
	int one_points2 = def_score2 / 1 % 10;
	int ten_points2 = def_score2 / 10 % 10;
	int hundred_points2 = def_score2 / 100 % 10;
	int thousand_points2 = def_score2 / 1000 % 10;
	int ten_thousand_points2 = def_score2 / 10000;
	//芋スワイプ変動スコア
	for (int i = 0; i < 10; i++){
		if (one_points2 == numbers_info[i].id){
			drawTextureBox(450, 200, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), number, Color(1, 1, 1));
		}
		if (ten_points2 == numbers_info[i].id){
			drawTextureBox(425, 200, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), number, Color(1, 1, 1));
		}
		if (hundred_points2 == numbers_info[i].id){
			drawTextureBox(400, 200, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), number, Color(1, 1, 1));
		}
		if (thousand_points2 == numbers_info[i].id){
			drawTextureBox(375, 200, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), number, Color(1, 1, 1));
		}
		if (ten_thousand_points2 == numbers_info[i].id){
			drawTextureBox(350, 200, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), number, Color(1, 1, 1));
		}
	}
	//毛虫タップ元スコア
	int one_points3 = def_score3 / 1 % 10;
	int ten_points3 = def_score3 / 10 % 10;
	int hundred_points3 = def_score3 / 100 % 10;
	int thousand_points3 = def_score3 / 1000 % 10;
	int ten_thousand_points3 = def_score3 / 10000;
	//毛虫タップ変動スコア
	for (int i = 0; i < 10; i++){
		if (one_points3 == numbers_info[i].id){
			drawTextureBox(450, 110, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), number, Color(1, 1, 1));
		}
		if (ten_points3 == numbers_info[i].id){
			drawTextureBox(425, 110, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), number, Color(1, 1, 1));
		}
		if (hundred_points3 == numbers_info[i].id){
			drawTextureBox(400, 110, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), number, Color(1, 1, 1));
		}
		if (thousand_points3 == numbers_info[i].id){
			drawTextureBox(375, 110, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), number, Color(1, 1, 1));
		}
		if (ten_thousand_points3 == numbers_info[i].id){
			drawTextureBox(350, 110, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), number, Color(1, 1, 1));
		}
	}
	//毛虫スワイプ元スコア
	int one_points4 = def_score4 / 1 % 10;
	int ten_points4 = def_score4 / 10 % 10;
	int hundred_points4 = def_score4 / 100 % 10;
	int thousand_points4 = def_score4 / 1000 % 10;
	int ten_thousand_points4 = def_score4 / 10000;
	//毛虫スワイプ変動スコア
	for (int i = 0; i < 10; i++){
		if (one_points4 == numbers_info[i].id){
			drawTextureBox(450, 60, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), number, Color(1, 1, 1));
		}
		if (ten_points4 == numbers_info[i].id){
			drawTextureBox(425, 60, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), number, Color(1, 1, 1));
		}
		if (hundred_points4 == numbers_info[i].id){
			drawTextureBox(400, 60, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), number, Color(1, 1, 1));
		}
		if (thousand_points4 == numbers_info[i].id){
			drawTextureBox(375, 60, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), number, Color(1, 1, 1));
		}
		if (ten_thousand_points4 == numbers_info[i].id){
			drawTextureBox(350, 60, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), number, Color(1, 1, 1));
		}
	}
	//神タップ元スコア
	int one_points5 = def_score5 / 1 % 10;
	int ten_points5 = def_score5 / 10 % 10;
	int hundred_points5 = def_score5 / 100 % 10;
	int thousand_points5 = def_score5 / 1000 % 10;
	int ten_thousand_points5 = def_score5 / 10000;
	//神タップ変動スコア
	for (int i = 0; i < 10; i++){
		if (one_points5 == numbers_info[i].id){
			drawTextureBox(450, -50, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), number, Color(1, 1, 1));
		}
		if (ten_points5 == numbers_info[i].id){
			drawTextureBox(425, -50, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), number, Color(1, 1, 1));
		}
		if (hundred_points5 == numbers_info[i].id){
			drawTextureBox(400, -50, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), number, Color(1, 1, 1));
		}
		if (thousand_points5 == numbers_info[i].id){
			drawTextureBox(375, -50, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), number, Color(1, 1, 1));
		}
		if (ten_thousand_points5 == numbers_info[i].id){
			drawTextureBox(350, -50, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), number, Color(1, 1, 1));
		}
	}
	//神スワイプ元スコア
	int one_points6 = def_score6 / 1 % 10;
	int ten_points6 = def_score6 / 10 % 10;
	int hundred_points6 = def_score6 / 100 % 10;
	int thousand_points6 = def_score6 / 1000 % 10;
	int ten_thousand_points6 = def_score6 / 10000;
	//神スワイプ変動スコア
	for (int i = 0; i < 10; i++){
		if (one_points6 == numbers_info[i].id){
			drawTextureBox(450, -100, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), number, Color(1, 1, 1));
		}
		if (ten_points6 == numbers_info[i].id){
			drawTextureBox(425, -100, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), number, Color(1, 1, 1));
		}
		if (hundred_points6 == numbers_info[i].id){
			drawTextureBox(400, -100, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), number, Color(1, 1, 1));
		}
		if (thousand_points6 == numbers_info[i].id){
			drawTextureBox(375, -100, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), number, Color(1, 1, 1));
		}
		if (ten_thousand_points6 == numbers_info[i].id){
			drawTextureBox(350, -100, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), number, Color(1, 1, 1));
		}
	}
	//comboボーナス元スコア
	int one_points7 = def_score7 / 1 % 10;
	int ten_points7 = def_score7 / 10 % 10;
	int hundred_points7 = def_score7 / 100 % 10;
	int thousand_points7 = def_score7 / 1000 % 10;
	int ten_thousand_points7 = def_score7 / 10000;
	//神スワイプ変動スコア
	for (int i = 0; i < 10; i++){
		if (one_points7 == numbers_info[i].id){
			drawTextureBox(450, -180, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), number, Color(1, 1, 1));
		}
		if (ten_points7 == numbers_info[i].id){
			drawTextureBox(425, -180, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), number, Color(1, 1, 1));
		}
		if (hundred_points7 == numbers_info[i].id){
			drawTextureBox(400, -180, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), number, Color(1, 1, 1));
		}
		if (thousand_points7 == numbers_info[i].id){
			drawTextureBox(375, -180, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), number, Color(1, 1, 1));
		}
		if (ten_thousand_points7 == numbers_info[i].id){
			drawTextureBox(350, -180, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), number, Color(1, 1, 1));
		}
	}
	//芋タップ元数
	int one_points11 = def_score11 / 1 % 10;
	int ten_points11 = def_score11 / 10 % 10;
	//芋タップ変動数
	for (int i = 0; i < 10; i++){
		if (one_points11 == numbers_info[i].id){
			drawTextureBox(125, 245, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), number, Color(1, 1, 1));
		}
		if (ten_points11 == numbers_info[i].id){
			drawTextureBox(100, 245, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), number, Color(1, 1, 1));
		}
	}
	//芋スワイプ元数
	int one_points22 = def_score22 / 1 % 10;
	int ten_points22 = def_score22 / 10 % 10;
	//芋スワイプ変動数
	for (int i = 0; i < 10; i++){
		if (one_points22 == numbers_info[i].id){
			drawTextureBox(125, 195, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), number, Color(1, 1, 1));
		}
		if (ten_points22 == numbers_info[i].id){
			drawTextureBox(100, 195, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), number, Color(1, 1, 1));
		}
	}
	//虫タップ元数
	int one_points33 = def_score33 / 1 % 10;
	int ten_points33 = def_score33 / 10 % 10;
	//虫タップ変動数
	for (int i = 0; i < 10; i++){
		if (one_points33 == numbers_info[i].id){
			drawTextureBox(125, 105, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), number, Color(1, 1, 1));
		}
		if (ten_points33 == numbers_info[i].id){
			drawTextureBox(100, 105, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), number, Color(1, 1, 1));
		}
	}
	//虫スワイプ元数
	int one_points44 = def_score44 / 1 % 10;
	int ten_points44 = def_score44 / 10 % 10;
	//虫スワイプ変動数
	for (int i = 0; i < 10; i++){
		if (one_points44 == numbers_info[i].id){
			drawTextureBox(125, 55, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), number, Color(1, 1, 1));
		}
		if (ten_points44 == numbers_info[i].id){
			drawTextureBox(100, 55, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), number, Color(1, 1, 1));
		}
	}
	//神タップ元数
	int one_points55 = def_score55 / 1 % 10;
	int ten_points55 = def_score55 / 10 % 10;
	//神タップ変動数
	for (int i = 0; i < 10; i++){
		if (one_points55 == numbers_info[i].id){
			drawTextureBox(125, -55, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), number, Color(1, 1, 1));
		}
		if (ten_points55 == numbers_info[i].id){
			drawTextureBox(100, -55, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), number, Color(1, 1, 1));
		}
	}
	//神スワイプ元数
	int one_points66 = def_score66 / 1 % 10;
	int ten_points66 = def_score66 / 10 % 10;
	//神スワイプ変動数
	for (int i = 0; i < 10; i++){
		if (one_points66 == numbers_info[i].id){
			drawTextureBox(125, -105, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), number, Color(1, 1, 1));
		}
		if (ten_points66 == numbers_info[i].id){
			drawTextureBox(100, -105, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), number, Color(1, 1, 1));
		}
	}
	//comboボーナス元数
	int one_points77 = def_score77 / 1 % 10;
	int ten_points77 = def_score77 / 10 % 10;
	//comboボーナス変動数
	for (int i = 0; i < 10; i++){
		if (one_points77 == numbers_info[i].id){
			drawTextureBox(125, -180, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), number, Color(1, 1, 1));
		}
		if (ten_points77 == numbers_info[i].id){
			drawTextureBox(100, -180, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), number, Color(1, 1, 1));
		}
	}
	//リザルトスコア合計元
	score8 = score1 + score2 + score3 + score4 + score5 + score6 + score7;

	int one_points8 = score8 / 1 % 10;
	int ten_points8 = score8 / 10 % 10;
	int hundred_points8 = score8 / 100 % 10;
	int thousand_points8 = score8 / 1000 % 10;
	int ten_thousand_points8 = score8 / 10000 % 10;

	//リザルトスコア合計数値
	for (int i = 0; i < 10; i++){
		if (one_points8 == numbers_info[i].id){
			drawTextureBox(450, -270, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), number, Color(1, 1, 1));
		}
		if (ten_points8 == numbers_info[i].id){
			drawTextureBox(425, -270, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), number, Color(1, 1, 1));
		}
		if (hundred_points8 == numbers_info[i].id){
			drawTextureBox(400, -270, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), number, Color(1, 1, 1));
		}
		if (thousand_points8 == numbers_info[i].id){
			drawTextureBox(375, -270, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), number, Color(1, 1, 1));
		}
		if (ten_thousand_points8 == numbers_info[i].id){
			drawTextureBox(350, -270, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), number, Color(1, 1, 1));
		}
	}
	/*
	for (int i = 0; i < 10; i++){
		if (i == digit_score[0]){

			drawTextureBox(numbers_info[i].pos.x() - numbers_info[i].size.x() * 0, numbers_info[i].pos.y(), numbers_info[i].size.x(), numbers_info[i].size.y(),
				numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(),
				number, Color(1, 1, 1));

		}

		if (i == digit_score[1]){

			drawTextureBox(numbers_info[i].pos.x() - numbers_info[i].size.x() * 1, numbers_info[i].pos.y(), numbers_info[i].size.x(), numbers_info[i].size.y(),
				numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(),
				number, Color(1, 1, 1));

		}

		if (i == digit_score[2]){

			drawTextureBox(numbers_info[i].pos.x() - numbers_info[i].size.x() * 2, numbers_info[i].pos.y(), numbers_info[i].size.x(), numbers_info[i].size.y(),
				numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(),
				number, Color(1, 1, 1));

		}

		if (i == digit_score[3]){

			drawTextureBox(numbers_info[i].pos.x() - numbers_info[i].size.x() * 3, numbers_info[i].pos.y(), numbers_info[i].size.x(), numbers_info[i].size.y(),
				numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(),
				number, Color(1, 1, 1));

		}

		if (i == digit_score[4]){

			drawTextureBox(numbers_info[i].pos.x() - numbers_info[i].size.x() * 4, numbers_info[i].pos.y(), numbers_info[i].size.x(), numbers_info[i].size.y(),
				numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(),
				number, Color(1, 1, 1));

		}

	}
	*/

	//芋
	drawTextureBox(-450, 180, 128, 128,
		0, 0, 256, 256,
		sweet_potato, Color(1, 1, 1));
	//芋タップ＆スワイプ
	drawTextureBox(-250, 170, 128, 128,
		0, 0, 256, 256,
		tap_swipe, Color(1, 1, 1));
	//芋タップ＋１０００
	drawTextureBox(-130, 230, 128, 64,
		0, 0, 128, 64,
		thousand, Color(1, 1, 1));
	//芋スワイプ＋５００
	drawTextureBox(-115, 180, 128, 64,
		0, 0, 128, 64,
		five_hundred, Color(1, 1, 1));
	// 芋タップ×
	drawTextureBox(50, 230, 64, 64,
		0, 0, 64, 64,
		kakeru, Color(1, 1, 1));
	// 芋スワイプ×
	drawTextureBox(50, 180, 64, 64,
		0, 0, 64, 64,
		kakeru, Color(1, 1, 1));
	//芋タップ＝
	drawTextureBox(200, 240, 64, 64,
		0, 0, 64, 64,
		iko_ru, Color(1, 1, 1));
	//芋スワイプ＝
	drawTextureBox(200, 190, 64, 64,
		0, 0, 64, 64,
		iko_ru, Color(1, 1, 1));
	//虫
	drawTextureBox(-450, 30, 128, 128,
		0, 0, 256, 256,
		mushi, Color(1, 1, 1));
	//虫タップ＆スワイプ
	drawTextureBox(-250, 30, 128, 128,
		0, 0, 256, 256,
		tap_swipe, Color(1, 1, 1));
	//虫タップ＋５００
	drawTextureBox(-115, 90, 128, 64,
		0, 0, 128, 64,
		five_hundred, Color(1, 1, 1));
	//虫スワイプー５００
	drawTextureBox(-115, 40, 128, 64,
		0, 0, 128, 64,
		five_hundred, Color(1, 1, 1));
	// 虫タップ×
	drawTextureBox(50, 90, 64, 64,
		0, 0, 64, 64,
		kakeru, Color(1, 1, 1));
	// 虫スワイプ×
	drawTextureBox(50, 40, 64, 64,
		0, 0, 64, 64,
		kakeru, Color(1, 1, 1));
	//虫タップ＝
	drawTextureBox(200, 100, 64, 64,
		0, 0, 64, 64,
		iko_ru, Color(1, 1, 1));
	//虫スワイプ＝
	drawTextureBox(200, 50, 64, 64,
		0, 0, 64, 64,
		iko_ru, Color(1, 1, 1));
	//神
	drawTextureBox(-450, -120, 128, 128,
		0, 0, 256, 256,
		holyghost, Color(1, 1, 1));
	//神タップ＆スワイプ
	drawTextureBox(-250, -130, 128, 128,
		0, 0, 256, 256,
		tap_swipe, Color(1, 1, 1));
	//神タップ＋１０００
	drawTextureBox(-130, -70, 128, 64,
		0, 0, 128, 64,
		thousand, Color(1, 1, 1));
	// 神スワイプー５００
	drawTextureBox(-115, -120, 128, 64,
		0, 0, 128, 64,
		five_hundred, Color(1, 1, 1));
	// 神タップ×
	drawTextureBox(50, -70, 64, 64,
		0, 0, 64, 64,
		kakeru, Color(1, 1, 1));
	// 神スワイプ×
	drawTextureBox(50, -120, 64, 64,
		0, 0, 64, 64,
		kakeru, Color(1, 1, 1));
	//神タップ＝
	drawTextureBox(200, -60, 64, 64,
		0, 0, 64, 64,
		iko_ru, Color(1, 1, 1));
	//神スワイプ＝
	drawTextureBox(200, -110, 64, 64,
		0, 0, 64, 64,
		iko_ru, Color(1, 1, 1));
	//comboボーナス
	drawTextureBox(-500, -200, 256, 64,
		0, 0, 512, 128,
		combo, Color(1, 1, 1));
	// comboボーナス×
	drawTextureBox(50, -195, 64, 64,
		0, 0, 64, 64,
		kakeru, Color(1, 1, 1));
	//comboボーナス＝
	drawTextureBox(200, -185, 64, 64,
		0, 0, 64, 64,
		iko_ru, Color(1, 1, 1));
	//リザルトスコア
	drawTextureBox(-50, -290, 256, 64,
		0, 0, 512, 128,
		resultscore, Color(1, 1, 1));
		//リザルトスコア＝
		drawTextureBox(200, -280, 64, 64,
			0, 0, 64, 64,
			iko_ru, Color(1, 1, 1));
		//リザルト↑の線
		drawLine(-530, -210, 500, -210, 4, Color(0, 0, 0));

	//スコア
	//drawTextureBox(-100, 200, 50, 50,
	//	15, 0, 58, 120,
	//	number, Color(1, 1, 1));

	

	// 画面更新
    app_env.update();
  }
  
  // アプリ終了
}
