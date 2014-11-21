#include "Resource.hpp"



CResource::CResource():
m_title_graph(std::make_unique<Texture>("res/graph/title_graph.png")),
m_stage_graph(std::make_unique<Texture>("res/graph/stage_graph.png")),
m_player_graph(std::make_unique<Texture>("res/graph/player/player.png")),
m_holyghost_graph(std::make_unique<Texture>("res/graph/holyghost/holyghost.png")),
m_sweetpotato_graph(std::make_unique<Texture>("res/graph/item/sweet_potato.png")),
m_stage_sound(std::make_unique<Media>("res/sound/stage_bg.wav")),
m_title_sound(std::make_unique<Media>("res/sound/title_bg.wav")),
m_start_sound(std::make_unique<Media>("res/sound/start.wav")),
m_finish_sound(std::make_unique<Media>("res/sound/finish.wav")),
m_enemy_graph(std::make_unique<Texture>("res/graph/enemy/enemy.png")),
m_enemy_death_graph(std::make_unique<Texture>("res/graph/enemy/death.png")),
stage_graph(std::make_unique<Texture>("res/stage_graph.png")),
mushi(std::make_unique<Texture>("res/mushi.png")),
number(std::make_unique<Texture>("res/number.png")),
holyghost(std::make_unique<Texture>("res/holyghost.png")),
sweet_potato(std::make_unique<Texture>("res/sweet_potato.png")),
combo(std::make_unique<Texture>("res/combo.png")),
tap_swipe(std::make_unique<Texture>("res/tap_swipe.png")),
resultscore(std::make_unique<Texture>("res/resultscore.png")),
iko_ru(std::make_unique<Texture>("res/iko_ru.png")),
kakeru(std::make_unique<Texture>("res/kakeru.png")),
thousand(std::make_unique<Texture>("res/thousand.png")),
five_hundred(std::make_unique<Texture>("res/five_hundred.png")),
first(std::make_unique<Texture>("res/first.png")),
second(std::make_unique<Texture>("res/second.png")),
third(std::make_unique<Texture>("res/third.png")),
your_score(std::make_unique<Texture>("res/your_score.png")),
hi_score(std::make_unique<Texture>("res/hi_score.png")),
mainasu(std::make_unique<Texture>("res/mainasu.png"))
{
	m_title_button_sound.emplace_back(std::make_unique<Media>("res/sound/title_button01.wav"));
	m_title_button_sound.emplace_back(std::make_unique<Media>("res/sound/title_button02.wav"));
	m_hit_sound.emplace_back(std::make_unique<Media>("res/sound/hit01.wav"));
	m_hit_sound.emplace_back(std::make_unique<Media>("res/sound/hit02.wav"));

	m_defoliation_graph.emplace_back(std::make_shared<Texture>("res/1.png"));
	m_defoliation_graph.emplace_back(std::make_shared<Texture>("res/2.png"));
	m_defoliation_graph.emplace_back(std::make_shared<Texture>("res/3.png"));
	m_defoliation_graph.emplace_back(std::make_shared<Texture>("res/4.png"));

}
