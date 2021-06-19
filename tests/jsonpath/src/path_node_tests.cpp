﻿// Copyright 2021 Daniel Parker
// Distributed under Boost license

#if defined(_MSC_VER)
#include "windows.h" // test no inadvertant macro expansions
#endif
#include <jsoncons_ext/jsonpath/path_node.hpp>
#include <catch/catch.hpp>
#include <iostream>

using path_node = jsoncons::jsonpath::detail::path_node<char>;

TEST_CASE("test path_node equals")
{
    path_node node1("$");
    path_node node2(&node1,"foo");
    path_node node3(&node2,"bar");
    path_node node4(&node3,0);

    path_node node11("$");
    path_node node12(&node11,"foo");
    path_node node13(&node12,"bar");
    path_node node14(&node13,0);

    CHECK(node4 == node14);
    CHECK(node3 == node13);
    CHECK(node2 == node12);
    CHECK(node1 == node11);

    CHECK_FALSE(node4 == node13);
    CHECK_FALSE(node3 == node12);
    CHECK_FALSE(node2 == node11);
}

TEST_CASE("test path_node to_string")
{
    path_node node1("$");
    path_node node2(&node1,"foo");
    path_node node3(&node2,"bar");
    path_node node4(&node3,0);

    CHECK(node4.to_string() == std::string("$['foo']['bar'][0]"));
}


