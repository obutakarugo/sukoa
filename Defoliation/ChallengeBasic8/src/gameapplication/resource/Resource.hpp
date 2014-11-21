#pragma once
#include "../Uncopyable.hpp"
#include "../../lib/texture.hpp"
#include <memory>
//========================================
//リソースクラス
//========================================
class CResource : private Uncopyable{
public:
	//　インスタンスの取得
	static CResource &GetInstance(){
		static CResource instance;
		return instance;
	}

	//　画像
	const std::unique_ptr<Texture>m_title_graph;
	const std::unique_ptr<Texture>m_stage_graph;
	const std::unique_ptr<Texture>m_player_graph;
	const std::unique_ptr<Texture>m_holyghost_graph;
	const std::unique_ptr<Texture>m_sweetpotato_graph;
	const std::unique_ptr<Texture>m_enemy_graph;
	const std::unique_ptr<Texture>m_enemy_death_graph;
	std::vector<std::shared_ptr<Texture>>m_defoliation_graph;

	const std::unique_ptr<Texture>stage_graph;
	const std::unique_ptr<Texture>mushi;
	const std::unique_ptr<Texture>number;
	const std::unique_ptr<Texture>holyghost;
	const std::unique_ptr<Texture>sweet_potato;
	const std::unique_ptr<Texture>combo;
	const std::unique_ptr<Texture>tap_swipe;
	const std::unique_ptr<Texture>resultscore;
	const std::unique_ptr<Texture>iko_ru;
	const std::unique_ptr<Texture>kakeru;
	const std::unique_ptr<Texture>thousand;
	const std::unique_ptr<Texture>five_hundred;

	const std::unique_ptr<Texture>first;
	const std::unique_ptr<Texture>second;
	const std::unique_ptr<Texture>third;
	const std::unique_ptr<Texture>your_score;
	const std::unique_ptr<Texture>hi_score;
	const std::unique_ptr<Texture>mainasu;










	//　音楽
	const std::unique_ptr<Media>m_stage_sound;
	const std::unique_ptr<Media>m_title_sound;
	std::vector<std::unique_ptr<Media>>m_title_button_sound;
	std::vector<std::unique_ptr<Media>>m_hit_sound;
	const std::unique_ptr<Media>m_start_sound;
	const std::unique_ptr<Media>m_finish_sound;
private:
	CResource();
};

