//#include "pch.h"
#include "filter.h"
#include <string.h>

using namespace libfilter;

Filter::Filter( const Platform::Array<float>^ impulseResponse ) {
	// Initialize everything here
}

Filter::~Filter() {
	// Clean everything up here
}

float Filter::filter( float data ) {
	// Filter a single sample
	// Return the output sample
}

Platform::Array<float>^ Filter::filter( const Platform::Array<float>^ data ) {
	// Filter each sample in the input array `data`
	// Return the array of output
}
