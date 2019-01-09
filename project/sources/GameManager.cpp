/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameManager.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 14:08:47 by gboudrie          #+#    #+#             */
/*   Updated: 2018/12/18 14:08:47 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/GameManager.hpp"

/* ******************************* */
/*    Constructors & destructor    */
/* ******************************* */
GameManager::GameManager(int x, int y) : state(eGameState::Pause), map(x, y) {
    instantiateFromLib(eSharedLibs::ncursesLib);

    map_states.insert(std::pair<eGameState, ft_state >(eGameState::Pause, &GameManager::gamePause));
    map_states.insert(std::pair<eGameState, ft_state >(eGameState::Game, &GameManager::gameRun));
    map_states.insert(std::pair<eGameState, ft_state >(eGameState::Quit, &GameManager::gameQuit));
    map_states.insert(std::pair<eGameState, ft_state >(eGameState::GameOver, &GameManager::gameOver));

    map_inputs.insert(std::pair<eInputs, ft_input >(eInputs::quit, &GameManager::inputQuit));
    map_inputs.insert(std::pair<eInputs, ft_input >(eInputs::lib1, &GameManager::inputLib1));
    map_inputs.insert(std::pair<eInputs, ft_input >(eInputs::lib2, &GameManager::inputLib2));
    map_inputs.insert(std::pair<eInputs, ft_input >(eInputs::lib3, &GameManager::inputLib3));
    map_inputs.insert(std::pair<eInputs, ft_input >(eInputs::pause, &GameManager::inputPause));
    map_inputs.insert(std::pair<eInputs, ft_input >(eInputs::up, &GameManager::inputUp));
    map_inputs.insert(std::pair<eInputs, ft_input >(eInputs::left, &GameManager::inputLeft));
    map_inputs.insert(std::pair<eInputs, ft_input >(eInputs::right, &GameManager::inputRight));
    map_inputs.insert(std::pair<eInputs, ft_input >(eInputs::down, &GameManager::inputDown));
    map_inputs.insert(std::pair<eInputs, ft_input >(eInputs::noInput, &GameManager::inputNo));

    newGame();
}

/* ******************************* */
/*            Accessors            */
/* ******************************* */
eGameState GameManager::getState() const {
    return this->state;
}

/* ******************************* */
/*       operators  overload       */
/* ******************************* */

/* ******************************* */
/*            Functions            */
/* ******************************* */
void GameManager::freeLib() {
    if (this->display)
        this->libLoader->loadFunction<void (*)(IEntity *)>("deleteDisplay")(this->display);
    if (this->input)
        this->libLoader->loadFunction<void (*)(IInputs *)>("deleteInputs")(this->input);
    delete this->libLoader;
}

void GameManager::instantiateFromLib(eSharedLibs lib) {
    this->libLoader = new LibLoader(lib);
    this->display = this->libLoader->loadFunction<IEntity *(*)(int, int)>("newDisplay")(map.getXSize(), map.getYSize());
    this->input = this->libLoader->loadFunction<IInputs *(*)()>("newInputs")();
}

void GameManager::changeLib(eSharedLibs lib) {
    if (lib == libLoader->getLibName())
        return;
    state = eGameState::Pause;
    freeLib();
    instantiateFromLib(lib);
}

void GameManager::newGame() {
    this->ms_per_frame = std::chrono::duration<int, std::milli>(16);
    this->intended_direction = Map::eDirection::up;
    this->frame_required_for_a_move = 62;
    this->current_frame = 0;
    map.spawnSnake();
    map.spawnFruit();

    loopGame();
}

void GameManager::update() {
    auto snakeSize = this->map.getSnake().size();
    this->map.moveSnake(this->intended_direction);
    if (this->map.getSnake().size() != snakeSize)
        this->ui.addScore(100);
}

void GameManager::render() {display->display(map, ui);}

void GameManager::gamePause() {this->ui.setGameState(this->state);}

void GameManager::gameRun() {
    this->current_frame ++;
    if (this->current_frame >= this->frame_required_for_a_move) {
        update();
        this->current_frame = 0;
    }
}

void GameManager::gameQuit() {freeLib();}

void GameManager::gameOver() {this->ui.setGameState(this->state);}

void GameManager::inputQuit() {this->state = eGameState::Quit;}

void GameManager::inputLib1() {changeLib(eSharedLibs::ncursesLib);}

void GameManager::inputLib2() {changeLib(eSharedLibs::ncursesLib);}//TODO change lib used

void GameManager::inputLib3() {changeLib(eSharedLibs::ncursesLib);}// TODO change lib used

void GameManager::inputPause() {
    if (this->state == eGameState::Pause) {
        this->state = eGameState::Game;
        this->ui.setGameState(this->state);
    }
    else if (this->state == eGameState::Game)
        this->state = eGameState::Pause;
}

void GameManager::inputUp() {
    if (this->intended_direction != Map::eDirection::down)
        this->intended_direction = Map::eDirection::up;
}

void GameManager::inputDown() {
    if (this->intended_direction != Map::eDirection::up)
        this->intended_direction = Map::eDirection::down;
}

void GameManager::inputLeft() {
    if (this->intended_direction != Map::eDirection::right)
        this->intended_direction = Map::eDirection::left;
}

void GameManager::inputRight() {
    if (this->intended_direction != Map::eDirection::left)
        this->intended_direction = Map::eDirection::right;
}

void GameManager::inputNo() {}

void GameManager::loopGame() {
    while (this->getState() != eGameState::Quit)
    {
        std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();

        (this->*map_inputs[input->getInput()])();
        (this->*map_states[this->state])();
        render();

        std::this_thread::sleep_for(start + ms_per_frame - std::chrono::high_resolution_clock::now());
    }
    (this->*map_states[this->state])();
}
/* ******************************* */
/*            Exceptions           */
/* ******************************* */

