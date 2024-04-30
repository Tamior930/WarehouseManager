add_rules("mode.debug", "mode.release")

add_requires("raylib")

target("raylib-scaffold")
    set_kind("binary")
    add_files("src/*.cpp")
    add_packages("raylib")
    set_languages("c++11")
