
#include "../includes/Inputs.hpp"

/* ******************************* */
/*    Constructors & destructor    */
/* ******************************* */
Inputs::Inputs(MlxData _mlxData) : mlxData(_mlxData) {
//    this->events_ptr = &ft_events;
//    this->destroy_ptr = &ft_destroy;
    mlx_hook(this->mlxData.getWindow(), 17, 0, (int (*)())(&ft_destroy), reinterpret_cast<void *>(this));
    mlx_hook(this->mlxData.getWindow(), 2, 0, (int (*)())(&ft_events), reinterpret_cast<void *>(getMlxData()));
}


/* ******************************* */
/*            Accessors            */
/* ******************************* */
eInputs Inputs::getCurrent_input() const {
    return current_input;
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
        case ONE_KEY:
            this->current_input = eInputs::lib1;
        case TWO_KEY:
            this->current_input = eInputs::lib2;
        case THREE_KEY:
            this->current_input = eInputs::lib3;
        case SPACE_KEY:
            this->current_input = eInputs::pause;
        case LEFT_KEY:
            this->current_input = eInputs::left;
        case RIGHT_KEY:
            this->current_input = eInputs::right;
        case UP_KEY:
            this->current_input = eInputs::up;
        case DOWN_KEY:
            this->current_input = eInputs::down;
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

