
#ifndef MLX_INPUTS_HPP
# define MLX_INPUTS_HPP

# include <iostream>
# include <mlx.h>
#include "MlxData.hpp"
#include "../../project/includes/eInputs.hpp"


#define ESC_KEY 53
#define ONE_KEY 18
#define TWO_KEY 19
#define THREE_KEY 20
#define SPACE_KEY 49
#define LEFT_KEY 123
#define RIGHT_KEY 124
#define UP_KEY 126
#define DOWN_KEY 125

int     ft_events(int keycode, void *param);
int     ft_destroy(void *param);

class Inputs {
public:
    Inputs(void) = default;
    Inputs(MlxData _mlxData);
    Inputs(Inputs const &src) = default;
    virtual ~Inputs(void);
    Inputs &operator=(Inputs const &rhs) = default;

    eInputs getCurrent_input() const;
    MlxData *getMlxData();

    void    stockInput(int input);

private:



    MlxData     mlxData;
    int        (*destroy_ptr)(void *param);
    int        (*events_ptr)(int keycode, void *param);
    eInputs     current_input;
};


#endif