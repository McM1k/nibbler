
#include <future>
#include "../includes/Inputs.hpp"

/* ******************************* */
/*    Constructors & destructor    */
/* ******************************* */
Inputs::Inputs(MlxData _mlxData) : mlxData(_mlxData), current_input(eInputs::noInput) {
//    this->events_ptr = &ft_events;
//    this->destroy_ptr = &ft_destroy;
    mlx_hook(this->mlxData.getWindow(), 17, 0, (int (*)())(&ft_destroy), reinterpret_cast<void *>(this));
    mlx_hook(this->mlxData.getWindow(), 2, 0, (int (*)())(&ft_events), reinterpret_cast<void *>(getMlxData()));

    //mlx_loop( mlxData.getMlx());
//    std::future<int> fut = std::async (std::launch::async, mlx_loop, mlxData.getMlx());
 //   int ret = fut.get();
    std::thread mlxInputThread(mlx_loop, mlxData.getMlx());
    mlxInputThread.detach();
}


/* ******************************* */
/*            Accessors            */
/* ******************************* */
eInputs Inputs::getCurrent_input() const {
    return this->current_input;
}

MlxData *Inputs::getMlxData(){
    return &(this->mlxData);
}
/* ******************************* */
/*       operators  overload       */
/* ******************************* */

/* ******************************* */
/*            Functions            */
/* ******************************* */
void Inputs::stockInput(int input) {
    switch(input) {
        case ESC_KEY:
            this->current_input = eInputs::quit;
            break;
        case ONE_KEY:
            this->current_input = eInputs::lib1;
            break;
        case TWO_KEY:
            this->current_input = eInputs::lib2;
            break;
        case THREE_KEY:
            this->current_input = eInputs::lib3;
            break;
        case SPACE_KEY:
            this->current_input = eInputs::pause;
            break;
        case LEFT_KEY:
            this->current_input = eInputs::left;
            break;
        case RIGHT_KEY:
            this->current_input = eInputs::right;
            break;
        case UP_KEY:
            this->current_input = eInputs::up;
            break;
        case DOWN_KEY:
            this->current_input = eInputs::down;
            break;
        default:
            this->current_input = eInputs::noInput;
    }
}

int     ft_events(int keycode, void *param)
{
    auto instance = reinterpret_cast<Inputs *>(param);
    instance->stockInput(keycode);

    if (instance->getCurrent_input() == eInputs::quit)
        ft_destroy(reinterpret_cast<void *>(instance->getMlxData())); // TODO could lead to leaks
    return keycode;
}

int     ft_destroy(void *param)
{
    auto data = reinterpret_cast<MlxData *>(param);
    mlx_destroy_image(data->getMlx(), data->getImg_addr());
    mlx_destroy_window(data->getMlx(), data->getWindow());
    return 0;
}
/* ******************************* */
/*            Exceptions           */
/* ******************************* */

