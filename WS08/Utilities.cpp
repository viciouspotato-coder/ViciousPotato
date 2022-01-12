// Workshop 8 - Smart Pointers
// 11/21/2021 - Henry Tao

#include "Element.h"
#include "List.h"
#include "Utilities.h"
#include <memory>

using namespace std;

namespace sdds {
List<Product>
mergeRaw(const List<Description> &desc, const List<Price> &price) {
	List<Product> priceList;
	// TODO: Add your code here to build a list of products
	//         using raw pointers
	for (size_t indexD = 0; indexD < desc.size(); indexD++) {
		for (size_t indexP = 0; indexP < price.size(); ++indexP) {
			if (desc[indexD].code == price[indexP].code) {
				Product *newProduct =
					new Product(desc[indexD].desc, price[indexP].price);
				newProduct->validate();
				priceList += newProduct;
				delete newProduct;
			}
		}
	}
	return priceList;
}

List<Product>
mergeSmart(const List<Description> &desc, const List<Price> &price) {
	List<Product> priceList;
	// TODO: Add your code here to build a list of products
	//         using smart pointers
	for (size_t indexD = 0; indexD < desc.size(); indexD++) {
		for (size_t indexP = 0; indexP < price.size(); ++indexP) {
			if (desc[indexD].code == price[indexP].code) {
				std::unique_ptr<Product> newProduct(
					new Product(desc[indexD].desc, price[indexP].price));
				newProduct->validate();
				priceList += newProduct;
			}
		}
	}
	return priceList;
}
} // namespace sdds