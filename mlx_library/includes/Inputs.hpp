
#ifndef INPUTS_HPP
# define INPUTS_HPP

# include <iostream>
# include <mlx.h>
#include "MlxData.hpp"
#include "../../project/includes/eInputs.hpp"

class Inputs {
public:
    Inputs(void) = default;
    Inputs(MlxData _mlxData);
    Inputs(Inputs const &src) = default;
    virtual ~Inputs(void);
    Inputs &operator=(Inputs const &rhs) = default;

    eInputs getCurrent_input() const;

    typedef int (Inputs::*mlx_key_hook_fct)(int keycode, void *param);
    typedef int (Inputs::*mlx_hook_fct)(void *param);
    typedef int (*mlx_fct)();
private:
    int     ft_events(int keycode, void *param);


    MlxData             mlxData;
    mlx_hook_fct        destroy_ptr;
    mlx_fct    events_ptr;
    eInputs             current_input;
};


#endif