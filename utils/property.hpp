/**
 * @file property.h
 * @author Charliechen114514 (chengh1922@mails.jlu.edu.cn)
 * @brief property settings with getter/setter
 * @version 0.1
 * @date 2025-11-08
 *
 * @copyright Copyright (c) 2025
 *
 */
#pragma once
#include <functional>

namespace plan_parser {
namespace utils {
	template <typename property_t>
	struct property {
	public:
		using setter_func_t = std::function<bool(const property_t&)>;
		using getter_func_t = std::function<property_t(void)>;

		property() {
			setter_ = [this](const property_t& v) -> bool {
				value = v;
				return true;
			};
			getter_ = [this]() -> property_t {
				return value;
			};
		};
		property(setter_func_t sf, getter_func_t gf)
		    : setter_(std::move(sf))
		    , getter_(std::move(gf)) { }

		explicit property(const property_t& initial_value)
		    : property() {
			value = initial_value;
		}

		explicit property(property_t&& initial_value)
		    : property() {
			value = std::move(initial_value);
		}

		bool set(const property_t& v) {
			if (setter_) // if we owns a possible setter, then do
				return setter_(v);
			return false;
		}

		property_t get() const {
			if (getter_)
				return getter_();
			return value; // fallback
		}

		const property_t& operator=(const property_t& v) {
			set(v);
			return v;
		}

		const property_t& get_ref() const noexcept { return value; }
		explicit operator property_t&() noexcept { return value; }
		explicit operator const property_t&() const noexcept { return value; }

	private:
		// for safety reason, disable all the property as
		// it binds to the target objects
		property(const property&) = delete;
		property& operator=(const property&) = delete;
		property(property&&) = delete;
		property& operator=(property&&) = delete;

	private:
		property_t value {};

		// allow view as const
		mutable setter_func_t setter_;
		mutable getter_func_t getter_;
	};

}
}