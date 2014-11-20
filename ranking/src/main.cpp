#include "lib/defines.hpp"
#include "lib/appEnv.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include "lib/Random.hpp"
#include "lib/utils.hpp"


// アプリのウインドウサイズ
enum Window {
  WIDTH  = 1320,
  HEIGHT = 720
};
// ランキング数をenumで定義
enum { RANKING_NUM = 4 };
 
// メインプログラム 
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
  app_env.bgColor(Color(0.5, 0.5, 0.5));
 
  //　初期化
  void Init();

  //　更新
  void Update();

  //　描画
  void Draw();
  Texture stage_graph("res/stage_graph.png");
  Texture first("res/first.png");
  Texture second("res/second.png");
  Texture third("res/third.png");
  Texture your_score("res/your_score.png");
  Texture number("res/number.png");
  Texture holyghost("res/holyghost.png");
  float angle = 0.0;
  Texture sweet_potato("res/sweet_potato.png");
  Texture hi_score("res/hi_score.png");
  // 乱数生成器を準備
  Random random;
  // ランキング用スコアの配列(自分のスコアも入れた要素)
  // 初期値は「0」
  int score[RANKING_NUM + 1] = {};
  //スコア
  int score1 = 40000;
  int score2 = 30000;
  int score3 = 20000;
  int score4 = 10000;

  // ファイルからスコアを読み込む
  // TIPS: elemsof は配列の要素数を計算してくれる
  std::ifstream fstr("res/score.txt");
  if (fstr) {
	  for (int i = 0; i < RANKING_NUM; ++i) {
		  fstr >> score[i];
	  }
  }
  //プレイ前のスコア記憶
  int def_score1 = score[0];
  int def_score2 = score[1];
  int def_score3 = score[2];
  int def_score4 = score[3];

 
 // int yousosuu[RANKING_NUM];
  // 末尾に今回のスコアを追加
  // TIPS: elemsofは配列の要素数を計算してくれる
  // スコアを大きい順にソート
 /* while (1) {
	  bool swaped = false;

	  for (int i = 0; i < (elemsof(score) - 1); ++i) {
		  if (score[i] < score[i + 1]) {
			  std::swap(score[i], score[i + 1]);
			  swaped = true;
		  }
	  }
	  if (!swaped) break;
  }*/


  //// ランクインしてるか調べる
  //bool rank_in = false;
  //int rank_num = 0;
  //for (int i = 0; i < RANKING_NUM; ++i) {
	 // if (current_score == score[i]) {
		//  // 最初に同じスコアを見つけたら検索成功
		//  rank_num = i;
		//  rank_in = true;
		//  break;
	 // }
  //}
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

	//1位スコア
	int one_points1 = def_score1 / 1 % 10;
	int ten_points1 = def_score1 / 10 % 10;
	int hundred_points1 = def_score1 / 100 % 10;
	int thousand_points1 = def_score1 / 1000 % 10;
	int ten_thousand_points1 = def_score1 / 10000;
	//１位変動スコア
	for (int i = 0; i < 10; i++){
		if (one_points1 == numbers_info[i].id){
			drawTextureBox(-50, 180, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), number, Color(1, 1, 1));
		}
		if (ten_points1 == numbers_info[i].id){
			drawTextureBox(-75, 180, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), number, Color(1, 1, 1));
		}
		if (hundred_points1 == numbers_info[i].id){
			drawTextureBox(-100, 180, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), number, Color(1, 1, 1));
		}
		if (thousand_points1 == numbers_info[i].id){
			drawTextureBox(-125, 180, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), number, Color(1, 1, 1));
		}
		if (ten_thousand_points1 == numbers_info[i].id){
			drawTextureBox(-150, 180, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), number, Color(1, 1, 1));
		}
	}
	//２位元スコア
	int one_points2 = def_score2 / 1 % 10;
	int ten_points2 = def_score2 / 10 % 10;
	int hundred_points2 = def_score2 / 100 % 10;
	int thousand_points2 = def_score2 / 1000 % 10;
	int ten_thousand_points2 = def_score2 / 10000;
	//２位変動スコア
	for (int i = 0; i < 10; i++){
		if (one_points2 == numbers_info[i].id){
			drawTextureBox(-50, 50, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), number, Color(1, 1, 1));
		}
		if (ten_points2 == numbers_info[i].id){
			drawTextureBox(-75, 50, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), number, Color(1, 1, 1));
		}
		if (hundred_points2 == numbers_info[i].id){
			drawTextureBox(-100, 50, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), number, Color(1, 1, 1));
		}
		if (thousand_points2 == numbers_info[i].id){
			drawTextureBox(-125, 50, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), number, Color(1, 1, 1));
		}
		if (ten_thousand_points2 == numbers_info[i].id){
			drawTextureBox(-150, 50, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), number, Color(1, 1, 1));
		}
	}
	//３位元スコア
	int one_points3 = def_score3 / 1 % 10;
	int ten_points3 = def_score3 / 10 % 10;
	int hundred_points3 = def_score3 / 100 % 10;
	int thousand_points3 = def_score3 / 1000 % 10;
	int ten_thousand_points3 = def_score3 / 10000;
	//３位変動スコア
	for (int i = 0; i < 10; i++){
		if (one_points3 == numbers_info[i].id){
			drawTextureBox(-50, -80, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), number, Color(1, 1, 1));
		}
		if (ten_points3 == numbers_info[i].id){
			drawTextureBox(-75, -80, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), number, Color(1, 1, 1));
		}
		if (hundred_points3 == numbers_info[i].id){
			drawTextureBox(-100, -80, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), number, Color(1, 1, 1));
		}
		if (thousand_points3 == numbers_info[i].id){
			drawTextureBox(-125, -80, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), number, Color(1, 1, 1));
		}
		if (ten_thousand_points3 == numbers_info[i].id){
			drawTextureBox(-150, -80, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), number, Color(1, 1, 1));
		}
	}
	//貴方の元スコア
	int one_points4 = def_score4 / 1 % 10;
	int ten_points4 = def_score4 / 10 % 10;
	int hundred_points4 = def_score4 / 100 % 10;
	int thousand_points4 = def_score4 / 1000 % 10;
	int ten_thousand_points4 = def_score4 / 10000;
	//貴方の変動スコア
	for (int i = 0; i < 10; i++){
		if (one_points4 == numbers_info[i].id){
			drawTextureBox(-50, -210, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), number, Color(1, 1, 1));
		}
		if (ten_points4 == numbers_info[i].id){
			drawTextureBox(-75, -210, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), number, Color(1, 1, 1));
		}
		if (hundred_points4 == numbers_info[i].id){
			drawTextureBox(-100, -210, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), number, Color(1, 1, 1));
		}
		if (thousand_points4 == numbers_info[i].id){
			drawTextureBox(-125, -210, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), number, Color(1, 1, 1));
		}
		if (ten_thousand_points4 == numbers_info[i].id){
			drawTextureBox(-150, -210, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), number, Color(1, 1, 1));
		}
	}
	//１位
	drawTextureBox(-400,160,128,64,0, 0, 128, 64,
		first,
		Color(1, 1, 1));
	//２位
	drawTextureBox(-400, 30, 128, 64, 0, 0, 128, 64,
		second,
		Color(1, 1, 1));
	//３位
	drawTextureBox(-400, -100, 128, 64, 0, 0, 128, 64,
		third,
		Color(1, 1, 1));
	//貴方のスコア
	drawTextureBox(-450, -230, 256, 64, 0, 0, 256, 64,
		your_score,
		Color(1, 1, 1));


	
	//芋
	//drawTextureBox(-450, 180, 128, 128,
	//	0, 0, 256, 256,
	//	sweet_potato, Color(1, 1, 1));
	
	// 80度~-80度をいったりきたり
//	float r = (M_PI / 4) * std::sin(angle);
//	angle += 0.05;
	//神
//	drawTextureBox(20, 150, 256, 256,
	//	0, 0, 256, 256,
	//	holyghost, Color(1, 1, 1), r,Vec2f(1, 1),Vec2f(145, 400));
	//ハイスコア画像
//	drawTextureBox(-250, 180, 512, 128,
	//	0, 0, 512, 128,
	//	hi_score, Color(1, 1, 1));
	//左クリックでTOPへ
	if (app_env.isPushButton(Mouse::LEFT))break;

	// 画面更新
    app_env.update();
  }
  
  // アプリ終了
}
