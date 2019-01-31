
#include "../includes/Inputs.hpp"

/* ******************************* */
/*    Constructors & destructor    */
/* ******************************* */
Inputs::Inputs(MlxData _mlxData) : mlxData(_mlxData) {
    this->events_ptr = (int (*)())&Inputs::ft_events;
    this->destroy_ptr = &Inputs::ft_destroy;
    mlx_hook(this->mlxData.getWindow(), 17, 0, this->destroy_ptr, &(this->mlxData));
    mlx_hook(this->mlxData.getWindow(), 2, 0, this->events_ptr, &(this->mlxData));
}


/* ******************************* */
/*            Accessors            */
/* ******************************* */
eInputs Inputs::getCurrent_input() const {
    return current_input;
}
/* ******************************* */
/*       operators  overload       */
/* ******************************* */

/* ******************************* */
/*            Functions            */
/* ******************************* */
int Inputs::ft_events(int keycode, void *param) {

}
/* ******************************* */
/*            Exceptions           */
/* ******************************* */

