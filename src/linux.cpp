// SPDX-License-Identifier: Apache-2.0

#include <algorithm>
#include <cctype>
#include <optional>
#include <ranges>
#include <string>
#include <string_view>

#include "platform.hpp"

namespace stdr = std::ranges;
namespace stdv = std::views;

static constexpr auto parse_cpuinfo(const std::string_view cpuinfo) -> std::optional<std::string> {
	auto lines = cpuinfo | stdv::split('\n') | stdv::transform([](auto&& line) { return std::string_view { line }; });
	auto iter = stdr::find_if(lines, [](auto&& line) { return line.starts_with("model name"); });
	if (iter == stdr::end(lines)) {
		return std::nullopt;
	}
	return *iter | stdv::split(':') | stdv::drop(1) | stdv::join |
		   stdv::drop_while([](auto element) { return std::isspace(element); }) | stdr::to<std::string>();
}

auto platform_get_cpu_name() -> std::optional<std::string> { return parse_cpuinfo(read_to_string("/proc/cpuinfo")); }
