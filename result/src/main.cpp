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
	  { 0, Vec2f(0, 0), Vec2f(32, 64), Vec2f(10, 32), Vec2f(25, 32) },
	  { 1, Vec2f(0, 0), Vec2f(32, 64), Vec2f(36, 32), Vec2f(22, 32) },
	  { 2, Vec2f(0, 0), Vec2f(32, 64), Vec2f(56, 32), Vec2f(22, 32) },
	  { 3, Vec2f(0, 0), Vec2f(32, 64), Vec2f(76, 32), Vec2f(22, 32) },
	  { 4, Vec2f(0, 0), Vec2f(32, 64), Vec2f(96, 32), Vec2f(25, 32) },
	  { 5, Vec2f(0, 0), Vec2f(32, 64), Vec2f(136, 32), Vec2f(24, 32) },
	  { 6, Vec2f(0, 0), Vec2f(32, 64), Vec2f(158, 32), Vec2f(23, 32) },
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
  Texture stage_graph("res/stage_graph.png");
  Texture mushi("res/mushi.png");
  Texture number("res/number.png");
  Texture holyghost("res/holyghost.png");
  Texture sweet_potato("res/sweet_potato.png");
  Texture combo("res/combo.png");
  Texture tap_swipe("res/tap_swipe.png");
  Texture resultscore("res/resultscore.png");

  int score = 12568;
  int digit_score[5];

  digit_score[0] = 8;
  digit_score[1] = 6;
  digit_score[2] = 5;
  digit_score[3] = 2;
  digit_score[4] = 1;

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

	//芋
	drawTextureBox(-450, 180, 128, 128,
		0, 0, 256, 256,
		sweet_potato, Color(1, 1, 1));
	//虫
	drawTextureBox(-450, 30, 128, 128,
		0, 0, 256, 256,
		mushi, Color(1, 1, 1));
	//神
	drawTextureBox(-450, -120, 128, 128,
		0, 0, 256, 256,
		holyghost, Color(1, 1, 1));
	
	//タップ＆スワイプ
	drawTextureBox(-250, 180, 128, 128,
		0, 0, 256, 256,
		tap_swipe, Color(1, 1, 1));
	//タップ＆スワイプ
	drawTextureBox(-250, 30, 128, 128,
		0, 0, 256, 256,
		tap_swipe, Color(1, 1, 1));
	//タップ＆スワイプ
	drawTextureBox(-250, -120, 128, 128,
		0, 0, 256, 256,
		tap_swipe, Color(1, 1, 1));
	//comboボーナス
	drawTextureBox(-500, -200, 256, 64,
		0, 0, 512, 128,
		combo, Color(1, 1, 1));
	//リザルトスコア
	drawTextureBox(-50, -300, 256, 64,
		0, 0, 512, 128,
		resultscore, Color(1, 1, 1));
	//スコア
	//drawTextureBox(-100, 200, 50, 50,
	//	15, 0, 58, 120,
	//	number, Color(1, 1, 1));

	

	// 画面更新
    app_env.update();
  }
  
  // アプリ終了
}
