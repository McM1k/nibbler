/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eInputs.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 15:49:27 by gboudrie          #+#    #+#             */
/*   Updated: 2019/01/18 15:49:27 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef EINPUTS_HPP
# define EINPUTS_HPP

typedef enum {
    quit,
    lib1,
    lib2,
    lib3,
    pause,
    left,
    right,
    up,
    down,
    noInput
} eInputs;

inline std::ostream &operator<<(std::ostream &o, eInputs const &i) {
    switch (i) {
        case eInputs::quit :
            o << "quit input" << std::endl;
            break;
        case eInputs::lib1 :
            o << "lib1 input" << std::endl;
            break;
        case eInputs::lib2 :
            o << "lib2 input" << std::endl;
            break;
        case eInputs::lib3 :
            o << "lib3 input" << std::endl;
            break;
        case eInputs::pause :
            o << "pause input" << std::endl;
            break;
        case eInputs::left :
            o << "left input" << std::endl;
            break;
        case eInputs::right :
            o << "right input" << std::endl;
            break;
        case eInputs::up :
            o << "up input" << std::endl;
            break;
        case eInputs::down :
            o << "down input" << std::endl;
            break;
        case eInputs::noInput :
            o << "no input" << std::endl;
            break;
    }
    return o;
}

#endif