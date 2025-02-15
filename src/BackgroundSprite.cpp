#include "BackgroundSprite.hpp"

#include "Director.hpp"
#include "SpriteFrameCache.hpp"

BackgroundSprite::BackgroundSprite(int index, LevelLayer* layer) {
    auto camera = Director::get()->m_camera;
    if (index == 0) index = 1;
    std::string name = (std::string) "game_bg_" + (index < 10 ? "0" : "") + std::to_string(index) + "_001.png";
    m_sprite = std::make_shared<RepeatForeverSprite>(SpriteFrameCache::get()->getSpriteFrameByName(name), camera->m_viewSize.y * camera->m_viewScale.y);
    m_sprite->m_position = {0, 0};
    addChild(m_sprite);

    m_sprite->m_color = layer->m_colorChannels[1000]->m_currColor;
}

void BackgroundSprite::update(float delta) {
    auto camera = Director::get()->m_camera;

    m_position = {camera->m_position.x, camera->m_position.y};
    m_sprite->m_lockedHeight = camera->m_viewSize.y * camera->m_viewScale.y;

    Node::update(delta);
}