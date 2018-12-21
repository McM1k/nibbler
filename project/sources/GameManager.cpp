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
GameManager::GameManager(int x, int y) : state(eGameState::Pause), map(x, y), ms_per_frame(16),
    intended_direction(Map::direction::up), frame_required_for_a_move(62), current_frame(0) {
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
}

/* ******************************* */
/*            Accessors            */
/* ******************************* */
eGameState GameManager::getState() const {
    return state;
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

void GameManager::update() {




}

void GameManager::render() {
    display->display(map, ui);
}

void GameManager::gamePause() {}

void GameManager::gameRun() {
    update();
}

void GameManager::gameQuit() {freeLib();}

void GameManager::gameOver() {}

void GameManager::inputQuit() {this->state = eGameState::Quit;}

void GameManager::inputLib1() {changeLib(eSharedLibs::ncursesLib);}

void GameManager::inputLib2() {changeLib(eSharedLibs::ncursesLib);}//TODO change lib used

void GameManager::inputLib3() {changeLib(eSharedLibs::ncursesLib);}// TODO change lib used

void GameManager::inputPause() {this->state = (this->state == eGameState::Pause ? eGameState::Game : eGameState::Pause);}

void GameManager::inputUp() {
    if (this->intended_direction != Map::direction::down)
        this->intended_direction = Map::direction::up;
}

void GameManager::inputDown() {
    if (this->intended_direction != Map::direction::up)
        this->intended_direction = Map::direction::down;
}

void GameManager::inputLeft() {
    if (this->intended_direction != Map::direction::right)
        this->intended_direction = Map::direction::left;
}

void GameManager::inputRight() {
    if (this->intended_direction != Map::direction::left)
        this->intended_direction = Map::direction::right;
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

