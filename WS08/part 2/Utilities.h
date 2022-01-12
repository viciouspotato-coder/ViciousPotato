// Workshop 8 - Smart Pointers
// 11/21/2021 - Henry Tao

#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H

#include "List.h"
#include "Element.h"

namespace sdds {
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price);
	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price);
}

#endif