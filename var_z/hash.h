#pragma once
//Someday I hope to give who ever wrote this public domain code the credit they desurve. However so far my search has proved to find no results.
constexpr uint32_t UIRN(char const *s, unsigned int count) {
	return count ? (UIRN(s, count - 1) ^ s[count - 1]) * 16777619u : 2166136261u;
}
#define COREFC(X) UIRN(X, strlen(X))
