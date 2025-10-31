#ifdef __OpenBSD__
#include <optional>
#include <string>
#include <string_view>

#include <sys/sysctl.h>
#include <stdlib.h>

#include "platform.hpp"

static constexpr auto get_sysctl_by_name(const std::string_view name) -> std::optional<std::string> { 
	auto len = 0;
	if (sysctlbyname(name.data(), nullptr, &len, nullptr, 0) < 0) {
		return std::nullopt;
	}
	char* buffer = new char[len];
	if (sysctlbyname(name.data(), buffer, &len, nullptr, 0) < 0 {
		return std::nullopt;
	}
	return std::make_optional(std::string { buffer });
}

constexpr auto platform_get_cpu_name() -> std::optional<std::string> {
	return get_sysctl_by_name("hw.model");
}

#endif
