//
// Created by johnn on 2024/5/13.
//

#include "ShapaBullet.hpp"
#include <cmath>
#include <random>
#include <string>
#include <utility>

#include "UI/Animation/DirtyEffect.hpp"
#include "Enemy/Enemy.hpp"
#include "Engine/Group.hpp"
#include "Engine/IObject.hpp"
#include "ShapaBullet.hpp"
#include "Scene/PlayScene.hpp"
#include "Engine/Point.hpp"

class Turret;

ShapaBullet::ShapaBullet(Engine::Point position, Engine::Point forwardDirection, float rotation, Turret* parent) :
	Bullet("play/bullet-11.png", 800, 0.1, position, forwardDirection, rotation - ALLEGRO_PI / 2, parent) {
}
void ShapaBullet::OnExplode(Enemy* enemy) {
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist(2, 10);
	getPlayScene()->GroundEffectGroup->AddNewObject(new DirtyEffect("play/dirty-2.png", dist(rng), enemy->Position.x, enemy->Position.y));
}

