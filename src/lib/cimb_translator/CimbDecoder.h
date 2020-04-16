#pragma once

#include <opencv2/opencv.hpp>
#include <cstdint>
#include <string>

class CimbDecoder
{
public:
	CimbDecoder(unsigned symbol_bits, unsigned color_bits);

	unsigned decode(const cv::Mat& cell);

	unsigned get_best_symbol(uint64_t hash);
	unsigned decode_symbol(const cv::Mat& cell);

	int get_best_color(unsigned char r, unsigned char g, unsigned char b) const;
	unsigned decode_color(const cv::Mat& cell);

protected:
	uint64_t get_tile_hash(std::string tile_dir, unsigned symbol);
	bool load_tiles(std::string tile_dir);

	unsigned check_color_distance(cv::Vec3b c, unsigned char r, unsigned char g, unsigned char b) const;
	unsigned char fix_color(unsigned char c, float adjust) const;

protected:
	std::vector<uint64_t> _tileHashes;
	unsigned _symbolBits;
	unsigned _numSymbols;
	unsigned _numColors;
	unsigned _colorThreshold;
	bool _dark;
	cv::Vec3b _backgroundColor;
};