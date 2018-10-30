cmake_minimum_required(VERSION 3.12)
project(ConsSW)

set(CMAKE_CXX_STANDARD 14)

add_executable(ConsSW main.cpp shapes/Shape.cpp shapes/Shape.h shapes/Circle.cpp shapes/Circle.h shapes/RegularPolygon.cpp shapes/RegularPolygon.h shapes/Text.cpp shapes/Text.h shapes/ShadowedRegularPolygon.cpp shapes/ShadowedRegularPolygon.h shapes/TextInShape.cpp shapes/TextInShape.h container/BinaryTree.cpp container/BinaryTree.h container/BinaryTreeIterator.cpp container/BinaryTreeIterator.h exceptions/OutOfRangeException.cpp exceptions/OutOfRangeException.h)