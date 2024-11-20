cmake_minimum_required(VERSION 3.31)

# Nom du projet
project(game-of-life)

# Définir la norme C++ (ex. C++23)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Chercher SDL2 via pkg-config ou chemin manuel
find_package(PkgConfig REQUIRED)
pkg_check_modules(SDL2 REQUIRED sdl2)

# Ajouter les chemins d'inclusion et de bibliothèques de SDL2
include_directories(${SDL2_INCLUDE_DIRS})
link_directories(${SDL2_LIBRARY_DIRS})

# Ajouter les fichiers sources
add_executable(game-of-life 
    src/main.cpp
    src/rules.cpp  # Ajoute rules.cpp ici
)

# Inclure les répertoires d'en-têtes
target_include_directories(game-of-life PUBLIC ${CMAKE_SOURCE_DIR}/includes)

# Lier SDL2 au projet
target_link_libraries(game-of-life ${SDL2_LIBRARIES})