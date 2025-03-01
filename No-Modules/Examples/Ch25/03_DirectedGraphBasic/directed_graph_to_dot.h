#pragma once

#include "directed_graph.h"
#include <print>
#include <sstream>
#include <string>
#include <string_view>
#include <utility>

namespace ProCpp
{

// Returns a given graph in DOT format.
template <typename T> std::string to_dot(const directed_graph<T> &graph, std::string_view graph_name)
{
    std::ostringstream output;

    std::println(output, "digraph {} {{", graph_name);
    for (std::size_t index{0}; index < graph.size(); ++index)
    {
        const auto &node_value{graph[index]};
        const auto  adjacent_values{graph.get_adjacent_nodes_values(node_value)};
        if (adjacent_values.empty())
        {
            std::println(output, "{}", node_value);
        }
        else
        {
            for (auto &&neighbor : adjacent_values)
            {
                std::println(output, "{} -> {}", node_value, neighbor);
            }
        }
    }
    std::println(output, "}}");

    return std::move(output).str();
}

} // namespace ProCpp
