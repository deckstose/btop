// SPDX-License-Identifier: Apache-2.0

#pragma once

#include <cstddef>
#include <fstream>
#include <optional>
#include <string>
#include <thread>

#include <unistd.h>

struct SystemInfo {
	std::size_t core_count;
	std::size_t page_size;
	std::size_t clock_ticks;
	std::string cpu_name;
};

constexpr auto read_to_string(auto&& path) -> std::string {
	std::ifstream file { path };
	return std::string { std::istreambuf_iterator<char> { file }, {} };
}

constexpr auto get_core_count() -> std::size_t {
	auto core_count = std::thread::hardware_concurrency();
	return static_cast<std::size_t>(core_count);
}

constexpr auto get_page_size() -> std::size_t {
	auto page_size = getpagesize();
	return static_cast<std::size_t>(page_size);
}

constexpr auto get_clock_ticks() -> std::size_t {
	auto clock_ticks = sysconf(_SC_CLK_TCK);
	return static_cast<std::size_t>(clock_ticks);
}

auto platform_get_cpu_name() -> std::optional<std::string>;

constexpr auto get_cpu_name() -> std::string { return platform_get_cpu_name().value_or(""); }

namespace Cpu {
	auto platform_collect();
}

namespace Mem {
	auto platform_collect();
}

namespace Net {
	auto platform_collect();
}

namespace Proc {
	auto platform_collect();
}
