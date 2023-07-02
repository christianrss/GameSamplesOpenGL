# CMakeList.txt: projeto de CMake para Sample2, incluir origem e definir
# lógica específica a um projeto aqui.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("Sample2")

# Adicione a origem ao executável deste projeto.
add_executable (Sample2 "Sample2.cpp" "Sample2.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Sample2 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Adicione testes e instale destinos, se necessário.
target_include_directories(
	Sample2
		PRIVATE 
			deps/glm
  			deps/stb
			deps/glfw/include
			deps/glew/include
)

target_link_directories(
	Sample2
		PRIVATE
			deps/glfw/lib-vc2022
			deps/glew/lib/Release/x64
)

target_link_libraries(
	Sample2
		PRIVATE
			glfw3.lib
			glew32.lib
			opengl32.lib
			glu32.lib
)