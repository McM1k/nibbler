#include "catch.hpp"
#include "../project/includes/LibLoader.hpp"
#include "../project/includes/IInputs.hpp"

typedef IInputs *(*NewInputsFunction)();

TEST_CASE("LibLoader fails with unexisting lib") {
    REQUIRE_THROWS_AS(LibLoader(static_cast<eSharedLibs>(3)), LibLoader::DLExceptions);
}

TEST_CASE("LibLoader works with existing lib") {
    REQUIRE_NOTHROW(LibLoader(eSharedLibs::ncursesLib));
}

TEST_CASE("LibLoader fails when creating non existing function pointer") {
    LibLoader libLoader(eSharedLibs::ncursesLib);

    REQUIRE_THROWS_AS(libLoader.loadFunction<NewInputsFunction>("test"), LibLoader::DLExceptions);
}

TEST_CASE("LibLoader works when creating an existing function pointer") {
    LibLoader libLoader(eSharedLibs::ncursesLib);

    REQUIRE_NOTHROW(libLoader.loadFunction<NewInputsFunction>("newInputs"));
}

TEST_CASE("LibLoader works when creating an object from a function pointer") {
    LibLoader libLoader(eSharedLibs::ncursesLib);

    auto newInputsFunction = libLoader.loadFunction<NewInputsFunction>("newInputs");
    IInputs *inputs = newInputsFunction();

    REQUIRE_FALSE(!inputs);
}

TEST_CASE("LibLoader works when creating an object from a function pointer but with wrong type") {
    LibLoader libLoader(eSharedLibs::ncursesLib);

    auto newInputsFunction = libLoader.loadFunction<IInputs *(*)(std::string)>("newInputs");
    IInputs *inputs = newInputsFunction("mdr");

    REQUIRE_FALSE(!inputs);
}
