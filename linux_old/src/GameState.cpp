#include "GameState.h"

void GameState::initKeybinds() {
	std::fstream ifs("Config/gamestate_keybinds.ini");

	if (ifs.is_open()) {

		std::string key1 = "";
		std::string key2 = "";

		while (ifs >> key1 >> key2) {
			this->keybinds[key1] = this->supportedKeys->at(key2);
		}
	}
	ifs.close();

	//�������� � � ������� ��������!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
}


void GameState::initTextures(){
	if (!this->textures["PLAYER"].loadFromFile("Resources/Images/Sprites/Player/cow.png")) {//��������!!!!!!!!!
		throw ("ERROR::GAME_STATE::NOT_LOADED_TEXTURE");
	}
}

void GameState::initPlayers(){
	float high = window->getSize().x;
	float weigh = window->getSize().y;
	this->player = new Player(600, 300, this->textures["PLAYER"]);//��������!!!!!!!!!
}

void GameState::initMusic() {
	/*if (!this->soundBuffer.loadFromFile("Resources/Sounds/game3.ogg"))
		throw ("ERROR::GAME_STATE::NOT_LOADED_MUSIC");
	this->mainMusic.setBuffer(soundBuffer);*/
	if (!this->mainMusic.openFromFile("Resources/Sounds/game3.ogg"))
		throw ("ERROR::GAME_STATE::NOT_LOADED_MUSIC");
	this->mainMusic.setLoop(true);
	this->mainMusic.play();
}

void GameState::initPlatforms() {
	std::fstream ifs("Resources/Levels/level1.level");

	if (ifs.is_open()) {
		float x = 0;
		float y = 0;
		float weight = 0;
		float height = 0;
		std::string colour = "";

		int curr = 0;
		while (ifs >> x >> y >> weight >> height >> colour) {
			this->platforms.push_back(new Platform(x, y, weight, height, sf::Color::Blue));
		}
	}

	ifs.close();
}


GameState::GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
	: State(window, supportedKeys, states) {
	this->initKeybinds();
	this->initTextures();
	this->initPlayers();
	this->initMusic();
	this->initPlatforms();
}

GameState::~GameState() {
	delete this->player;

}

//void GameState::updateCollision(){
//	for (auto& it : this->platforms) {
//		it->checkCollision(this->queueCollision, this->player->heatbox);
//		std::ofstream out;          // ����� ��� ������
//		out.open("de_bug/test.txt");      // ��������� ���� ��� ������
//		if (!this->queueCollision.empty()) {
//			if (out.is_open())
//			{
//				sf::FloatRect coord = this->queueCollision.back();
//				out << coord.getPosition().x << " " << coord.getPosition().y << " " << coord.height << std::endl;
//			}
//			out.close();
//		}
//	}
//	if (!this->queueCollision.empty())
//		this->queueCollision.pop();
//}

void GameState::hp_upd() {
	font.loadFromFile("Fonts/ComicoroRu_0.ttf");
	hpText.setFont(font); // �������� 'font' �� ��� ����, ���� �� ����loadFromFile("Fonts/ComicoroRu_0.ttf")
	hpText.setCharacterSize(24); // ������ ������
	hpText.setFillColor(sf::Color::Green); // ���� ������
	hpText.setString("HP: " + std::to_string(this->player->heatbox->getCurrentHP())); // �����

	// ��������� ������� ������
	hpText.setPosition(10.f, 10.f); // ��������� ��������� � ������� ����� ���� ������
	hpBarBack.setSize(sf::Vector2f(200.f, 20.f));
	hpBarBack.setFillColor(sf::Color(50, 50, 50, 200));
	hpBarBack.setPosition(10.f, 40.f);

	// ��������� ������� HP
	float hpPercent = static_cast<float>(this->player->heatbox->getCurrentHP()) / this->player->heatbox->getMaxHP();
	hpBar.setSize(sf::Vector2f(200.f * hpPercent, 20.f));
	hpBar.setFillColor(sf::Color::Green);
	hpBar.setPosition(10.f, 40.f);
}

void GameState::updateInput(const float& dt) {
	//update player input
	this->player->move(0.f, 1.f, dt);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_LEFT"))))
		this->player->move(-1.f, 0.f, dt);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_RIGHT"))))
		this->player->move(1.f, 0.f, dt);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_UP"))))
		if (energy >= 10 && energy <= 100 && block == false) {
			this->player->move(0.f, -1.f, dt);
			energy = energy-2;
		}
		if (energy < 10) block = true;


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_DOWN"))))
		this->player->move(0.f, 1.f, dt);

	// � ������ updateInput()
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("DAMAGE")))) {
		// ���������, ������ �� ���������� ������� � ������� ���������� ��������� �����
		if (damageTimer.getElapsedTime().asSeconds() >= 0.3f) { // ��������, ���� ������ 0.5 �������
			this->player->heatbox->getDamage(10); // ������� ���� ��������� ������
			damageTimer.restart(); // ���������� ������
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("CLOSE"))))
		this->endState();

	hp_upd();
	energy = energy + 0.4;
	if (energy >= 50) {
		block = false;
	}
	if (energy >= 100) {
		energy = 100;
	}
}

void GameState::update(const float& dt) {
	this->updateMousePosition();
	this->updateInput(dt);

	//this->updateCollision();

	// ��������� �������� ������ this->player->heatbox->setVelocityy(0.f);
	this->player->update(dt);

	// ��������� � ������������ ��������
}

void GameState::renderPlatforms(sf::RenderTarget* target) {
	for (auto& it : this->platforms) {
		it->render(target);
	}
}

void GameState::render(sf::RenderTarget* target) {
	if (!target) {
		target = this->window;
	}
	target->draw(hpText);
	target->draw(this->hpBarBack);
	target->draw(this->hpBar);

	// ����� ������� ����� � �������� ��������
	sf::RectangleShape energyBar;
	energyBar.setSize(sf::Vector2f(200.f * (energy / 100.f), 5.f)); // ������ ������� 5 ��������, ����� ������� �� �����
	energyBar.setFillColor(sf::Color::Yellow);
	energyBar.setPosition(10.f, 95.f); // ������� ����� � �������� ��������, �� ������� ����
	target->draw(energyBar);

	// ��������� �����������
	//for (auto& collider : this->colliders) {
	//	target->draw(collider);
	//}

	this->renderPlatforms(target);

	this->player->render(target);
}
